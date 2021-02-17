
// Generated from /home/jack/Documents/Panko/Panko.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "PankoVisitor.h"


/**
 * This class provides an empty implementation of PankoVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PankoBaseVisitor : public PankoVisitor {
public:

  virtual antlrcpp::Any visitFile(PankoParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(PankoParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunc_decl(PankoParser::Func_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSemi_statement(PankoParser::Semi_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_statement(PankoParser::Block_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParen_expr(PankoParser::Paren_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_expr(PankoParser::Unary_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComplex_assignment(PankoParser::Complex_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary_expr(PankoParser::Binary_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_assignment(PankoParser::Simple_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitId_expr(PankoParser::Id_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunc_expr(PankoParser::Func_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt_lit(PankoParser::Int_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloat_lit(PankoParser::Float_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBool_lit(PankoParser::Bool_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTyped_identifier(PankoParser::Typed_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(PankoParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgument_list(PankoParser::Argument_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_decl(PankoParser::Var_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_statement(PankoParser::If_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_block(PankoParser::If_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile_loop(PankoParser::While_loopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn_statement(PankoParser::Return_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_decl(PankoParser::Type_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBuiltin_type(PankoParser::Builtin_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary_operator(PankoParser::Binary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_operator(PankoParser::Unary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment_operator(PankoParser::Assignment_operatorContext *ctx) override {
    return visitChildren(ctx);
  }


};

