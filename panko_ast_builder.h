//
// Created by jack on 1/25/21.
//

#ifndef PANKO_AST_BUILDER_H
#define PANKO_AST_BUILDER_H

#include "PankoBaseVisitor.h"
#include "panko_ast.h"

#include <map>
#include <string>
#include <iostream>

namespace panko {

    struct Variable {};
    struct Function {};
    struct Type {};

    class ASTBuilder : PankoBaseVisitor {
    private:
        ast::AST built_ast{};

        antlrcpp::Any visitFile(PankoParser::FileContext *context) override {
            auto file = new ast::File();
            for (auto& statement : context->statement()) {
                file->statements.push_back(make_unique_any<ast::Statement>(statement->accept(this)));
            }

            return file;
        }

        antlrcpp::Any visitBlock(PankoParser::BlockContext *context) override {
            auto block = new ast::Block();
            for (auto statement : context->statement()) {
                block->statements.push_back(make_unique_any<ast::Statement>(visit(statement)));
            }

            return static_cast<ast::Node*>(block);
        }

        antlrcpp::Any visitBlock_statement(PankoParser::Block_statementContext *context) override {
            return visitChildren(context);
        }

        antlrcpp::Any visitSemi_statement(PankoParser::Semi_statementContext *context) override {
            return context->children[0]->accept(this);
        }

        antlrcpp::Any visitFunc_decl(PankoParser::Func_declContext *context) override {
            return antlrcpp::Any();
        }

        antlrcpp::Any visitUnary_expr(PankoParser::Unary_exprContext *context) override {
            auto expr = new ast::UnaryOperatorExpression();
            auto op = context->unary_operator()->getText();

            if (op == "!") {
                expr->op = ast::UnaryOperator::NOT;
            } else if (op == "~") {
                expr->op = ast::UnaryOperator::BITNOT;
            }

            expr->lhs = make_unique_any<ast::Expression>(context->expression()->accept(this));

            return static_cast<ast::Node*>(expr);
        }

        antlrcpp::Any visitComplex_assignment(PankoParser::Complex_assignmentContext *context) override {
            auto expr = new ast::ComplexAssignment();
            expr->variable = built_ast.variables.hash(context->IDENTIFIER()->getText());
            expr->increment = context->op->getText() == "++";
            return static_cast<ast::Node*>(expr);
        }

        antlrcpp::Any visitBinary_expr(PankoParser::Binary_exprContext *context) override {
            auto expr = new ast::BinaryOperatorExpression();
            auto op = context->binary_operator()->getText();

            if (op == "||") {
                expr->op = ast::BinaryOperator::OR;
            } else if (op == "&&") {
                expr->op = ast::BinaryOperator::AND;
            } else if (op == "==") {
                expr->op = ast::BinaryOperator::EQ;
            } else if (op == "!=") {
                expr->op = ast::BinaryOperator::NEQ;
            } else if (op == ">") {
                expr->op = ast::BinaryOperator::GT;
            } else if (op == "<") {
                expr->op = ast::BinaryOperator::LT;
            } else if (op == ">=") {
                expr->op = ast::BinaryOperator::GTEQ;
            } else if (op == "<=") {
                expr->op = ast::BinaryOperator::LTEQ;
            } else if (op == "+") {
                expr->op = ast::BinaryOperator::ADD;
            } else if (op == "-") {
                expr->op = ast::BinaryOperator::SUB;
            } else if (op == "*") {
                expr->op = ast::BinaryOperator::MUL;
            } else if (op == "/") {
                expr->op = ast::BinaryOperator::DIV;
            } else if (op == "%") {
                expr->op = ast::BinaryOperator::MOD;
            } else if (op == "^") {
                expr->op = ast::BinaryOperator::XOR;
            } else if (op == "&") {
                expr->op = ast::BinaryOperator::BITAND;
            } else if (op == "|") {
                expr->op = ast::BinaryOperator::BITOR;
            }

            expr->lhs = make_unique_any<ast::Expression>(context->lhs->accept(this));
            expr->rhs = make_unique_any<ast::Expression>(context->rhs->accept(this));

            return static_cast<ast::Node*>(expr);
        }

