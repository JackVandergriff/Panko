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

    class ASTBuilder : PankoBaseVisitor {
    private:
        ast::AST built_ast{};
        scope::Context cur_context;

        antlrcpp::Any visitFile(PankoParser::FileContext *context) override {
            auto file = new ast::File();

            file->module = context->IDENTIFIER()->getText();
            cur_context.push(scope::Type::MODULE, file->module);

            for (auto& statement : context->statement()) {
                file->statements.push_back(make_unique_any<ast::Statement>(statement->accept(this)));
            }

            cur_context.pop();
            return file;
        }

        antlrcpp::Any visitBlock(PankoParser::BlockContext *context) override {
            auto block = new ast::Block();
            cur_context.push(scope::Type::BLOCK);
            for (auto statement : context->statement()) {
                block->statements.push_back(make_unique_any<ast::Statement>(visit(statement)));
            }

            cur_context.pop();
            return static_cast<ast::Node*>(block);
        }

        antlrcpp::Any visitBlock_statement(PankoParser::Block_statementContext *context) override {
            return visitChildren(context);
        }

        antlrcpp::Any visitSemi_statement(PankoParser::Semi_statementContext *context) override {
            return context->children[0]->accept(this);
        }

        antlrcpp::Any visitFunc_decl(PankoParser::Func_declContext *context) override {
            auto decl = new ast::FunctionDeclaration();
            ast::Function func{cur_context.mangle(context->ret_type->IDENTIFIER()->getText())};
            func.return_type = std::get<size_t>(cur_context.lookup(context->ret_type->type()->getText(), built_ast.types));

            cur_context.push(scope::Type::FUNCTION, static_cast<std::string>(func.name));
            if (!context->params.empty()) {
                for (auto param : context->params) {
                    func.parameters.emplace_back(
                            util::string_hash{cur_context.mangle(param->IDENTIFIER()->getText())},
                            std::get<size_t>(cur_context.lookup(param->type()->getText(), built_ast.types))
                    );
                }
            }

            func.body = make_unique_any<ast::Block>(context->block()->accept(this));

            cur_context.pop();
            decl->function = built_ast.functions.make(std::move(func));

            return static_cast<ast::Node*>(decl);
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
            expr->variable = std::get<size_t>(cur_context.lookup(context->IDENTIFIER()->getText(), built_ast.variables));
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
            expr->variable = std::get<size_t>(cur_context.lookup(context->IDENTIFIER()->getText(), built_ast.variables));
            expr->expression = make_unique_any<ast::Expression>(context->expression()->accept(this));
            return static_cast<ast::Node*>(expr);
        }

        antlrcpp::Any visitId_expr(PankoParser::Id_exprContext *context) override {
            auto expr = new ast::Identifier();
            expr->variable = std::get<size_t>(cur_context.lookup(context->IDENTIFIER()->getText(), built_ast.variables));
            return static_cast<ast::Node*>(expr);
        }

        antlrcpp::Any visitFunc_expr(PankoParser::Func_exprContext *context) override {
            auto expr = new ast::FunctionCall();
            expr->function = std::get<size_t>(cur_context.lookup(context->IDENTIFIER()->getText(), built_ast.functions));

            if (context->argument_list()) {
                for (auto param : context->argument_list()->expression()) {
                    expr->arguments.emplace_back(make_unique_any<ast::Expression>(param->accept(this)));
                }
            }

            return static_cast<ast::Node*>(expr);
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

        antlrcpp::Any visitVar_decl(PankoParser::Var_declContext *context) override {
            auto expr = new ast::VariableDeclaration();
            expr->variable = built_ast.variables.make(
                    cur_context.mangle(context->typed_identifier()->IDENTIFIER()->getText()),
                    std::get<size_t>(cur_context.lookup(context->typed_identifier()->type()->getText(), built_ast.types))
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

            if (context->final) {
                statement->else_block = make_unique_any<ast::Block>(context->final->accept(this));
            }

            return static_cast<ast::Node*>(statement);
        }

        antlrcpp::Any visitWhile_loop(PankoParser::While_loopContext *context) override {
            auto statement = new ast::WhileLoop();
            statement->condition = make_unique_any<ast::Expression>(context->expression()->accept(this));
            statement->body = make_unique_any<ast::Block>(context->block()->accept(this));
            return static_cast<ast::Node*>(statement);
        }

        antlrcpp::Any visitBool_lit(PankoParser::Bool_litContext *context) override {
            auto literal = new ast::BoolLiteral();
            literal->value = context->TRUE();
            return static_cast<ast::Node*>(literal);
        }

        antlrcpp::Any visitReturn_statement(PankoParser::Return_statementContext *context) override {
            auto statement = new ast::ReturnStatement();
            statement->expression = make_unique_any<ast::Expression>(context->expression()->accept(this));
            return static_cast<ast::Node*>(statement);
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
