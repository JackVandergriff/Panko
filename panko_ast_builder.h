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
        scope::Context ast_context;

        antlrcpp::Any visitFile(PankoParser::FileContext *context) override;
        antlrcpp::Any visitBlock(PankoParser::BlockContext *context) override;
        antlrcpp::Any visitBlock_statement(PankoParser::Block_statementContext *context) override;
        antlrcpp::Any visitSemi_statement(PankoParser::Semi_statementContext *context) override;
        antlrcpp::Any visitFunc_decl(PankoParser::Func_declContext *context) override;
        antlrcpp::Any visitUnary_expr(PankoParser::Unary_exprContext *context) override;
        antlrcpp::Any visitComplex_assignment(PankoParser::Complex_assignmentContext *context) override;
        antlrcpp::Any visitBinary_expr(PankoParser::Binary_exprContext *context) override;
        antlrcpp::Any visitSimple_assignment(PankoParser::Simple_assignmentContext *context) override;
        antlrcpp::Any visitId_expr(PankoParser::Id_exprContext *context) override;
        antlrcpp::Any visitFunc_expr(PankoParser::Func_exprContext *context) override;
        antlrcpp::Any visitInt_lit(PankoParser::Int_litContext *context) override;
        antlrcpp::Any visitFloat_lit(PankoParser::Float_litContext *context) override;
        antlrcpp::Any visitVar_decl(PankoParser::Var_declContext *context) override;
        antlrcpp::Any visitIf_statement(PankoParser::If_statementContext *context) override;
        antlrcpp::Any visitWhile_loop(PankoParser::While_loopContext *context) override;
        antlrcpp::Any visitBool_lit(PankoParser::Bool_litContext *context) override;
        antlrcpp::Any visitReturn_statement(PankoParser::Return_statementContext *context) override;
        antlrcpp::Any visitParen_expr(PankoParser::Paren_exprContext *context) override;
        antlrcpp::Any visitType_decl(PankoParser::Type_declContext *context) override;
        antlrcpp::Any visitAccess_expr(PankoParser::Access_exprContext *context) override;
        antlrcpp::Any visitObj_expr(PankoParser::Obj_exprContext *context) override;
        antlrcpp::Any visitBuiltin_type(PankoParser::Builtin_typeContext *context) override;
        antlrcpp::Any visitId_type(PankoParser::Id_typeContext *context) override;
        antlrcpp::Any visitParen_type(PankoParser::Paren_typeContext *context) override;
        antlrcpp::Any visitTuple_type(PankoParser::Tuple_typeContext *context) override;
        antlrcpp::Any visitBinary_type(PankoParser::Binary_typeContext *context) override;
        antlrcpp::Any visitUnary_type(PankoParser::Unary_typeContext *context) override;
        antlrcpp::Any visitArray_type(PankoParser::Array_typeContext *context) override;
        antlrcpp::Any visitArray_expr(PankoParser::Array_exprContext *context) override;

        template<typename T>
        std::unique_ptr<T> make_unique_any(antlrcpp::Any any) {
            return std::unique_ptr<T>((T*)any.as<ast::Node*>()); // Pass around everything as Node*
        }

    public:
        ASTBuilder();
        ASTBuilder& appendFile(PankoParser& parser);
        [[nodiscard]] const ast::AST& getTree() const;
    };
}

#endif //PANKO_AST_BUILDER_H
