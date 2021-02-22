
// Generated from /home/jack/Documents/Panko/Panko.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  PankoParser : public antlr4::Parser {
public:
  enum {
    TYPE = 1, TRUE = 2, FALSE = 3, IF = 4, ELSE = 5, WHILE = 6, FOR = 7, 
    KW_NULL = 8, INT = 9, FLOAT = 10, RETURN = 11, MODULE = 12, IMPORT = 13, 
    OR = 14, AND = 15, EQ = 16, NEQ = 17, GT = 18, LT = 19, GTEQ = 20, LTEQ = 21, 
    ADD = 22, SUB = 23, MUL = 24, DIV = 25, MOD = 26, XOR = 27, BITOR = 28, 
    BITAND = 29, BITNOT = 30, NOT = 31, ELIPSIS = 32, ASSIGN = 33, ADDEQ = 34, 
    SUBEQ = 35, MULEQ = 36, DIVEQ = 37, MODEQ = 38, XOREQ = 39, BITOREQ = 40, 
    BITANDEQ = 41, INC = 42, DEC = 43, SEMICLN = 44, COLON = 45, COMMA = 46, 
    PERIOD = 47, OPAREN = 48, CPAREN = 49, OBRACE = 50, CBRACE = 51, OBRACKET = 52, 
    CBRACKET = 53, IDENTIFIER = 54, INTLIT = 55, FLOATLIT = 56, COMMENT = 57, 
    SPACE = 58
  };

  enum {
    RuleFile = 0, RuleBlock = 1, RuleFunc_decl = 2, RuleStatement = 3, RuleExpression = 4, 
    RuleType = 5, RuleTyped_identifier = 6, RuleArgument_list = 7, RuleVar_decl = 8, 
    RuleIf_statement = 9, RuleIf_block = 10, RuleWhile_loop = 11, RuleReturn_statement = 12, 
    RuleType_decl = 13, RuleObject_var = 14, RuleBinary_operator = 15, RuleUnary_operator = 16, 
    RuleType_unary_operator = 17, RuleType_binary_operator = 18, RuleAssignment_operator = 19
  };

  explicit PankoParser(antlr4::TokenStream *input);
  ~PankoParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class BlockContext;
  class Func_declContext;
  class StatementContext;
  class ExpressionContext;
  class TypeContext;
  class Typed_identifierContext;
  class Argument_listContext;
  class Var_declContext;
  class If_statementContext;
  class If_blockContext;
  class While_loopContext;
  class Return_statementContext;
  class Type_declContext;
  class Object_varContext;
  class Binary_operatorContext;
  class Unary_operatorContext;
  class Type_unary_operatorContext;
  class Type_binary_operatorContext;
  class Assignment_operatorContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MODULE();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *SEMICLN();
    antlr4::tree::TerminalNode *EOF();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBRACE();
    antlr4::tree::TerminalNode *CBRACE();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  Func_declContext : public antlr4::ParserRuleContext {
  public:
    PankoParser::Typed_identifierContext *ret_type = nullptr;
    PankoParser::Typed_identifierContext *typed_identifierContext = nullptr;
    std::vector<Typed_identifierContext *> params;
    Func_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPAREN();
    antlr4::tree::TerminalNode *CPAREN();
    BlockContext *block();
    std::vector<Typed_identifierContext *> typed_identifier();
    Typed_identifierContext* typed_identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_declContext* func_decl();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Semi_statementContext : public StatementContext {
  public:
    Semi_statementContext(StatementContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMICLN();
    Var_declContext *var_decl();
    Return_statementContext *return_statement();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Block_statementContext : public StatementContext {
  public:
    Block_statementContext(StatementContext *ctx);

    Func_declContext *func_decl();
    Type_declContext *type_decl();
    If_statementContext *if_statement();
    While_loopContext *while_loop();
    BlockContext *block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Paren_exprContext : public ExpressionContext {
  public:
    Paren_exprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *OPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CPAREN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Unary_exprContext : public ExpressionContext {
  public:
    Unary_exprContext(ExpressionContext *ctx);

    Unary_operatorContext *unary_operator();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Access_exprContext : public ExpressionContext {
  public:
    Access_exprContext(ExpressionContext *ctx);

    antlr4::Token *initial = nullptr;
    antlr4::Token *identifierToken = nullptr;
    std::vector<antlr4::Token *> accessors;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PERIOD();
    antlr4::tree::TerminalNode* PERIOD(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Complex_assignmentContext : public ExpressionContext {
  public:
    Complex_assignmentContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *INC();
    antlr4::tree::TerminalNode *DEC();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Binary_exprContext : public ExpressionContext {
  public:
    Binary_exprContext(ExpressionContext *ctx);

    PankoParser::ExpressionContext *lhs = nullptr;
    PankoParser::ExpressionContext *rhs = nullptr;
    Binary_operatorContext *binary_operator();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Id_exprContext : public ExpressionContext {
  public:
    Id_exprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_assignmentContext : public ExpressionContext {
  public:
    Simple_assignmentContext(ExpressionContext *ctx);

    PankoParser::ExpressionContext *lhs = nullptr;
    PankoParser::ExpressionContext *rhs = nullptr;
    Assignment_operatorContext *assignment_operator();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Func_exprContext : public ExpressionContext {
  public:
    Func_exprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *OPAREN();
    antlr4::tree::TerminalNode *CPAREN();
    Argument_listContext *argument_list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Int_litContext : public ExpressionContext {
  public:
    Int_litContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *INTLIT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Float_litContext : public ExpressionContext {
  public:
    Float_litContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *FLOATLIT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Obj_exprContext : public ExpressionContext {
  public:
    Obj_exprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *OBRACE();
    std::vector<Object_varContext *> object_var();
    Object_varContext* object_var(size_t i);
    antlr4::tree::TerminalNode *CBRACE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Bool_litContext : public ExpressionContext {
  public:
    Bool_litContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() = default;
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Builtin_typeContext : public TypeContext {
  public:
    Builtin_typeContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *KW_NULL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Unary_typeContext : public TypeContext {
  public:
    Unary_typeContext(TypeContext *ctx);

    Type_unary_operatorContext *type_unary_operator();
    TypeContext *type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Id_typeContext : public TypeContext {
  public:
    Id_typeContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Array_typeContext : public TypeContext {
  public:
    Array_typeContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *OBRACKET();
    TypeContext *type();
    antlr4::tree::TerminalNode *ELIPSIS();
    antlr4::tree::TerminalNode *CBRACKET();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Tuple_typeContext : public TypeContext {
  public:
    Tuple_typeContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *OBRACKET();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *CBRACKET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Paren_typeContext : public TypeContext {
  public:
    Paren_typeContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *OPAREN();
    TypeContext *type();
    antlr4::tree::TerminalNode *CPAREN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Binary_typeContext : public TypeContext {
  public:
    Binary_typeContext(TypeContext *ctx);

    PankoParser::TypeContext *lhs = nullptr;
    PankoParser::TypeContext *rhs = nullptr;
    Type_binary_operatorContext *type_binary_operator();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();
  TypeContext* type(int precedence);
  class  Typed_identifierContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    Typed_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Typed_identifierContext* typed_identifier();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Argument_listContext* argument_list();

  class  Var_declContext : public antlr4::ParserRuleContext {
  public:
    Var_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Typed_identifierContext *typed_identifier();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declContext* var_decl();

  class  If_statementContext : public antlr4::ParserRuleContext {
  public:
    PankoParser::BlockContext *final = nullptr;
    If_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IF();
    antlr4::tree::TerminalNode* IF(size_t i);
    std::vector<If_blockContext *> if_block();
    If_blockContext* if_block(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELSE();
    antlr4::tree::TerminalNode* ELSE(size_t i);
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_statementContext* if_statement();

  class  If_blockContext : public antlr4::ParserRuleContext {
  public:
    If_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CPAREN();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_blockContext* if_block();

  class  While_loopContext : public antlr4::ParserRuleContext {
  public:
    While_loopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *OPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CPAREN();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_loopContext* while_loop();

  class  Return_statementContext : public antlr4::ParserRuleContext {
  public:
    Return_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Return_statementContext* return_statement();

  class  Type_declContext : public antlr4::ParserRuleContext {
  public:
    PankoParser::Var_declContext *var_declContext = nullptr;
    std::vector<Var_declContext *> vars;
    PankoParser::Func_declContext *func_declContext = nullptr;
    std::vector<Func_declContext *> funcs;
    Type_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *OBRACE();
    antlr4::tree::TerminalNode *CBRACE();
    std::vector<Func_declContext *> func_decl();
    Func_declContext* func_decl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICLN();
    antlr4::tree::TerminalNode* SEMICLN(size_t i);
    std::vector<Var_declContext *> var_decl();
    Var_declContext* var_decl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_declContext* type_decl();

  class  Object_varContext : public antlr4::ParserRuleContext {
  public:
    Object_varContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *COLON();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Object_varContext* object_var();

  class  Binary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Binary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GTEQ();
    antlr4::tree::TerminalNode *LTEQ();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *XOR();
    antlr4::tree::TerminalNode *BITAND();
    antlr4::tree::TerminalNode *BITOR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Binary_operatorContext* binary_operator();

  class  Unary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Unary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BITNOT();
    antlr4::tree::TerminalNode *NOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_operatorContext* unary_operator();

  class  Type_unary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Type_unary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *MUL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_unary_operatorContext* type_unary_operator();

  class  Type_binary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Type_binary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BITAND();
    antlr4::tree::TerminalNode *BITOR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_binary_operatorContext* type_binary_operator();

  class  Assignment_operatorContext : public antlr4::ParserRuleContext {
  public:
    Assignment_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *ADDEQ();
    antlr4::tree::TerminalNode *SUBEQ();
    antlr4::tree::TerminalNode *MULEQ();
    antlr4::tree::TerminalNode *DIVEQ();
    antlr4::tree::TerminalNode *MODEQ();
    antlr4::tree::TerminalNode *XOREQ();
    antlr4::tree::TerminalNode *BITANDEQ();
    antlr4::tree::TerminalNode *BITOREQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_operatorContext* assignment_operator();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);
  bool typeSempred(TypeContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

