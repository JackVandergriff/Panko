//
// Created by jack on 1/24/21.
//

#ifndef PANKO_INTERPRETER_H
#define PANKO_INTERPRETER_H

#include "panko_ast_visitor.h"

#include <iostream>
#include <variant>

namespace panko::runtime {

    struct BadOperatorCall : util::Exception {
        using util::Exception::Exception;
    };

    struct ComplexValue;
    struct ReturnValue;
    struct Reference;

    struct Returning {};

    using Null = std::monostate;
    using Value = util::invariant<int, double, bool, Null, ComplexValue, Returning, Reference>;
    using WeakValue = std::variant<int, double, bool, Null, ComplexValue, Returning, Reference>;

    struct Reference {
        size_t value; // Used to look into interpreter::values
    };

    struct ComplexValue {
        std::map<util::string_hash, Value> attributes;
    };

    std::ostream& operator<<(std::ostream& os, const Value& val) {
        static int tab_depth = 0;

        util::visit(val.getVariant(),
            [&os](const ComplexValue& val) {
                os << "Type:";
                tab_depth++;
                for (const auto &kv : val.attributes) {
                    os << '\n' << std::string(tab_depth, '-') << kv.second;
                }
                tab_depth--;
            },
            [&os](int val){ os << "Int: " << val; },
            [&os](double val){ os << "Double: " << val; },
            [&os](bool val){ os << "Bool: " << val; },
            [&os](Reference val){ os << "Reference to " << val.value; },
            [&os](Null){ os << "Null"; },
            [&os](Returning){ os << "Returning"; }
        );
        return os;
    }

    struct Interpreter : ast::BaseVisitor<Value> {
        const ast::AST& ast;
        util::hasher<ast::Variable> params;
        std::map<size_t, Value> values;
        WeakValue return_value;
        size_t call_stack_size = 0;

        explicit Interpreter(const ast::AST& ast) : ast{ast} {}

        void run() {
            std::cout << std::boolalpha;
            for (auto& file : ast.files) {
                visitFile(file.get());
            }
        }

        Value removeReference(const Value& value) {
            if (std::holds_alternative<Reference>(value.getVariant())) {
                std::cout << "Stripping reference\n";
                return values.at(std::get<Reference>(value.getVariant()).value);
            } else {
                return value;
            }
        }

        std::tuple<size_t, const ast::Variable*> findVariableAndHash(const ast::Identifier& id) {
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

        const ast::Variable* findVariable(const ast::Identifier& id) {
            return std::get<const ast::Variable*>(findVariableAndHash(id));
        }

        Value& findValue(const ast::Identifier& id) {
            auto [hash, ptr] = findVariableAndHash(id);
            if (ptr) {
                return values.at(hash);
            } else {
                throw util::Exception("Value not found for identifier " + id.context.mangle(id.identifier));
            }
        }

        const ast::Type* findType(const ast::Identifier& id) {
            if (auto type = std::get<const ast::Type*>(id.context.lookup(id.identifier, ast.types))) {
                return type;
            } else {
                return nullptr;
            }
        }

        const ast::Function* findFunction(const ast::Identifier& id) {
            if (auto func = std::get<const ast::Function*>(id.context.lookup(id.identifier, ast.functions))) {
                return func;
            } else {
                return nullptr;
            }
        }

        Value constructValue(const ast::Type& type) {
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

        Value makeReference(const ast::Identifier& id) {
            return Reference{std::get<size_t>(findVariableAndHash(id))};
        }

        Value visitFile(ast::File *file) override {
            for (auto& statement : file->statements) {
                std::cout << visit(statement.get()) << '\n';
            }

            return std::monostate{};
        }

        Value visitBinaryOperatorExpression(ast::BinaryOperatorExpression *expression) override {

            auto int_float_lambda = [expression](util::Number auto lhs, util::Number auto rhs){
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

            return std::visit(util::visitor{
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
                [](auto x, auto y){throw BadOperatorCall{"Failed to find operator overload"}; return Value{std::monostate{}};}
            }, removeReference(visit(expression->lhs.get())).getVariant()
            , removeReference(visit(expression->rhs.get())).getVariant());
        }

        Value visitUnaryOperatorExpression(ast::UnaryOperatorExpression* expression) override {
            int lhs = std::get<int>(removeReference(visit(expression->lhs.get())).getVariant());

            switch (expression->op) {
                case ast::UnaryOperator::BITNOT:
                    return Value{~lhs};
                case ast::UnaryOperator::NOT:
                    return Value{!lhs};
            }
        }

        Value visitIntegerLiteral(ast::IntegerLiteral *literal) override {
            return Value{literal->value};
        }

        Value visitFloatLiteral(ast::FloatLiteral *literal) override {
            return Value{literal->value};
        }

        Value visitBoolLiteral(ast::BoolLiteral* literal) override {
            return Value{literal->value};
        }

        Value visitVariableDeclaration(ast::VariableDeclaration *var_decl) override {
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

        Value visitVariableExpression(ast::VariableExpression *identifier) override {
            return findValue(identifier->variable);
        }

        Value visitComplexAssignment(ast::ComplexAssignment *assignment) override {
            auto& var = findValue(assignment->variable);
            var = util::visit(var.getVariant(),
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

        Value visitSimpleAssignment(ast::SimpleAssignment *assignment) override {
            auto& var = findValue(assignment->variable);
            var = visit(assignment->expression.get());
            return var;
        }

        Value visitBlock(ast::Block *block) override {

            for (auto& statement : block->statements) {
                if (std::holds_alternative<Returning>(visit(statement.get()).getVariant())) {
                    return Returning{};
                }
            }

            return std::monostate{};
        }

        Value visitIfStatement(ast::IfStatement* if_stat) override {
            for (auto& block : if_stat->if_blocks) {
                if (std::get<bool>(visit(block.condition.get()).getVariant())) {
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

        Value visitWhileLoop(ast::WhileLoop* loop) override {
            while (std::get<bool>(visit(loop->condition.get()).getVariant())) {
                if (std::holds_alternative<Returning>(visit(loop->body.get()).getVariant())) {
                    return Returning{};
                }
            }

            return std::monostate{};
        }

        Value visitReturnStatement(ast::ReturnStatement* return_stat) override {
            return_value = visit(return_stat->expression.get()).getVariant();
            return Returning{};
        }

        Value visitFunctionDeclaration(ast::FunctionDeclaration *) override {
            return std::monostate{};
        }

        Value visitFunctionCall(ast::FunctionCall* call) override {
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
                    visit(call->arguments.at(i).get())
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

        Value visitTypeDeclaration(ast::TypeDeclaration*) override {
            return std::monostate{};
        }
    };
}

#endif //PANKO_INTERPRETER_H
