
// Generated from /home/jack/Documents/Panko/Panko.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "PankoParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PankoParser.
 */
class  PankoVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PankoParser.
   */
    virtual antlrcpp::Any visitFile(PankoParser::FileContext *context) = 0;

    virtual antlrcpp::Any visitBlock(PankoParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitFunc_decl(PankoParser::Func_declContext *context) = 0;

    virtual antlrcpp::Any visitSemi_statement(PankoParser::Semi_statementContext *context) = 0;

    virtual antlrcpp::Any visitBlock_statement(PankoParser::Block_statementContext *context) = 0;

    virtual antlrcpp::Any visitParen_expr(PankoParser::Paren_exprContext *context) = 0;

    virtual antlrcpp::Any visitUnary_expr(PankoParser::Unary_exprContext *context) = 0;

    virtual antlrcpp::Any visitAccess_expr(PankoParser::Access_exprContext *context) = 0;

    virtual antlrcpp::Any visitComplex_assignment(PankoParser::Complex_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitBinary_expr(PankoParser::Binary_exprContext *context) = 0;

    virtual antlrcpp::Any visitId_expr(PankoParser::Id_exprContext *context) = 0;

    virtual antlrcpp::Any visitSimple_assignment(PankoParser::Simple_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitFunc_expr(PankoParser::Func_exprContext *context) = 0;

    virtual antlrcpp::Any visitInt_lit(PankoParser::Int_litContext *context) = 0;

    virtual antlrcpp::Any visitFloat_lit(PankoParser::Float_litContext *context) = 0;

    virtual antlrcpp::Any visitBool_lit(PankoParser::Bool_litContext *context) = 0;

    virtual antlrcpp::Any visitTyped_identifier(PankoParser::Typed_identifierContext *context) = 0;

    virtual antlrcpp::Any visitType(PankoParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitArgument_list(PankoParser::Argument_listContext *context) = 0;

    virtual antlrcpp::Any visitVar_decl(PankoParser::Var_declContext *context) = 0;

    virtual antlrcpp::Any visitIf_statement(PankoParser::If_statementContext *context) = 0;

    virtual antlrcpp::Any visitIf_block(PankoParser::If_blockContext *context) = 0;

    virtual antlrcpp::Any visitWhile_loop(PankoParser::While_loopContext *context) = 0;

    virtual antlrcpp::Any visitReturn_statement(PankoParser::Return_statementContext *context) = 0;

    virtual antlrcpp::Any visitType_decl(PankoParser::Type_declContext *context) = 0;

    virtual antlrcpp::Any visitBuiltin_type(PankoParser::Builtin_typeContext *context) = 0;

    virtual antlrcpp::Any visitBinary_operator(PankoParser::Binary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitUnary_operator(PankoParser::Unary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_operator(PankoParser::Assignment_operatorContext *context) = 0;


};