        antlrcpp::Any visitSimple_assignment(PankoParser::Simple_assignmentContext *context) override {
            auto expr = new ast::SimpleAssignment();
            expr->variable = built_ast.variables.hash(context->IDENTIFIER()->getText());
            expr->expression = make_unique_any<ast::Expression>(context->expression()->accept(this));
            return static_cast<ast::Node*>(expr);
        }

        antlrcpp::Any visitId_expr(PankoParser::Id_exprContext *context) override {
            auto expr = new ast::Identifier();
            expr->variable = built_ast.variables.hash(context->IDENTIFIER()->getText());
            return static_cast<ast::Node*>(expr);
        }

        antlrcpp::Any visitFunc_expr(PankoParser::Func_exprContext *context) override {
            return antlrcpp::Any();
        }

        antlrcpp::Any visitInt_lit(PankoParser::Int_litContext *context) override {
            auto int_lit = new ast::IntegerLiteral();
            int_lit->value = std::stoi(context->INTLIT()->getText());
            return static_cast<ast::Node*>(int_lit);
        }

        antlrcpp::Any visitFloat_lit(PankoParser::Float_litContext *context) override {
            auto float_lit = new ast::FloatLiteral();
            float_lit->value = std::stod(context->FLOATLIT()->getText());
            return static_cast<ast::Node*>(float_lit);
        }

        antlrcpp::Any visitTyped_identifier(PankoParser::Typed_identifierContext *context) override {
            return antlrcpp::Any();
        }

        antlrcpp::Any visitType(PankoParser::TypeContext *context) override {
            return antlrcpp::Any();
        }

        antlrcpp::Any visitArgument_list(PankoParser::Argument_listContext *context) override {
            return antlrcpp::Any();
        }

        antlrcpp::Any visitVar_decl(PankoParser::Var_declContext *context) override {
            auto expr = new ast::VariableDeclaration();
            expr->variable = built_ast.variables.make(
                    util::string_hash(context->typed_identifier()->IDENTIFIER()->getText()),
                    built_ast.types.hash(context->typed_identifier()->type()->getText())
            );
            expr->assignment = make_unique_any<ast::Expression>(context->expression()->accept(this));

            return static_cast<ast::Node*>(expr);
        }

        antlrcpp::Any visitIf_statement(PankoParser::If_statementContext *context) override {
            auto statement = new ast::IfStatement();
            for(auto block : context->if_block()) {
                auto& back = statement->if_blocks.emplace_back();
                back.condition = make_unique_any<ast::Expression>(block->expression()->accept(this));
                back.block = make_unique_any<ast::Block>(block->block()->accept(this));
            }
            statement->else_block = make_unique_any<ast::Block>(context->final->accept(this));
            return static_cast<ast::Node*>(statement);
        }

        antlrcpp::Any visitIf_block(PankoParser::If_blockContext *context) override {
            return antlrcpp::Any();
        }

        antlrcpp::Any visitReturn_statement(PankoParser::Return_statementContext *context) override {
            return antlrcpp::Any();
        }

        antlrcpp::Any visitBuiltin_type(PankoParser::Builtin_typeContext *context) override {
            return antlrcpp::Any();
        }

        antlrcpp::Any visitBinary_operator(PankoParser::Binary_operatorContext *context) override {
            return antlrcpp::Any();
        }

        antlrcpp::Any visitUnary_operator(PankoParser::Unary_operatorContext *context) override {
            return antlrcpp::Any();
        }

        antlrcpp::Any visitAssignment_operator(PankoParser::Assignment_operatorContext *context) override {
            return antlrcpp::Any();
        }

        antlrcpp::Any visitParen_expr(PankoParser::Paren_exprContext *context) override {
            return context->expression()->accept(this);
        }

        template<typename T>
        std::unique_ptr<T> make_unique_any(antlrcpp::Any any) {
            return std::unique_ptr<T>((T*)any.as<ast::Node*>()); // Pass around everything as Node*
        }

    public:
        ASTBuilder() {
            built_ast.types.make("int");
            built_ast.types.make("float");
            built_ast.types.make("bool");
        }

        ASTBuilder& appendFile(PankoParser& parser) {
            built_ast.files.emplace_back((ast::File*)visitFile(parser.file()));
            return *this;
        }

        [[nodiscard]] const ast::AST& getTree() const {
            return built_ast;
        }
    };
}

#endif //PANKO_AST_BUILDER_H
