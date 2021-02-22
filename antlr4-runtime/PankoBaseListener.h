
// Generated from /home/jack/Documents/Panko/Panko.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "PankoListener.h"


/**
 * This class provides an empty implementation of PankoListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  PankoBaseListener : public PankoListener {
public:

  virtual void enterFile(PankoParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(PankoParser::FileContext * /*ctx*/) override { }

  virtual void enterBlock(PankoParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(PankoParser::BlockContext * /*ctx*/) override { }

  virtual void enterFunc_decl(PankoParser::Func_declContext * /*ctx*/) override { }
  virtual void exitFunc_decl(PankoParser::Func_declContext * /*ctx*/) override { }

  virtual void enterSemi_statement(PankoParser::Semi_statementContext * /*ctx*/) override { }
  virtual void exitSemi_statement(PankoParser::Semi_statementContext * /*ctx*/) override { }

  virtual void enterBlock_statement(PankoParser::Block_statementContext * /*ctx*/) override { }
  virtual void exitBlock_statement(PankoParser::Block_statementContext * /*ctx*/) override { }

  virtual void enterParen_expr(PankoParser::Paren_exprContext * /*ctx*/) override { }
  virtual void exitParen_expr(PankoParser::Paren_exprContext * /*ctx*/) override { }

  virtual void enterUnary_expr(PankoParser::Unary_exprContext * /*ctx*/) override { }
  virtual void exitUnary_expr(PankoParser::Unary_exprContext * /*ctx*/) override { }

  virtual void enterAccess_expr(PankoParser::Access_exprContext * /*ctx*/) override { }
  virtual void exitAccess_expr(PankoParser::Access_exprContext * /*ctx*/) override { }

  virtual void enterComplex_assignment(PankoParser::Complex_assignmentContext * /*ctx*/) override { }
  virtual void exitComplex_assignment(PankoParser::Complex_assignmentContext * /*ctx*/) override { }

  virtual void enterBinary_expr(PankoParser::Binary_exprContext * /*ctx*/) override { }
  virtual void exitBinary_expr(PankoParser::Binary_exprContext * /*ctx*/) override { }

  virtual void enterId_expr(PankoParser::Id_exprContext * /*ctx*/) override { }
  virtual void exitId_expr(PankoParser::Id_exprContext * /*ctx*/) override { }

  virtual void enterSimple_assignment(PankoParser::Simple_assignmentContext * /*ctx*/) override { }
  virtual void exitSimple_assignment(PankoParser::Simple_assignmentContext * /*ctx*/) override { }

  virtual void enterFunc_expr(PankoParser::Func_exprContext * /*ctx*/) override { }
  virtual void exitFunc_expr(PankoParser::Func_exprContext * /*ctx*/) override { }

  virtual void enterInt_lit(PankoParser::Int_litContext * /*ctx*/) override { }
  virtual void exitInt_lit(PankoParser::Int_litContext * /*ctx*/) override { }

  virtual void enterFloat_lit(PankoParser::Float_litContext * /*ctx*/) override { }
  virtual void exitFloat_lit(PankoParser::Float_litContext * /*ctx*/) override { }

  virtual void enterObj_expr(PankoParser::Obj_exprContext * /*ctx*/) override { }
  virtual void exitObj_expr(PankoParser::Obj_exprContext * /*ctx*/) override { }

  virtual void enterBool_lit(PankoParser::Bool_litContext * /*ctx*/) override { }
  virtual void exitBool_lit(PankoParser::Bool_litContext * /*ctx*/) override { }

  virtual void enterBuiltin_type(PankoParser::Builtin_typeContext * /*ctx*/) override { }
  virtual void exitBuiltin_type(PankoParser::Builtin_typeContext * /*ctx*/) override { }

  virtual void enterUnary_type(PankoParser::Unary_typeContext * /*ctx*/) override { }
  virtual void exitUnary_type(PankoParser::Unary_typeContext * /*ctx*/) override { }

  virtual void enterId_type(PankoParser::Id_typeContext * /*ctx*/) override { }
  virtual void exitId_type(PankoParser::Id_typeContext * /*ctx*/) override { }

  virtual void enterArray_type(PankoParser::Array_typeContext * /*ctx*/) override { }
  virtual void exitArray_type(PankoParser::Array_typeContext * /*ctx*/) override { }

  virtual void enterTuple_type(PankoParser::Tuple_typeContext * /*ctx*/) override { }
  virtual void exitTuple_type(PankoParser::Tuple_typeContext * /*ctx*/) override { }

  virtual void enterParen_type(PankoParser::Paren_typeContext * /*ctx*/) override { }
  virtual void exitParen_type(PankoParser::Paren_typeContext * /*ctx*/) override { }

  virtual void enterBinary_type(PankoParser::Binary_typeContext * /*ctx*/) override { }
  virtual void exitBinary_type(PankoParser::Binary_typeContext * /*ctx*/) override { }

  virtual void enterTyped_identifier(PankoParser::Typed_identifierContext * /*ctx*/) override { }
  virtual void exitTyped_identifier(PankoParser::Typed_identifierContext * /*ctx*/) override { }

  virtual void enterArgument_list(PankoParser::Argument_listContext * /*ctx*/) override { }
  virtual void exitArgument_list(PankoParser::Argument_listContext * /*ctx*/) override { }

  virtual void enterVar_decl(PankoParser::Var_declContext * /*ctx*/) override { }
  virtual void exitVar_decl(PankoParser::Var_declContext * /*ctx*/) override { }

  virtual void enterIf_statement(PankoParser::If_statementContext * /*ctx*/) override { }
  virtual void exitIf_statement(PankoParser::If_statementContext * /*ctx*/) override { }

  virtual void enterIf_block(PankoParser::If_blockContext * /*ctx*/) override { }
  virtual void exitIf_block(PankoParser::If_blockContext * /*ctx*/) override { }

  virtual void enterWhile_loop(PankoParser::While_loopContext * /*ctx*/) override { }
  virtual void exitWhile_loop(PankoParser::While_loopContext * /*ctx*/) override { }

  virtual void enterReturn_statement(PankoParser::Return_statementContext * /*ctx*/) override { }
  virtual void exitReturn_statement(PankoParser::Return_statementContext * /*ctx*/) override { }

  virtual void enterType_decl(PankoParser::Type_declContext * /*ctx*/) override { }
  virtual void exitType_decl(PankoParser::Type_declContext * /*ctx*/) override { }

  virtual void enterObject_var(PankoParser::Object_varContext * /*ctx*/) override { }
  virtual void exitObject_var(PankoParser::Object_varContext * /*ctx*/) override { }

  virtual void enterBinary_operator(PankoParser::Binary_operatorContext * /*ctx*/) override { }
  virtual void exitBinary_operator(PankoParser::Binary_operatorContext * /*ctx*/) override { }

  virtual void enterUnary_operator(PankoParser::Unary_operatorContext * /*ctx*/) override { }
  virtual void exitUnary_operator(PankoParser::Unary_operatorContext * /*ctx*/) override { }

  virtual void enterType_unary_operator(PankoParser::Type_unary_operatorContext * /*ctx*/) override { }
  virtual void exitType_unary_operator(PankoParser::Type_unary_operatorContext * /*ctx*/) override { }

  virtual void enterType_binary_operator(PankoParser::Type_binary_operatorContext * /*ctx*/) override { }
  virtual void exitType_binary_operator(PankoParser::Type_binary_operatorContext * /*ctx*/) override { }

  virtual void enterAssignment_operator(PankoParser::Assignment_operatorContext * /*ctx*/) override { }
  virtual void exitAssignment_operator(PankoParser::Assignment_operatorContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

