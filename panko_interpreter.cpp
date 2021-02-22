//
// Created by jack on 2/19/21.
//

#include "panko_interpreter.h"

using namespace panko::runtime;
using namespace panko;

ComplexValue& ComplexValue::operator=(const ComplexValue &other) {
    if (!util::typeEqual(attributes, other.attributes)){
        throw BadTypeConversion{"ComplexValue types don't match"};
    }

    for (auto &kv : attributes) {
        kv.second = other.attributes.at(kv.first);
    }

    return *this;
}

std::ostream& panko::runtime::operator<<(std::ostream& os, const Value& val) {
    static int tab_depth = 0;

    util::visit(val.getVariant(),
        [&os](const ComplexValue& val) {
            os << "Type:";
            tab_depth++;
            for (const auto &kv : val.attributes) {
                os << '\n' << std::string(tab_depth * 2, ' ') << '"' << (std::string)kv.first << "\" = " << kv.second;
            }
            tab_depth--;
        },
        [&os](int val){ os << "Int: " << val; },
        [&os](double val){ os << "Double: " << val; },
        [&os](bool val){ os << "Bool: " << val; },
        [&os](Reference val){ os << "Reference to " << *val.value; },
        [&os](const Array& array) {
            os << "Array: [";
            bool first = true;
            for (const auto& val : array.values) {
                if (first) {
                    first = false;
                } else {
                    os << ',';
                }
                os << val;
            }
            os << ']';
        },
        [&os](Null){ os << "Null"; },
        [&os](Returning){ os << "Returning"; }
    );
    return os;
}

void Interpreter::run() {
    std::cout << std::boolalpha;
    for (auto& file : ast.files) {
        visitFile(file.get());
    }
}

const Value& Interpreter::removeReference(const Value& value) {
    if (std::holds_alternative<Reference>(value.getVariant())) {
        return *std::get<Reference>(value.getVariant()).value;
    } else {
        return value;
    }
}

Value& Interpreter::getReferenceValue(const Value& ref) {
    try {
        return *util::get<Reference>(ref).value;
    } catch (std::bad_variant_access&) {
        throw BadTypeConversion{"Value is not a reference"};
    }
}

std::tuple<size_t, const ast::Variable*> Interpreter::findVariableAndHash(const ast::Identifier& id) {
    auto var = id.context.lookup(id.identifier, ast.variables);

    if (std::get<const ast::Variable*>(var)) {
        return var;
    } else {
        size_t hash = std::hash<ast::Variable>{}(ast::Variable{id.identifier + std::to_string(call_stack_size)});
        const auto ptr = params.get(hash);
        if (ptr) {
            return {hash, ptr};
        } else {
            return {0, nullptr};
        }
    }
}

const ast::Variable* Interpreter::findVariable(const ast::Identifier& id) {
    return std::get<const ast::Variable*>(findVariableAndHash(id));
}

Value& Interpreter::findValue(const ast::Identifier& id) {
    auto [hash, ptr] = findVariableAndHash(id);
    if (ptr) {
        return values.at(hash);
    } else {
        throw util::Exception("Value not found for identifier " + id.context.mangle(id.identifier));
    }
}

const ast::Type* Interpreter::findType(const ast::Identifier& id) {
    if (auto type = std::get<const ast::Type*>(id.context.lookup(id.identifier, ast.types))) {
        return type;
    } else {
        return nullptr;
    }
}

const ast::Function* Interpreter::findFunction(const ast::Identifier& id) {
    if (auto func = std::get<const ast::Function*>(id.context.lookup(id.identifier, ast.functions))) {
        return func;
    } else {
        return nullptr;
    }
}

Value Interpreter::constructValue(const ast::Type& type) {
    if (type.name == util::string_hash{"int"}) {
        return Value{std::in_place_type<int>};
    } else if (type.name == util::string_hash{"float"}) {
        return Value{std::in_place_type<double>};
    } else if (type.name == util::string_hash{"bool"}) {
        return Value{std::in_place_type<bool>};
    } else {
        ComplexValue val{};

        for (const auto& attr : type.attributes) {
            val.attributes.emplace(attr.name, constructValue(*findType(attr.type)));
        }

        return val;
    }
}

Reference Interpreter::makeReference(const ast::Identifier& id) {
    return Reference{&findValue(id)};
}

