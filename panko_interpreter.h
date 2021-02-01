//
// Created by jack on 1/24/21.
//

#ifndef PANKO_INTERPRETER_H
#define PANKO_INTERPRETER_H

#include "panko_ast_visitor.h"

#include <iostream>
#include <variant>

namespace panko::runtime {

    struct ComplexValue;

    using Value = util::invariant<int, double, bool, std::monostate, ComplexValue>;

    struct ComplexValue {
        std::map<util::string_hash, Value> attributes;
    };

    Value constructValue(const ast::Type& type) {
        if (type.name == util::string_hash{"int"}) {
            return Value{std::in_place_type<int>};
        } else if (type.name == util::string_hash{"float"}) {
            return Value{std::in_place_type<double>};
        } else if (type.name == util::string_hash{"bool"}) {
            return Value{std::in_place_type<bool>};
        } else {
            return std::monostate{};
        }
    }

    struct Interpreter : ast::BaseVisitor<Value> {
        const ast::AST& ast;
        std::map<ast::variable_hash, Value> variables;

        explicit Interpreter(const ast::AST& ast) : ast{ast} {}

        void run() {
            for (auto& file : ast.files) {
                visitFile(file.get());
            }
        }

        Value visitFile(ast::File *file) override {
            for (auto& statement : file->statements) {
                util::visit(visit(statement.get()).getVariant(),
                    [](int i){std::cout << "Int: " << i << '\n';},
                    [](double d){std::cout << "Double: " << d << '\n';},
                    [](bool b){std::cout << "Bool: " << b << '\n';},
                    [](auto any) {}
                );
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
                [](auto lhs, auto rhs){return Value{std::monostate{}};}
            }, visit(expression->lhs.get()).getVariant(), visit(expression->rhs.get()).getVariant());
        }

        Value visitUnaryOperatorExpression(ast::UnaryOperatorExpression* expression) override {
            int lhs = std::get<int>(visit(expression->lhs.get()).getVariant());

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

        Value visitVariableDeclaration(ast::VariableDeclaration *var_decl) override {
            const auto& var = ast.variables.get(var_decl->variable);
            variables.emplace(var_decl->variable, constructValue(ast.types.get(var.type)));
            if (auto assignment = var_decl->assignment.get()) {
                variables.at(var_decl->variable) = visit(assignment);
                return variables.at(var_decl->variable);
            } else {
                return std::monostate{};
            }
        }

        Value visitIdentifier(ast::Identifier *identifier) override {
            return variables.at(identifier->variable);
        }

        Value visitComplexAssignment(ast::ComplexAssignment *assignment) override {
            auto& var = variables.at(assignment->variable);
            var = util::visit(var.getVariant(),
                [assignment](util::Number auto value){
                    if (assignment->increment) {
                        return Value{value + 1};
                    } else {
                        return Value{value - 1};
                    }
                },
                [](auto value){return Value{std::monostate{}};}
            );

            return var;
        }

        Value visitSimpleAssignment(ast::SimpleAssignment *assignment) override {
            auto& var = variables.at(assignment->variable);
            var = visit(assignment->expression.get());
            return var;
        }
    };
}

#endif //PANKO_INTERPRETER_H
