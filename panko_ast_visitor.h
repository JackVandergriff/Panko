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
        virtual T visitIntegerLiteral(IntegerLiteral*)=0;
        virtual T visitFloatLiteral(FloatLiteral*)=0;
        virtual T visitBoolLiteral(BoolLiteral*)=0;
        virtual T visitNullLiteral(NullLiteral*)=0;
        virtual T visitFunctionCall(FunctionCall*)=0;
        virtual T visitBinaryOperatorExpression(BinaryOperatorExpression*)=0;
        virtual T visitUnaryOperatorExpression(UnaryOperatorExpression*)=0;
        virtual T visitVariableDeclaration(VariableDeclaration*)=0;
        virtual T visitVariableExpression(VariableExpression*)=0;
        virtual T visitComplexAssignment(ComplexAssignment*)=0;
        virtual T visitSimpleAssignment(SimpleAssignment*)=0;
        virtual T visitIfStatement(IfStatement*)=0;
        virtual T visitWhileLoop(WhileLoop*)=0;
        virtual T visitReturnStatement(ReturnStatement*)=0;
        virtual T visitFunctionDeclaration(FunctionDeclaration*)=0;
        virtual T visitTypeDeclaration(TypeDeclaration*)=0;
        virtual T visitAccessExpression(AccessExpression*)=0;
        virtual T visitArrayAccessExpression(ArrayAccessExpression*)=0;
        virtual T visitObjectExpression(ObjectExpression*)=0;
        virtual T visitArrayExpression(ArrayExpression*)=0;

        T visit(Node* node) { // Will dispatch to most specified type
            if (auto statement = dynamic_cast<Statement*>(node)) {
                if (auto expression = dynamic_cast<Expression*>(statement)) {
                    if (auto int_lit = dynamic_cast<IntegerLiteral*>(expression)) {
                        return visitIntegerLiteral(int_lit);
                    } else if (auto float_lit = dynamic_cast<FloatLiteral*>(expression)) {
                        return visitFloatLiteral(float_lit);
                    } else if (auto bool_lit = dynamic_cast<BoolLiteral*>(expression)) {
                        return visitBoolLiteral(bool_lit);
                    } else if (auto null_lit = dynamic_cast<NullLiteral*>(expression)) {
                        return visitNullLiteral(null_lit);
                    } else if (auto func_call = dynamic_cast<FunctionCall*>(expression)) {
                        return visitFunctionCall(func_call);
                    } else if (auto binop_expr = dynamic_cast<BinaryOperatorExpression*>(expression)) {
                        return visitBinaryOperatorExpression(binop_expr);
                    } else if (auto unary_expr = dynamic_cast<UnaryOperatorExpression*>(expression)) {
                        return visitUnaryOperatorExpression(unary_expr);
                    } else if (auto var_expr = dynamic_cast<VariableExpression*>(expression)) {
                        return visitVariableExpression(var_expr);
                    } else if (auto assignment = dynamic_cast<ComplexAssignment*>(expression)) {
                        return visitComplexAssignment(assignment);
                    } else if (auto assignment = dynamic_cast<SimpleAssignment*>(expression)) {
                        return visitSimpleAssignment(assignment);
                    } else if (auto access = dynamic_cast<AccessExpression*>(expression)) {
                        return visitAccessExpression(access);
                    } else if (auto array_access = dynamic_cast<ArrayAccessExpression*>(expression)) {
                        return visitArrayAccessExpression(array_access);
                    } else if (auto obj = dynamic_cast<ObjectExpression*>(expression)) {
                        return visitObjectExpression(obj);
                    } else if (auto arr = dynamic_cast<ArrayExpression*>(expression)) {
                        return visitArrayExpression(arr);
                    } else {
                        return visitExpression(expression);
                    }
                } else if (auto var_decl = dynamic_cast<VariableDeclaration*>(statement)) {
                    return visitVariableDeclaration(var_decl);
                } else if (auto func_decl = dynamic_cast<FunctionDeclaration*>(statement)) {
                    return visitFunctionDeclaration(func_decl);
                } else if (auto type_decl = dynamic_cast<TypeDeclaration*>(statement)) {
                    return visitTypeDeclaration(type_decl);
                } else if (auto if_stat = dynamic_cast<IfStatement*>(statement)) {
                    return visitIfStatement(if_stat);
                } else if (auto while_loop = dynamic_cast<WhileLoop*>(statement)) {
                    return visitWhileLoop(while_loop);
                } else if (auto return_stat = dynamic_cast<ReturnStatement*>(statement)) {
                    return visitReturnStatement(return_stat);
                } else {
                    return visitStatement(statement);
                }
            } else if (auto block = dynamic_cast<Block*>(node)) {
                return visitBlock(block);
            } else if (auto file = dynamic_cast<File*>(node)) {
                return visitFile(file);
            } else {
                return {};
            }
        }
    };

    template<typename T>
    struct BaseVisitor : Visitor<T> {
        T visitFile(File*) override { return T(); }
        T visitBlock(Block*) override { return T(); }
        T visitStatement(Statement *statement) override { return this->visit(statement); }
        T visitExpression(Expression *expression) override { return this->visit(expression); }
        T visitIntegerLiteral(IntegerLiteral*) override { return T(); }
        T visitFloatLiteral(FloatLiteral*) override { return T(); }
        T visitBoolLiteral(BoolLiteral*) override { return T(); }
        T visitNullLiteral(NullLiteral*) override { return T(); }
        T visitFunctionCall(FunctionCall*) override { return T(); }
        T visitBinaryOperatorExpression(BinaryOperatorExpression*) override { return T(); }
        T visitUnaryOperatorExpression(UnaryOperatorExpression*) override { return T(); }
        T visitVariableExpression(VariableExpression*) override { return T(); }
        T visitVariableDeclaration(VariableDeclaration*) override { return T(); }
        T visitComplexAssignment(ComplexAssignment*) override { return T(); }
        T visitSimpleAssignment(SimpleAssignment*) override { return T(); }
        T visitIfStatement(IfStatement*) override { return T(); }
        T visitWhileLoop(WhileLoop*) override { return T(); }
        T visitReturnStatement(ReturnStatement*) override { return T(); }
        T visitFunctionDeclaration(FunctionDeclaration*) override { return T(); }
        T visitTypeDeclaration(TypeDeclaration*) override { return T(); }
        T visitAccessExpression(AccessExpression*) override { return T(); }
        T visitArrayAccessExpression(ArrayAccessExpression*) override { return T(); }
        T visitObjectExpression(ObjectExpression*) override { return T(); }
        T visitArrayExpression(ArrayExpression*) override { return T(); }
    };
}

#endif //PANKO_AST_VISITOR_H