Value Interpreter::visitFile(ast::File *file) {
    for (auto& statement : file->statements) {
        std::cout << visit(statement.get()) << '\n';
    }

    return std::monostate{};
}

Value Interpreter::visitBinaryOperatorExpression(ast::BinaryOperatorExpression *expression) {
    auto int_float_lambda = [expression](util::Number auto lhs, util::Number auto rhs) {
        switch (expression->op) {
            case ast::BinaryOperator::OR:
                return Value{lhs || rhs};
            case ast::BinaryOperator::AND:
                return Value{lhs && rhs};
            case ast::BinaryOperator::EQ:
                return Value{lhs == rhs};
            case ast::BinaryOperator::NEQ:
                return Value{lhs != rhs};
            case ast::BinaryOperator::GT:
                return Value{lhs > rhs};
            case ast::BinaryOperator::LT:
                return Value{lhs < rhs};
            case ast::BinaryOperator::GTEQ:
                return Value{lhs >= rhs};
            case ast::BinaryOperator::LTEQ:
                return Value{lhs <= rhs};
            case ast::BinaryOperator::ADD:
                return Value{lhs + rhs};
            case ast::BinaryOperator::SUB:
                return Value{lhs - rhs};
            case ast::BinaryOperator::MUL:
                return Value{lhs * rhs};
            case ast::BinaryOperator::DIV:
                return Value{lhs / rhs};
            default:
                return Value{std::monostate{}};
        }
    };

    return std::visit(
        util::visitor{
            [expression, int_float_lambda](int lhs, int rhs) {
                switch (expression->op) {
                    case ast::BinaryOperator::MOD:
                        return Value{lhs % rhs};
                    case ast::BinaryOperator::BITAND:
                        return Value{lhs & rhs};
                    case ast::BinaryOperator::BITOR:
                        return Value{lhs | rhs};
                    case ast::BinaryOperator::XOR:
                        return Value{lhs ^ rhs};
                    default:
                        return int_float_lambda(lhs, rhs);
                }
            },
            [expression](bool lhs, bool rhs) {
                switch (expression->op) {
                    case ast::BinaryOperator::AND:
                        return Value{lhs && rhs};
                    case ast::BinaryOperator::OR:
                        return Value{lhs || rhs};
                    case ast::BinaryOperator::EQ:
                        return Value{lhs == rhs};
                    case ast::BinaryOperator::NEQ:
                        return Value{lhs != rhs};
                    default:
                        return Value{std::monostate{}};
                }
            },
            int_float_lambda,
            [](auto&&, auto&&){throw BadOperatorCall{"Failed to find operator overload"}; return Value{};}
        },
        removeReference(visit(expression->lhs.get())).getVariant(),
        removeReference(visit(expression->rhs.get())).getVariant()
    );
}

Value Interpreter::visitUnaryOperatorExpression(ast::UnaryOperatorExpression* expression) {
    return util::visit(removeReference(visit(expression->lhs.get())).getVariant(),
        [expression](int lhs){
            switch (expression->op) {
                case ast::UnaryOperator::BITNOT:
                    return Value{~lhs};
                case ast::UnaryOperator::NOT:
                    return Value{!lhs};
            }
        },
        [expression](bool lhs){
            switch (expression->op) {
                case ast::UnaryOperator::NOT:
                    return Value{!lhs};
                default:
                    throw BadOperatorCall{"Failed to find operator overload"};
                    return Value{};
            }
        },
        [](auto&&) {
            throw BadOperatorCall{"Failed to find operator overload"};
            return Value{};
        }
    );
}

Value Interpreter::visitIntegerLiteral(ast::IntegerLiteral *literal) {
    return Value{literal->value};
}

Value Interpreter::visitFloatLiteral(ast::FloatLiteral *literal) {
    return Value{literal->value};
}

Value Interpreter::visitBoolLiteral(ast::BoolLiteral* literal) {
    return Value{literal->value};
}

Value Interpreter::visitVariableDeclaration(ast::VariableDeclaration *var_decl) {
    auto var = ast.variables.get(var_decl->variable);
    if (var) {
        auto type = findType(var->type);
        if (type) {
            values.emplace(var_decl->variable, constructValue(*type));
        } else {
            std::cerr << "TYPE NOT FOUND!";
            std::terminate();
        }
    } else {
        std::cerr << "VARIABLE NOT FOUND!";
        std::terminate();
    }

    if (auto assignment = var_decl->assignment.get()) {
        values.at(var_decl->variable) = visit(assignment);
    }

    return values.at(var_decl->variable);
}

