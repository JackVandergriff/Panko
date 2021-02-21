
// Generated from /home/jack/Documents/Panko/Panko.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "PankoParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by PankoParser.
 */
class  PankoListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(PankoParser::FileContext *ctx) = 0;
  virtual void exitFile(PankoParser::FileContext *ctx) = 0;

  virtual void enterBlock(PankoParser::BlockContext *ctx) = 0;
  virtual void exitBlock(PankoParser::BlockContext *ctx) = 0;

  virtual void enterFunc_decl(PankoParser::Func_declContext *ctx) = 0;
  virtual void exitFunc_decl(PankoParser::Func_declContext *ctx) = 0;

  virtual void enterSemi_statement(PankoParser::Semi_statementContext *ctx) = 0;
  virtual void exitSemi_statement(PankoParser::Semi_statementContext *ctx) = 0;

  virtual void enterBlock_statement(PankoParser::Block_statementContext *ctx) = 0;
  virtual void exitBlock_statement(PankoParser::Block_statementContext *ctx) = 0;

  virtual void enterParen_expr(PankoParser::Paren_exprContext *ctx) = 0;
  virtual void exitParen_expr(PankoParser::Paren_exprContext *ctx) = 0;

  virtual void enterUnary_expr(PankoParser::Unary_exprContext *ctx) = 0;
  virtual void exitUnary_expr(PankoParser::Unary_exprContext *ctx) = 0;

  virtual void enterAccess_expr(PankoParser::Access_exprContext *ctx) = 0;
  virtual void exitAccess_expr(PankoParser::Access_exprContext *ctx) = 0;

  virtual void enterComplex_assignment(PankoParser::Complex_assignmentContext *ctx) = 0;
  virtual void exitComplex_assignment(PankoParser::Complex_assignmentContext *ctx) = 0;

  virtual void enterBinary_expr(PankoParser::Binary_exprContext *ctx) = 0;
  virtual void exitBinary_expr(PankoParser::Binary_exprContext *ctx) = 0;

  virtual void enterId_expr(PankoParser::Id_exprContext *ctx) = 0;
  virtual void exitId_expr(PankoParser::Id_exprContext *ctx) = 0;

  virtual void enterSimple_assignment(PankoParser::Simple_assignmentContext *ctx) = 0;
  virtual void exitSimple_assignment(PankoParser::Simple_assignmentContext *ctx) = 0;

  virtual void enterFunc_expr(PankoParser::Func_exprContext *ctx) = 0;
  virtual void exitFunc_expr(PankoParser::Func_exprContext *ctx) = 0;

  virtual void enterInt_lit(PankoParser::Int_litContext *ctx) = 0;
  virtual void exitInt_lit(PankoParser::Int_litContext *ctx) = 0;

  virtual void enterFloat_lit(PankoParser::Float_litContext *ctx) = 0;
  virtual void exitFloat_lit(PankoParser::Float_litContext *ctx) = 0;

  virtual void enterObj_expr(PankoParser::Obj_exprContext *ctx) = 0;
  virtual void exitObj_expr(PankoParser::Obj_exprContext *ctx) = 0;

  virtual void enterBool_lit(PankoParser::Bool_litContext *ctx) = 0;
  virtual void exitBool_lit(PankoParser::Bool_litContext *ctx) = 0;

  virtual void enterTyped_identifier(PankoParser::Typed_identifierContext *ctx) = 0;
  virtual void exitTyped_identifier(PankoParser::Typed_identifierContext *ctx) = 0;

  virtual void enterType(PankoParser::TypeContext *ctx) = 0;
  virtual void exitType(PankoParser::TypeContext *ctx) = 0;

  virtual void enterArgument_list(PankoParser::Argument_listContext *ctx) = 0;
  virtual void exitArgument_list(PankoParser::Argument_listContext *ctx) = 0;

  virtual void enterVar_decl(PankoParser::Var_declContext *ctx) = 0;
  virtual void exitVar_decl(PankoParser::Var_declContext *ctx) = 0;

  virtual void enterIf_statement(PankoParser::If_statementContext *ctx) = 0;
  virtual void exitIf_statement(PankoParser::If_statementContext *ctx) = 0;

  virtual void enterIf_block(PankoParser::If_blockContext *ctx) = 0;
  virtual void exitIf_block(PankoParser::If_blockContext *ctx) = 0;

  virtual void enterWhile_loop(PankoParser::While_loopContext *ctx) = 0;
  virtual void exitWhile_loop(PankoParser::While_loopContext *ctx) = 0;

  virtual void enterReturn_statement(PankoParser::Return_statementContext *ctx) = 0;
  virtual void exitReturn_statement(PankoParser::Return_statementContext *ctx) = 0;

  virtual void enterType_decl(PankoParser::Type_declContext *ctx) = 0;
  virtual void exitType_decl(PankoParser::Type_declContext *ctx) = 0;

  virtual void enterObject_var(PankoParser::Object_varContext *ctx) = 0;
  virtual void exitObject_var(PankoParser::Object_varContext *ctx) = 0;

  virtual void enterBuiltin_type(PankoParser::Builtin_typeContext *ctx) = 0;
  virtual void exitBuiltin_type(PankoParser::Builtin_typeContext *ctx) = 0;

  virtual void enterBinary_operator(PankoParser::Binary_operatorContext *ctx) = 0;
  virtual void exitBinary_operator(PankoParser::Binary_operatorContext *ctx) = 0;

  virtual void enterUnary_operator(PankoParser::Unary_operatorContext *ctx) = 0;
  virtual void exitUnary_operator(PankoParser::Unary_operatorContext *ctx) = 0;

  virtual void enterAssignment_operator(PankoParser::Assignment_operatorContext *ctx) = 0;
  virtual void exitAssignment_operator(PankoParser::Assignment_operatorContext *ctx) = 0;


};

