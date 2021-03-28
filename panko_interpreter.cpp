//
// Created by jack on 2/19/21.
//

#include "panko_interpreter.h"

#include <utility>

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

ComplexValue &ComplexValue::operator=(ComplexValue&& other) {
    *this = other;
    return *this;
}

std::ostream& panko::runtime::operator<<(std::ostream& os, const Value& val) {
    static int tab_depth = 0;

    util::visit(val,
        [&os](const ComplexValue& val) {
            os << "Object: {";
            tab_depth++;
            for (const auto &kv : val.attributes) {
                os << '\n' << std::string(tab_depth * 2, ' ') << '"' << (std::string)kv.first << "\" = " << kv.second;
            }
            tab_depth--;
            os << '\n' << std::string(tab_depth * 2, ' ') << '}';
        },
        [&os](int val){ os << "Int: " << val; },
        [&os](double val){ os << "Double: " << val; },
        [&os](bool val){ os << "Bool: " << val; },
        [&os](const Reference& val){ os << "Reference to " << *val.getValue(); },
        [&os](const Superset& val){ os << "Superset with value: " << val.getValue(); },
        [&os](const auto& array) {
            tab_depth++;
            if constexpr (std::is_same_v<std::remove_cvref_t<decltype(array)>, Array>) {
                os << "Array: ";
            } else {
                os << "Tuple: ";
            }
            os << "[\n" << std::string(tab_depth * 2, ' ');
            bool first = true;
            for (const auto& val : array.values) {
                if (first) {
                    first = false;
                } else {
                    os << ",\n" << std::string(tab_depth * 2, ' ');
                }
                os << val;
            }
            tab_depth--;
            os << '\n' << std::string(tab_depth * 2, ' ') << ']';
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

const Value& Interpreter::decay(const Value& value) {
    return *util::visit(value,
        [](const Reference& ref){return &decay(*ref.getValue());},
        [](const Superset& sup){return &(sup.getValue());},
        [&](const auto&){return &value;}
    );
}

Value& Interpreter::getReferenceValue(const Value& ref) {
    try {
        return *util::get<Reference>(ref).getValue();
    } catch (std::bad_variant_access&) {
        throw BadTypeConversion{"Value is not a reference"};
    }
}

std::tuple<size_t, const ast::Variable*> Interpreter::findVariableAndHash(const ast::Identifier& id) const {
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

const ast::Variable* Interpreter::findVariable(const ast::Identifier& id) const {
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

const ast::Type* Interpreter::findType(const ast::Identifier& id) const {
    if (auto type = std::get<const ast::Type*>(id.context.lookup(id.identifier, ast.types))) {
        return type;
    } else {
        return nullptr;
    }
}

const ast::Function* Interpreter::findFunction(const ast::Identifier& id) const {
    if (auto func = std::get<const ast::Function*>(id.context.lookup(id.identifier, ast.functions))) {
        return func;
    } else {
        return nullptr;
    }
}

Value Interpreter::constructValue(const ast::TypeIdentifier* type) const {
    if (!type) return Value{};
    switch (type->op) {
        case ast::TypeOperator::BASIC: {
            const auto actual = findType(type->id);
            if (actual->name == util::string_hash{"int"}) {
                return Value{std::in_place_type<int>};
            } else if (actual->name == util::string_hash{"float"}) {
                return Value{std::in_place_type<double>};
            } else if (actual->name == util::string_hash{"bool"}) {
                return Value{std::in_place_type<bool>};
            } else {
                ComplexValue val{};
                for (const auto &attr : actual->attributes) {
                    val.attributes.emplace(attr.name, constructValue(attr.type.get()));
                }
                return val;
            }
        } case ast::TypeOperator::SUBSET:
            break;
        case ast::TypeOperator::SUPERSET:
            return Superset{util::get<ComplexValue>(constructValue(type->other_types.at(0).get()))};
        case ast::TypeOperator::REFERENCE:
            return Reference{type->other_types.at(0).get(), nullptr};
        case ast::TypeOperator::CONJUNCTION:
            break;
        case ast::TypeOperator::DISJUNCTION:
            break;
        case ast::TypeOperator::TUPLE: {
            Tuple ret_val{this};
            for (const auto& subtype : type->other_types) {
                ret_val.values.push_back(constructValue(subtype.get()));
                ret_val.types.push_back(subtype.get());
            }

            return ret_val;
        } case ast::TypeOperator::ARRAY:
            return Array{type->other_types.at(0).get(), this};
    }

    return Value{};
}

Reference Interpreter::makeReference(const ast::Identifier& id) {
    return Reference{findVariable(id)->type.get(), &findValue(id)};
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
            decay(visit(expression->lhs.get())).getVariant(),
            decay(visit(expression->rhs.get())).getVariant()
    );
}

Value Interpreter::visitUnaryOperatorExpression(ast::UnaryOperatorExpression* expression) {
    return util::visit(decay(visit(expression->lhs.get())),
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
        values.emplace(var_decl->variable, constructValue(var->type.get()));
    } else {
        std::cerr << "VARIABLE NOT FOUND!";
        std::terminate();
    }

    if (auto assignment = var_decl->assignment.get()) {
        values.at(var_decl->variable) = convert(visit(assignment), var->type.get());
    }

    return values.at(var_decl->variable);
}

Value Interpreter::visitVariableExpression(ast::VariableExpression *identifier) {
    return makeReference(identifier->variable);
}

Value Interpreter::visitComplexAssignment(ast::ComplexAssignment *assignment) {
    auto& var = getReferenceValue(visit(assignment->reference.get()));
    var = util::visit(
        var,
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
    auto ref = visit(assignment->reference.get());
    auto& var = getReferenceValue(ref);
    var = convert(visit(assignment->expression.get()), util::get<Reference>(ref).type);
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
        if (util::get<bool>(decay(visit(block.condition.get())))) {
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
    while (util::get<bool>(decay(visit(loop->condition.get())))) {
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
        ret_val = constructValue(func->return_type.get());
    }

    std::vector<size_t> param_hashes;
    param_hashes.reserve(func->parameters.size());

    for (size_t i = 0; i < func->parameters.size(); i++) {
        const auto& cur = func->parameters.at(i);
        values.emplace(
            param_hashes.emplace_back(params.make(
                // Have to use call_stack_size + 1 so visiting parameter expressions still work
                util::string_hash{static_cast<std::string>(cur.name) + std::to_string(call_stack_size + 1)},
                std::make_unique<ast::TypeIdentifier>(cur.type->clone())
            )),
            convert(visit(call->arguments.at(i).get()), func->parameters.at(i).type.get())
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
    Reference ret_val = util::get<Reference>(visit(access->reference.get()));
    ret_val.type = nullptr; // I don't like it either

    for (const auto& accessor : access->accessors) {
        ret_val.setValue(&util::get<ComplexValue>(*ret_val.getValue()).attributes.at(accessor));
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

Value Interpreter::visitArrayExpression(ast::ArrayExpression *array) {
    Tuple ret_val{this};

    for (const auto& member : array->members) {
        ret_val.values.push_back(visit(member.get()));
    }

    return ret_val;
}

Value Interpreter::convert(const Value& other, const ast::TypeIdentifier *type) const {
    Value ret_val;
    if (type && type->op == ast::TypeOperator::SUPERSET) {
        return Superset{util::get<ComplexValue>(decay(other))};
    } else if (type && type->op == ast::TypeOperator::SUBSET) {
        return Value{};
    } else {
        ret_val = constructValue(type);
    }

    if (ret_val.getIndex() == other.getIndex()) return other;

    if (std::holds_alternative<Reference>(ret_val.getVariant())) {
        ret_val = other;
    } else if (std::holds_alternative<Array>(ret_val.getVariant()) && std::holds_alternative<Tuple>(other.getVariant())) {
        Array ret_array{nullptr, this};
        for (const auto& value : util::get<Tuple>(other).values) {
            ret_array.values.emplace_back(value);
        }
        ret_val = ret_array;
    } else {
        ret_val = decay(other);
    }
    return ret_val;
}

Value Interpreter::visitNullLiteral(ast::NullLiteral*) {
    return Null{};
}

Value Interpreter::visitArrayAccessExpression(ast::ArrayAccessExpression *access) {
    return util::visit(getReferenceValue(visit(access->reference.get())),
        [access](Array& array){ return Reference{array.type, &array.values.at(access->index)}; },
        [access](Tuple& tuple){ return Reference{tuple.types.at(access->index), &tuple.values.at(access->index)}; },
        [](auto& other){ std::cout << other << '\n'; throw BadOperatorCall{"Can't use non-array type as array"}; return Reference{};}
    );
}

Array &Array::operator=(const Array &other) { // Have to reimplement Interpreter::convert bc of pesky constructValue
    if (&other == this) return *this;
    values.clear();

    for (const auto& value : other.values) {
        values.emplace_back(other.interpreter->convert(value, type));
    }

    interpreter = other.interpreter;
    return *this;
}

Tuple &Tuple::operator=(const Tuple &other) {
    if (&other == this) return *this;
    if (values.size() != other.values.size()) {
        throw BadTypeConversion{"Tuple sizes not equal"};
    }

    for (size_t i = 0; i < values.size(); i++) { // First standard for loop in forever
        values.at(i) = other.interpreter->convert(other.values.at(i), types.at(i));
    }

    interpreter = other.interpreter;
    return *this;
}

void Reference::setValue(Value* val) {
    if (val && std::holds_alternative<Reference>(val->getVariant())) {
        value = util::get<Reference>(*val).value;
        type = util::get<Reference>(*val).type;
    } else {
        value = val;
    }
}

Value* Reference::getValue() const {
    return value;
}

Reference::Reference(const ast::TypeIdentifier *type, Value *value) : type{type} {
    setValue(value);
}

void Superset::setValue(const ComplexValue& new_value) {
    if (!util::typeSubset(test_value.attributes, new_value.attributes)) {
        throw BadTypeConversion{"New value doesn't contain all aspects of subtype"};
    }

    ComplexValue& cv = util::get<ComplexValue>(*value);

    cv.attributes = test_value.attributes;
    for (const auto& kv : new_value.attributes) {
        auto iter = cv.attributes.find(kv.first);
        if (iter == cv.attributes.end()) {
            cv.attributes.emplace(kv);
        } else {
            cv.attributes.at(kv.first) = kv.second;
        }
    }
}

const Value& Superset::getValue() const {
    return *value;
}

Superset &Superset::operator=(const Superset &other) {
    if (&other == this) return *this;
    setValue(util::get<ComplexValue>(*other.value));
    return *this;
}

Superset &Superset::operator=(Superset&& other) {
    *this = other;
    return *this;
}