Value Interpreter::visitVariableExpression(ast::VariableExpression *identifier) {
    return makeReference(identifier->variable);
}

Value Interpreter::visitComplexAssignment(ast::ComplexAssignment *assignment) {
    auto& var = getReferenceValue(visit(assignment->reference.get()));
    var = util::visit(
        var.getVariant(),
        [assignment](util::Number auto value){
            if (assignment->increment) {
                return Value{value + 1};
            } else {
                return Value{value - 1};
            }
        },
        [](auto){return Value{std::monostate{}};}
    );

    return var;
}

Value Interpreter::visitSimpleAssignment(ast::SimpleAssignment *assignment) {
    auto& var = getReferenceValue(visit(assignment->reference.get()));
    var = removeReference(visit(assignment->expression.get()));
    return var;
}

Value Interpreter::visitBlock(ast::Block *block) {
    for (auto& statement : block->statements) {
        if (std::holds_alternative<Returning>(visit(statement.get()).getVariant())) {
            return Returning{};
        }
    }

    return std::monostate{};
}

Value Interpreter::visitIfStatement(ast::IfStatement* if_stat) {
    for (auto& block : if_stat->if_blocks) {
        if (util::get<bool>(removeReference(visit(block.condition.get())))) {
            if (std::holds_alternative<Returning>(visit(block.block.get()).getVariant())) {
                return Returning{};
            } else {
                return std::monostate{};
            }
        }
    }

    if (if_stat->else_block.get() && std::holds_alternative<Returning>(visit(if_stat->else_block.get()).getVariant())) {
        return Returning{};
    } else {
        return std::monostate{};
    }
}

Value Interpreter::visitWhileLoop(ast::WhileLoop* loop) {
    while (util::get<bool>(removeReference(visit(loop->condition.get())))) {
        if (std::holds_alternative<Returning>(visit(loop->body.get()).getVariant())) {
            return Returning{};
        }
    }

    return std::monostate{};
}

Value Interpreter::visitReturnStatement(ast::ReturnStatement* return_stat) {
    return_value = visit(return_stat->expression.get()).getVariant();
    return Returning{};
}

Value Interpreter::visitFunctionDeclaration(ast::FunctionDeclaration *) {
    return std::monostate{};
}

Value Interpreter::visitFunctionCall(ast::FunctionCall* call) {
    auto func = findFunction(call->function);
    Value ret_val;

    if (func) {
        auto type = findType(func->return_type);

        if (type) {
            ret_val = constructValue(*type);
        }
    }

    std::vector<size_t> param_hashes;
    param_hashes.reserve(func->parameters.size());

    for (size_t i = 0; i < func->parameters.size(); i++) {
        const auto& cur = func->parameters.at(i);
        values.emplace(
            param_hashes.emplace_back(params.make(
                // Have to use call_stack_size + 1 so visiting parameter expressions still work
                util::string_hash{static_cast<std::string>(cur.name) + std::to_string(call_stack_size + 1)},
                std::ref(cur.type)
            )),
            removeReference(visit(call->arguments.at(i).get()))
        );
    }
    call_stack_size++;
    auto dec = util::Finally{[this](){call_stack_size--;}};
    visit(func->body.get());
    ret_val = return_value;

    return_value = std::monostate{};

    for (auto param : param_hashes) {
        values.erase(param);
    }

    return ret_val;
}

Value Interpreter::visitTypeDeclaration(ast::TypeDeclaration*) {
    return std::monostate{};
}

Value Interpreter::visitAccessExpression(ast::AccessExpression* access) {
    auto [hash, var_ptr] = findVariableAndHash(access->initial);
    Reference ret_val = makeReference(access->initial);

    if (var_ptr) {
        for (const auto& accessor : access->accessors) {
            ret_val.value = &util::get<ComplexValue>(*ret_val.value).attributes.at(accessor);
        }
    }

    return ret_val;
}

Value Interpreter::visitObjectExpression(ast::ObjectExpression *object) {
    ComplexValue ret_val;

    for (const auto& member : object->members) {
        ret_val.attributes.emplace(member.first, visit(member.second.get()));
    }

    return ret_val;
}
