//
// Created by jack on 1/27/21.
//

#ifndef PANKO_AST_VISITOR_H
#define PANKO_AST_VISITOR_H

#include <any>
#include <variant>

#include "panko_ast.h"

namespace panko::ast {

    template<typename T>
    struct Visitor {
        virtual T visitFile(File*)=0;
        virtual T visitBlock(Block*)=0;
        virtual T visitStatement(Statement*)=0;
        virtual T visitExpression(Expression*)=0;
        virtual T visitVariable(Variable*)=0;
        virtual T visitFunction(Function*)=0;
        virtual T visitIntegerLiteral(IntegerLiteral*)=0;
        virtual T visitFloatLiteral(FloatLiteral*)=0;
        virtual T visitFunctionCall(FunctionCall*)=0;
        virtual T visitBinaryOperatorExpression(BinaryOperatorExpression*)=0;
        virtual T visitUnaryOperatorExpression(UnaryOperatorExpression*)=0;
        virtual T visitVariableDeclaration(VariableDeclaration*)=0;
        virtual T visitIdentifier(Identifier*)=0;
        virtual T visitComplexAssignment(ComplexAssignment*)=0;
        virtual T visitSimpleAssignment(SimpleAssignment*)=0;

        T visit(Node* node) { // Will dispatch to most specified type
            if (auto statement = dynamic_cast<Statement*>(node)) {
                if (auto expression = dynamic_cast<Expression*>(statement)) {
                    if (auto int_lit = dynamic_cast<IntegerLiteral *>(expression)) {
                        return visitIntegerLiteral(int_lit);
                    } else if (auto float_lit = dynamic_cast<FloatLiteral *>(expression)) {
                        return visitFloatLiteral(float_lit);
                    } else if (auto func_call = dynamic_cast<FunctionCall *>(expression)) {
                        return visitFunctionCall(func_call);
                    } else if (auto binop_expr = dynamic_cast<BinaryOperatorExpression *>(expression)) {
                        return visitBinaryOperatorExpression(binop_expr);
                    } else if (auto unary_expr = dynamic_cast<UnaryOperatorExpression *>(expression)) {
                        return visitUnaryOperatorExpression(unary_expr);
                    } else if (auto id = dynamic_cast<Identifier*>(expression)) {
                        return visitIdentifier(id);
                    } else if (auto assignment = dynamic_cast<ComplexAssignment*>(expression)) {
                        return visitComplexAssignment(assignment);
                    } else if (auto assignment = dynamic_cast<SimpleAssignment*>(expression)) {
                        return visitSimpleAssignment(assignment);
                    } else {
                        return visitExpression(expression);
                    }
                } else if (auto var_decl = dynamic_cast<VariableDeclaration*>(statement)) {
                    return visitVariableDeclaration(var_decl);
                } else {
                    return visitStatement(statement);
                }
            } else if (auto block = dynamic_cast<Block*>(node)) {
                return visitBlock(block);
            } else if (auto variable = dynamic_cast<Variable*>(node)) {
                return visitVariable(variable);
            } else if (auto function = dynamic_cast<Function*>(node)) {
                return visitFunction(function);
            } else if (auto file = dynamic_cast<File*>(node)) {
                return visitFile(file);
            } else {
                return {};
            }
        }
    };

    template<typename T>
    struct BaseVisitor : Visitor<T> {
        T visitFile(File *file) override {
            return T();
        }

        T visitBlock(Block *block) override {
            return T();
        }

        T visitStatement(Statement *statement) override {
            return this->visit(statement);
        }

        T visitExpression(Expression *expression) override {
            return this->visit(expression);
        }

        T visitVariable(Variable *variable) override {
            return T();
        }

        T visitFunction(Function *function) override {
            return T();
        }

        T visitIntegerLiteral(IntegerLiteral *literal) override {
            return T();
        }

        T visitFloatLiteral(FloatLiteral *literal) override {
            return T();
        }

        T visitFunctionCall(FunctionCall *call) override {
            return T();
        }

        T visitBinaryOperatorExpression(BinaryOperatorExpression *expression) override {
            return T();
        }

        T visitUnaryOperatorExpression(UnaryOperatorExpression *expression) override {
            return T();
        }

        T visitIdentifier(Identifier *identifier) override {
            return T();
        }

        T visitVariableDeclaration(VariableDeclaration *var_decl) override {
            return T();
        }

        T visitComplexAssignment(ComplexAssignment *assignment) override {
            return T();
        }

        T visitSimpleAssignment(SimpleAssignment* assignment) override {
            return T();
        }
    };
}

#endif //PANKO_AST_VISITOR_H
