
// Generated from /home/jack/Documents/Panko/Panko.g4 by ANTLR 4.9.1


#include "PankoListener.h"
#include "PankoVisitor.h"

#include "PankoParser.h"


using namespace antlrcpp;
using namespace antlr4;

PankoParser::PankoParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PankoParser::~PankoParser() {
  delete _interpreter;
}

std::string PankoParser::getGrammarFileName() const {
  return "Panko.g4";
}

const std::vector<std::string>& PankoParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PankoParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

PankoParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::FileContext::MODULE() {
  return getToken(PankoParser::MODULE, 0);
}

tree::TerminalNode* PankoParser::FileContext::IDENTIFIER() {
  return getToken(PankoParser::IDENTIFIER, 0);
}

tree::TerminalNode* PankoParser::FileContext::SEMICLN() {
  return getToken(PankoParser::SEMICLN, 0);
}

tree::TerminalNode* PankoParser::FileContext::EOF() {
  return getToken(PankoParser::EOF, 0);
}

std::vector<PankoParser::StatementContext *> PankoParser::FileContext::statement() {
  return getRuleContexts<PankoParser::StatementContext>();
}

PankoParser::StatementContext* PankoParser::FileContext::statement(size_t i) {
  return getRuleContext<PankoParser::StatementContext>(i);
}


size_t PankoParser::FileContext::getRuleIndex() const {
  return PankoParser::RuleFile;
}

void PankoParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void PankoParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


antlrcpp::Any PankoParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::FileContext* PankoParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, PankoParser::RuleFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(40);
    match(PankoParser::MODULE);
    setState(41);
    match(PankoParser::IDENTIFIER);
    setState(42);
    match(PankoParser::SEMICLN);
    setState(44); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(43);
      statement();
      setState(46); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PankoParser::TYPE)
      | (1ULL << PankoParser::TRUE)
      | (1ULL << PankoParser::FALSE)
      | (1ULL << PankoParser::IF)
      | (1ULL << PankoParser::WHILE)
      | (1ULL << PankoParser::KW_NULL)
      | (1ULL << PankoParser::INT)
      | (1ULL << PankoParser::FLOAT)
      | (1ULL << PankoParser::RETURN)
      | (1ULL << PankoParser::BITNOT)
      | (1ULL << PankoParser::NOT)
      | (1ULL << PankoParser::OPAREN)
      | (1ULL << PankoParser::OBRACE)
      | (1ULL << PankoParser::OBRACKET)
      | (1ULL << PankoParser::IDENTIFIER)
      | (1ULL << PankoParser::INTLIT)
      | (1ULL << PankoParser::FLOATLIT))) != 0));
    setState(48);
    match(PankoParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

PankoParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::BlockContext::OBRACE() {
  return getToken(PankoParser::OBRACE, 0);
}

tree::TerminalNode* PankoParser::BlockContext::CBRACE() {
  return getToken(PankoParser::CBRACE, 0);
}

std::vector<PankoParser::StatementContext *> PankoParser::BlockContext::statement() {
  return getRuleContexts<PankoParser::StatementContext>();
}

PankoParser::StatementContext* PankoParser::BlockContext::statement(size_t i) {
  return getRuleContext<PankoParser::StatementContext>(i);
}


size_t PankoParser::BlockContext::getRuleIndex() const {
  return PankoParser::RuleBlock;
}

void PankoParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void PankoParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any PankoParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::BlockContext* PankoParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 2, PankoParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    match(PankoParser::OBRACE);
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PankoParser::TYPE)
      | (1ULL << PankoParser::TRUE)
      | (1ULL << PankoParser::FALSE)
      | (1ULL << PankoParser::IF)
      | (1ULL << PankoParser::WHILE)
      | (1ULL << PankoParser::KW_NULL)
      | (1ULL << PankoParser::INT)
      | (1ULL << PankoParser::FLOAT)
      | (1ULL << PankoParser::RETURN)
      | (1ULL << PankoParser::BITNOT)
      | (1ULL << PankoParser::NOT)
      | (1ULL << PankoParser::OPAREN)
      | (1ULL << PankoParser::OBRACE)
      | (1ULL << PankoParser::OBRACKET)
      | (1ULL << PankoParser::IDENTIFIER)
      | (1ULL << PankoParser::INTLIT)
      | (1ULL << PankoParser::FLOATLIT))) != 0)) {
      setState(51);
      statement();
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(57);
    match(PankoParser::CBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declContext ------------------------------------------------------------------

PankoParser::Func_declContext::Func_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::Func_declContext::OPAREN() {
  return getToken(PankoParser::OPAREN, 0);
}

tree::TerminalNode* PankoParser::Func_declContext::CPAREN() {
  return getToken(PankoParser::CPAREN, 0);
}

PankoParser::BlockContext* PankoParser::Func_declContext::block() {
  return getRuleContext<PankoParser::BlockContext>(0);
}

std::vector<PankoParser::Typed_identifierContext *> PankoParser::Func_declContext::typed_identifier() {
  return getRuleContexts<PankoParser::Typed_identifierContext>();
}

PankoParser::Typed_identifierContext* PankoParser::Func_declContext::typed_identifier(size_t i) {
  return getRuleContext<PankoParser::Typed_identifierContext>(i);
}

std::vector<tree::TerminalNode *> PankoParser::Func_declContext::COMMA() {
  return getTokens(PankoParser::COMMA);
}

tree::TerminalNode* PankoParser::Func_declContext::COMMA(size_t i) {
  return getToken(PankoParser::COMMA, i);
}


size_t PankoParser::Func_declContext::getRuleIndex() const {
  return PankoParser::RuleFunc_decl;
}

void PankoParser::Func_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_decl(this);
}

void PankoParser::Func_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_decl(this);
}


antlrcpp::Any PankoParser::Func_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitFunc_decl(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::Func_declContext* PankoParser::func_decl() {
  Func_declContext *_localctx = _tracker.createInstance<Func_declContext>(_ctx, getState());
  enterRule(_localctx, 4, PankoParser::RuleFunc_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    dynamic_cast<Func_declContext *>(_localctx)->ret_type = typed_identifier();
    setState(60);
    match(PankoParser::OPAREN);
    setState(69);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PankoParser::KW_NULL)
      | (1ULL << PankoParser::INT)
      | (1ULL << PankoParser::FLOAT)
      | (1ULL << PankoParser::OPAREN)
      | (1ULL << PankoParser::OBRACKET)
      | (1ULL << PankoParser::IDENTIFIER))) != 0)) {
      setState(61);
      dynamic_cast<Func_declContext *>(_localctx)->typed_identifierContext = typed_identifier();
      dynamic_cast<Func_declContext *>(_localctx)->params.push_back(dynamic_cast<Func_declContext *>(_localctx)->typed_identifierContext);
      setState(66);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PankoParser::COMMA) {
        setState(62);
        match(PankoParser::COMMA);
        setState(63);
        dynamic_cast<Func_declContext *>(_localctx)->typed_identifierContext = typed_identifier();
        dynamic_cast<Func_declContext *>(_localctx)->params.push_back(dynamic_cast<Func_declContext *>(_localctx)->typed_identifierContext);
        setState(68);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(71);
    match(PankoParser::CPAREN);
    setState(72);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

PankoParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PankoParser::StatementContext::getRuleIndex() const {
  return PankoParser::RuleStatement;
}

void PankoParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Semi_statementContext ------------------------------------------------------------------

PankoParser::Var_declContext* PankoParser::Semi_statementContext::var_decl() {
  return getRuleContext<PankoParser::Var_declContext>(0);
}

tree::TerminalNode* PankoParser::Semi_statementContext::SEMICLN() {
  return getToken(PankoParser::SEMICLN, 0);
}

PankoParser::Return_statementContext* PankoParser::Semi_statementContext::return_statement() {
  return getRuleContext<PankoParser::Return_statementContext>(0);
}

PankoParser::ExpressionContext* PankoParser::Semi_statementContext::expression() {
  return getRuleContext<PankoParser::ExpressionContext>(0);
}

PankoParser::Semi_statementContext::Semi_statementContext(StatementContext *ctx) { copyFrom(ctx); }

void PankoParser::Semi_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSemi_statement(this);
}
void PankoParser::Semi_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSemi_statement(this);
}

antlrcpp::Any PankoParser::Semi_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitSemi_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Block_statementContext ------------------------------------------------------------------

PankoParser::Func_declContext* PankoParser::Block_statementContext::func_decl() {
  return getRuleContext<PankoParser::Func_declContext>(0);
}

PankoParser::Type_declContext* PankoParser::Block_statementContext::type_decl() {
  return getRuleContext<PankoParser::Type_declContext>(0);
}

PankoParser::If_statementContext* PankoParser::Block_statementContext::if_statement() {
  return getRuleContext<PankoParser::If_statementContext>(0);
}

PankoParser::While_loopContext* PankoParser::Block_statementContext::while_loop() {
  return getRuleContext<PankoParser::While_loopContext>(0);
}

PankoParser::BlockContext* PankoParser::Block_statementContext::block() {
  return getRuleContext<PankoParser::BlockContext>(0);
}

PankoParser::Block_statementContext::Block_statementContext(StatementContext *ctx) { copyFrom(ctx); }

void PankoParser::Block_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock_statement(this);
}
void PankoParser::Block_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock_statement(this);
}

antlrcpp::Any PankoParser::Block_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitBlock_statement(this);
  else
    return visitor->visitChildren(this);
}
PankoParser::StatementContext* PankoParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 6, PankoParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(88);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PankoParser::Block_statementContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(74);
      func_decl();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PankoParser::Semi_statementContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(75);
      var_decl();
      setState(76);
      match(PankoParser::SEMICLN);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PankoParser::Block_statementContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(78);
      type_decl();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PankoParser::Block_statementContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(79);
      if_statement();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PankoParser::Block_statementContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(80);
      while_loop();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PankoParser::Block_statementContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(81);
      block();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PankoParser::Semi_statementContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(82);
      return_statement();
      setState(83);
      match(PankoParser::SEMICLN);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<PankoParser::Semi_statementContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(85);
      expression(0);
      setState(86);
      match(PankoParser::SEMICLN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

PankoParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PankoParser::ExpressionContext::getRuleIndex() const {
  return PankoParser::RuleExpression;
}

void PankoParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Paren_exprContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Paren_exprContext::OPAREN() {
  return getToken(PankoParser::OPAREN, 0);
}

PankoParser::ExpressionContext* PankoParser::Paren_exprContext::expression() {
  return getRuleContext<PankoParser::ExpressionContext>(0);
}

tree::TerminalNode* PankoParser::Paren_exprContext::CPAREN() {
  return getToken(PankoParser::CPAREN, 0);
}

PankoParser::Paren_exprContext::Paren_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Paren_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParen_expr(this);
}
void PankoParser::Paren_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParen_expr(this);
}

antlrcpp::Any PankoParser::Paren_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitParen_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Access_exprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> PankoParser::Access_exprContext::IDENTIFIER() {
  return getTokens(PankoParser::IDENTIFIER);
}

tree::TerminalNode* PankoParser::Access_exprContext::IDENTIFIER(size_t i) {
  return getToken(PankoParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> PankoParser::Access_exprContext::PERIOD() {
  return getTokens(PankoParser::PERIOD);
}

tree::TerminalNode* PankoParser::Access_exprContext::PERIOD(size_t i) {
  return getToken(PankoParser::PERIOD, i);
}

PankoParser::Access_exprContext::Access_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Access_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccess_expr(this);
}
void PankoParser::Access_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccess_expr(this);
}

antlrcpp::Any PankoParser::Access_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitAccess_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Complex_assignmentContext ------------------------------------------------------------------

PankoParser::ExpressionContext* PankoParser::Complex_assignmentContext::expression() {
  return getRuleContext<PankoParser::ExpressionContext>(0);
}

tree::TerminalNode* PankoParser::Complex_assignmentContext::INC() {
  return getToken(PankoParser::INC, 0);
}

tree::TerminalNode* PankoParser::Complex_assignmentContext::DEC() {
  return getToken(PankoParser::DEC, 0);
}

PankoParser::Complex_assignmentContext::Complex_assignmentContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Complex_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComplex_assignment(this);
}
void PankoParser::Complex_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComplex_assignment(this);
}

antlrcpp::Any PankoParser::Complex_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitComplex_assignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Binary_exprContext ------------------------------------------------------------------

PankoParser::Binary_operatorContext* PankoParser::Binary_exprContext::binary_operator() {
  return getRuleContext<PankoParser::Binary_operatorContext>(0);
}

std::vector<PankoParser::ExpressionContext *> PankoParser::Binary_exprContext::expression() {
  return getRuleContexts<PankoParser::ExpressionContext>();
}

PankoParser::ExpressionContext* PankoParser::Binary_exprContext::expression(size_t i) {
  return getRuleContext<PankoParser::ExpressionContext>(i);
}

PankoParser::Binary_exprContext::Binary_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Binary_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_expr(this);
}
void PankoParser::Binary_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_expr(this);
}

antlrcpp::Any PankoParser::Binary_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitBinary_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Id_exprContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Id_exprContext::IDENTIFIER() {
  return getToken(PankoParser::IDENTIFIER, 0);
}

PankoParser::Id_exprContext::Id_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Id_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId_expr(this);
}
void PankoParser::Id_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId_expr(this);
}

antlrcpp::Any PankoParser::Id_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitId_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Simple_assignmentContext ------------------------------------------------------------------

PankoParser::Assignment_operatorContext* PankoParser::Simple_assignmentContext::assignment_operator() {
  return getRuleContext<PankoParser::Assignment_operatorContext>(0);
}

std::vector<PankoParser::ExpressionContext *> PankoParser::Simple_assignmentContext::expression() {
  return getRuleContexts<PankoParser::ExpressionContext>();
}

PankoParser::ExpressionContext* PankoParser::Simple_assignmentContext::expression(size_t i) {
  return getRuleContext<PankoParser::ExpressionContext>(i);
}

PankoParser::Simple_assignmentContext::Simple_assignmentContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Simple_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_assignment(this);
}
void PankoParser::Simple_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_assignment(this);
}

antlrcpp::Any PankoParser::Simple_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitSimple_assignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Func_exprContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Func_exprContext::IDENTIFIER() {
  return getToken(PankoParser::IDENTIFIER, 0);
}

tree::TerminalNode* PankoParser::Func_exprContext::OPAREN() {
  return getToken(PankoParser::OPAREN, 0);
}

tree::TerminalNode* PankoParser::Func_exprContext::CPAREN() {
  return getToken(PankoParser::CPAREN, 0);
}

PankoParser::Argument_listContext* PankoParser::Func_exprContext::argument_list() {
  return getRuleContext<PankoParser::Argument_listContext>(0);
}

PankoParser::Func_exprContext::Func_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Func_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_expr(this);
}
void PankoParser::Func_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_expr(this);
}

antlrcpp::Any PankoParser::Func_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitFunc_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Obj_exprContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Obj_exprContext::OBRACE() {
  return getToken(PankoParser::OBRACE, 0);
}

std::vector<PankoParser::Object_varContext *> PankoParser::Obj_exprContext::object_var() {
  return getRuleContexts<PankoParser::Object_varContext>();
}

PankoParser::Object_varContext* PankoParser::Obj_exprContext::object_var(size_t i) {
  return getRuleContext<PankoParser::Object_varContext>(i);
}

tree::TerminalNode* PankoParser::Obj_exprContext::CBRACE() {
  return getToken(PankoParser::CBRACE, 0);
}

std::vector<tree::TerminalNode *> PankoParser::Obj_exprContext::COMMA() {
  return getTokens(PankoParser::COMMA);
}

tree::TerminalNode* PankoParser::Obj_exprContext::COMMA(size_t i) {
  return getToken(PankoParser::COMMA, i);
}

PankoParser::Obj_exprContext::Obj_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Obj_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObj_expr(this);
}
void PankoParser::Obj_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObj_expr(this);
}

antlrcpp::Any PankoParser::Obj_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitObj_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Bool_litContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Bool_litContext::TRUE() {
  return getToken(PankoParser::TRUE, 0);
}

tree::TerminalNode* PankoParser::Bool_litContext::FALSE() {
  return getToken(PankoParser::FALSE, 0);
}

PankoParser::Bool_litContext::Bool_litContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Bool_litContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBool_lit(this);
}
void PankoParser::Bool_litContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBool_lit(this);
}

antlrcpp::Any PankoParser::Bool_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitBool_lit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Array_exprContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Array_exprContext::OBRACKET() {
  return getToken(PankoParser::OBRACKET, 0);
}

std::vector<PankoParser::ExpressionContext *> PankoParser::Array_exprContext::expression() {
  return getRuleContexts<PankoParser::ExpressionContext>();
}

PankoParser::ExpressionContext* PankoParser::Array_exprContext::expression(size_t i) {
  return getRuleContext<PankoParser::ExpressionContext>(i);
}

tree::TerminalNode* PankoParser::Array_exprContext::CBRACKET() {
  return getToken(PankoParser::CBRACKET, 0);
}

std::vector<tree::TerminalNode *> PankoParser::Array_exprContext::COMMA() {
  return getTokens(PankoParser::COMMA);
}

tree::TerminalNode* PankoParser::Array_exprContext::COMMA(size_t i) {
  return getToken(PankoParser::COMMA, i);
}

PankoParser::Array_exprContext::Array_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Array_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_expr(this);
}
void PankoParser::Array_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_expr(this);
}

antlrcpp::Any PankoParser::Array_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitArray_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Unary_exprContext ------------------------------------------------------------------

PankoParser::Unary_operatorContext* PankoParser::Unary_exprContext::unary_operator() {
  return getRuleContext<PankoParser::Unary_operatorContext>(0);
}

PankoParser::ExpressionContext* PankoParser::Unary_exprContext::expression() {
  return getRuleContext<PankoParser::ExpressionContext>(0);
}

PankoParser::Unary_exprContext::Unary_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Unary_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expr(this);
}
void PankoParser::Unary_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expr(this);
}

antlrcpp::Any PankoParser::Unary_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitUnary_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Array_access_exprContext ------------------------------------------------------------------

PankoParser::ExpressionContext* PankoParser::Array_access_exprContext::expression() {
  return getRuleContext<PankoParser::ExpressionContext>(0);
}

tree::TerminalNode* PankoParser::Array_access_exprContext::OBRACKET() {
  return getToken(PankoParser::OBRACKET, 0);
}

tree::TerminalNode* PankoParser::Array_access_exprContext::INTLIT() {
  return getToken(PankoParser::INTLIT, 0);
}

tree::TerminalNode* PankoParser::Array_access_exprContext::CBRACKET() {
  return getToken(PankoParser::CBRACKET, 0);
}

PankoParser::Array_access_exprContext::Array_access_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Array_access_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_access_expr(this);
}
void PankoParser::Array_access_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_access_expr(this);
}

antlrcpp::Any PankoParser::Array_access_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitArray_access_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Int_litContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Int_litContext::INTLIT() {
  return getToken(PankoParser::INTLIT, 0);
}

PankoParser::Int_litContext::Int_litContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Int_litContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt_lit(this);
}
void PankoParser::Int_litContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt_lit(this);
}

antlrcpp::Any PankoParser::Int_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitInt_lit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Float_litContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Float_litContext::FLOATLIT() {
  return getToken(PankoParser::FLOATLIT, 0);
}

PankoParser::Float_litContext::Float_litContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Float_litContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloat_lit(this);
}
void PankoParser::Float_litContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloat_lit(this);
}

antlrcpp::Any PankoParser::Float_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitFloat_lit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Null_litContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Null_litContext::KW_NULL() {
  return getToken(PankoParser::KW_NULL, 0);
}

PankoParser::Null_litContext::Null_litContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PankoParser::Null_litContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNull_lit(this);
}
void PankoParser::Null_litContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNull_lit(this);
}

antlrcpp::Any PankoParser::Null_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitNull_lit(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::ExpressionContext* PankoParser::expression() {
   return expression(0);
}

PankoParser::ExpressionContext* PankoParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PankoParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  PankoParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, PankoParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(140);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Paren_exprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(91);
      match(PankoParser::OPAREN);
      setState(92);
      expression(0);
      setState(93);
      match(PankoParser::CPAREN);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Unary_exprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(95);
      unary_operator();
      setState(96);
      expression(13);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Func_exprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(98);
      match(PankoParser::IDENTIFIER);
      setState(99);
      match(PankoParser::OPAREN);
      setState(101);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PankoParser::TRUE)
        | (1ULL << PankoParser::FALSE)
        | (1ULL << PankoParser::KW_NULL)
        | (1ULL << PankoParser::BITNOT)
        | (1ULL << PankoParser::NOT)
        | (1ULL << PankoParser::OPAREN)
        | (1ULL << PankoParser::OBRACE)
        | (1ULL << PankoParser::OBRACKET)
        | (1ULL << PankoParser::IDENTIFIER)
        | (1ULL << PankoParser::INTLIT)
        | (1ULL << PankoParser::FLOATLIT))) != 0)) {
        setState(100);
        argument_list();
      }
      setState(103);
      match(PankoParser::CPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Access_exprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(104);
      dynamic_cast<Access_exprContext *>(_localctx)->initial = match(PankoParser::IDENTIFIER);
      setState(107); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(105);
                match(PankoParser::PERIOD);
                setState(106);
                dynamic_cast<Access_exprContext *>(_localctx)->identifierToken = match(PankoParser::IDENTIFIER);
                dynamic_cast<Access_exprContext *>(_localctx)->accessors.push_back(dynamic_cast<Access_exprContext *>(_localctx)->identifierToken);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(109); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Obj_exprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(111);
      match(PankoParser::OBRACE);
      setState(117);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(112);
          object_var();
          setState(113);
          match(PankoParser::COMMA); 
        }
        setState(119);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      }
      setState(120);
      object_var();
      setState(121);
      match(PankoParser::CBRACE);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Array_exprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(123);
      match(PankoParser::OBRACKET);
      setState(129);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(124);
          expression(0);
          setState(125);
          match(PankoParser::COMMA); 
        }
        setState(131);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      }
      setState(132);
      expression(0);
      setState(133);
      match(PankoParser::CBRACKET);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<Id_exprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(135);
      match(PankoParser::IDENTIFIER);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<Int_litContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(136);
      match(PankoParser::INTLIT);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<Float_litContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(137);
      match(PankoParser::FLOATLIT);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<Bool_litContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(138);
      _la = _input->LA(1);
      if (!(_la == PankoParser::TRUE

      || _la == PankoParser::FALSE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<Null_litContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(139);
      match(PankoParser::KW_NULL);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(158);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(156);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Binary_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(142);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(143);
          binary_operator();
          setState(144);
          dynamic_cast<Binary_exprContext *>(_localctx)->rhs = expression(15);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Simple_assignmentContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(146);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(147);
          assignment_operator();
          setState(148);
          dynamic_cast<Simple_assignmentContext *>(_localctx)->rhs = expression(12);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Complex_assignmentContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(150);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(151);
          dynamic_cast<Complex_assignmentContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == PankoParser::INC

          || _la == PankoParser::DEC)) {
            dynamic_cast<Complex_assignmentContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Array_access_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(152);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(153);
          match(PankoParser::OBRACKET);
          setState(154);
          match(PankoParser::INTLIT);
          setState(155);
          match(PankoParser::CBRACKET);
          break;
        }

        default:
          break;
        } 
      }
      setState(160);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

PankoParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PankoParser::TypeContext::getRuleIndex() const {
  return PankoParser::RuleType;
}

void PankoParser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Builtin_typeContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Builtin_typeContext::INT() {
  return getToken(PankoParser::INT, 0);
}

tree::TerminalNode* PankoParser::Builtin_typeContext::FLOAT() {
  return getToken(PankoParser::FLOAT, 0);
}

tree::TerminalNode* PankoParser::Builtin_typeContext::KW_NULL() {
  return getToken(PankoParser::KW_NULL, 0);
}

PankoParser::Builtin_typeContext::Builtin_typeContext(TypeContext *ctx) { copyFrom(ctx); }

void PankoParser::Builtin_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBuiltin_type(this);
}
void PankoParser::Builtin_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBuiltin_type(this);
}

antlrcpp::Any PankoParser::Builtin_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitBuiltin_type(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Unary_typeContext ------------------------------------------------------------------

PankoParser::TypeContext* PankoParser::Unary_typeContext::type() {
  return getRuleContext<PankoParser::TypeContext>(0);
}

PankoParser::Type_unary_operatorContext* PankoParser::Unary_typeContext::type_unary_operator() {
  return getRuleContext<PankoParser::Type_unary_operatorContext>(0);
}

PankoParser::Unary_typeContext::Unary_typeContext(TypeContext *ctx) { copyFrom(ctx); }

void PankoParser::Unary_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_type(this);
}
void PankoParser::Unary_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_type(this);
}

antlrcpp::Any PankoParser::Unary_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitUnary_type(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Id_typeContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Id_typeContext::IDENTIFIER() {
  return getToken(PankoParser::IDENTIFIER, 0);
}

PankoParser::Id_typeContext::Id_typeContext(TypeContext *ctx) { copyFrom(ctx); }

void PankoParser::Id_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId_type(this);
}
void PankoParser::Id_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId_type(this);
}

antlrcpp::Any PankoParser::Id_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitId_type(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Array_typeContext ------------------------------------------------------------------

PankoParser::TypeContext* PankoParser::Array_typeContext::type() {
  return getRuleContext<PankoParser::TypeContext>(0);
}

tree::TerminalNode* PankoParser::Array_typeContext::ELIPSIS() {
  return getToken(PankoParser::ELIPSIS, 0);
}

PankoParser::Array_typeContext::Array_typeContext(TypeContext *ctx) { copyFrom(ctx); }

void PankoParser::Array_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_type(this);
}
void PankoParser::Array_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_type(this);
}

antlrcpp::Any PankoParser::Array_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitArray_type(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Tuple_typeContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Tuple_typeContext::OBRACKET() {
  return getToken(PankoParser::OBRACKET, 0);
}

std::vector<PankoParser::TypeContext *> PankoParser::Tuple_typeContext::type() {
  return getRuleContexts<PankoParser::TypeContext>();
}

PankoParser::TypeContext* PankoParser::Tuple_typeContext::type(size_t i) {
  return getRuleContext<PankoParser::TypeContext>(i);
}

tree::TerminalNode* PankoParser::Tuple_typeContext::CBRACKET() {
  return getToken(PankoParser::CBRACKET, 0);
}

std::vector<tree::TerminalNode *> PankoParser::Tuple_typeContext::COMMA() {
  return getTokens(PankoParser::COMMA);
}

tree::TerminalNode* PankoParser::Tuple_typeContext::COMMA(size_t i) {
  return getToken(PankoParser::COMMA, i);
}

PankoParser::Tuple_typeContext::Tuple_typeContext(TypeContext *ctx) { copyFrom(ctx); }

void PankoParser::Tuple_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTuple_type(this);
}
void PankoParser::Tuple_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTuple_type(this);
}

antlrcpp::Any PankoParser::Tuple_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitTuple_type(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Paren_typeContext ------------------------------------------------------------------

tree::TerminalNode* PankoParser::Paren_typeContext::OPAREN() {
  return getToken(PankoParser::OPAREN, 0);
}

PankoParser::TypeContext* PankoParser::Paren_typeContext::type() {
  return getRuleContext<PankoParser::TypeContext>(0);
}

tree::TerminalNode* PankoParser::Paren_typeContext::CPAREN() {
  return getToken(PankoParser::CPAREN, 0);
}

PankoParser::Paren_typeContext::Paren_typeContext(TypeContext *ctx) { copyFrom(ctx); }

void PankoParser::Paren_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParen_type(this);
}
void PankoParser::Paren_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParen_type(this);
}

antlrcpp::Any PankoParser::Paren_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitParen_type(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Binary_typeContext ------------------------------------------------------------------

PankoParser::Type_binary_operatorContext* PankoParser::Binary_typeContext::type_binary_operator() {
  return getRuleContext<PankoParser::Type_binary_operatorContext>(0);
}

std::vector<PankoParser::TypeContext *> PankoParser::Binary_typeContext::type() {
  return getRuleContexts<PankoParser::TypeContext>();
}

PankoParser::TypeContext* PankoParser::Binary_typeContext::type(size_t i) {
  return getRuleContext<PankoParser::TypeContext>(i);
}

PankoParser::Binary_typeContext::Binary_typeContext(TypeContext *ctx) { copyFrom(ctx); }

void PankoParser::Binary_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_type(this);
}
void PankoParser::Binary_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_type(this);
}

antlrcpp::Any PankoParser::Binary_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitBinary_type(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::TypeContext* PankoParser::type() {
   return type(0);
}

PankoParser::TypeContext* PankoParser::type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PankoParser::TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, parentState);
  PankoParser::TypeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, PankoParser::RuleType, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(179);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PankoParser::OPAREN: {
        _localctx = _tracker.createInstance<Paren_typeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(162);
        match(PankoParser::OPAREN);
        setState(163);
        type(0);
        setState(164);
        match(PankoParser::CPAREN);
        break;
      }

      case PankoParser::OBRACKET: {
        _localctx = _tracker.createInstance<Tuple_typeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(166);
        match(PankoParser::OBRACKET);
        setState(167);
        type(0);
        setState(172);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PankoParser::COMMA) {
          setState(168);
          match(PankoParser::COMMA);
          setState(169);
          type(0);
          setState(174);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(175);
        match(PankoParser::CBRACKET);
        break;
      }

      case PankoParser::KW_NULL:
      case PankoParser::INT:
      case PankoParser::FLOAT: {
        _localctx = _tracker.createInstance<Builtin_typeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(177);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PankoParser::KW_NULL)
          | (1ULL << PankoParser::INT)
          | (1ULL << PankoParser::FLOAT))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case PankoParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<Id_typeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(178);
        match(PankoParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(191);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(189);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Binary_typeContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(181);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(182);
          type_binary_operator();
          setState(183);
          dynamic_cast<Binary_typeContext *>(_localctx)->rhs = type(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Unary_typeContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(185);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(186);
          type_unary_operator();
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Array_typeContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(187);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(188);
          match(PankoParser::ELIPSIS);
          break;
        }

        default:
          break;
        } 
      }
      setState(193);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Typed_identifierContext ------------------------------------------------------------------

PankoParser::Typed_identifierContext::Typed_identifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PankoParser::TypeContext* PankoParser::Typed_identifierContext::type() {
  return getRuleContext<PankoParser::TypeContext>(0);
}

tree::TerminalNode* PankoParser::Typed_identifierContext::IDENTIFIER() {
  return getToken(PankoParser::IDENTIFIER, 0);
}


size_t PankoParser::Typed_identifierContext::getRuleIndex() const {
  return PankoParser::RuleTyped_identifier;
}

void PankoParser::Typed_identifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyped_identifier(this);
}

void PankoParser::Typed_identifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyped_identifier(this);
}


antlrcpp::Any PankoParser::Typed_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitTyped_identifier(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::Typed_identifierContext* PankoParser::typed_identifier() {
  Typed_identifierContext *_localctx = _tracker.createInstance<Typed_identifierContext>(_ctx, getState());
  enterRule(_localctx, 12, PankoParser::RuleTyped_identifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    type(0);
    setState(195);
    dynamic_cast<Typed_identifierContext *>(_localctx)->id = match(PankoParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

PankoParser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PankoParser::ExpressionContext *> PankoParser::Argument_listContext::expression() {
  return getRuleContexts<PankoParser::ExpressionContext>();
}

PankoParser::ExpressionContext* PankoParser::Argument_listContext::expression(size_t i) {
  return getRuleContext<PankoParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PankoParser::Argument_listContext::COMMA() {
  return getTokens(PankoParser::COMMA);
}

tree::TerminalNode* PankoParser::Argument_listContext::COMMA(size_t i) {
  return getToken(PankoParser::COMMA, i);
}


size_t PankoParser::Argument_listContext::getRuleIndex() const {
  return PankoParser::RuleArgument_list;
}

void PankoParser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void PankoParser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}


antlrcpp::Any PankoParser::Argument_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitArgument_list(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::Argument_listContext* PankoParser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 14, PankoParser::RuleArgument_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(197);
    expression(0);
    setState(202);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PankoParser::COMMA) {
      setState(198);
      match(PankoParser::COMMA);
      setState(199);
      expression(0);
      setState(204);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declContext ------------------------------------------------------------------

PankoParser::Var_declContext::Var_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PankoParser::Typed_identifierContext* PankoParser::Var_declContext::typed_identifier() {
  return getRuleContext<PankoParser::Typed_identifierContext>(0);
}

tree::TerminalNode* PankoParser::Var_declContext::ASSIGN() {
  return getToken(PankoParser::ASSIGN, 0);
}

PankoParser::ExpressionContext* PankoParser::Var_declContext::expression() {
  return getRuleContext<PankoParser::ExpressionContext>(0);
}


size_t PankoParser::Var_declContext::getRuleIndex() const {
  return PankoParser::RuleVar_decl;
}

void PankoParser::Var_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_decl(this);
}

void PankoParser::Var_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_decl(this);
}


antlrcpp::Any PankoParser::Var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitVar_decl(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::Var_declContext* PankoParser::var_decl() {
  Var_declContext *_localctx = _tracker.createInstance<Var_declContext>(_ctx, getState());
  enterRule(_localctx, 16, PankoParser::RuleVar_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    typed_identifier();
    setState(208);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PankoParser::ASSIGN) {
      setState(206);
      match(PankoParser::ASSIGN);
      setState(207);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

PankoParser::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PankoParser::If_statementContext::IF() {
  return getTokens(PankoParser::IF);
}

tree::TerminalNode* PankoParser::If_statementContext::IF(size_t i) {
  return getToken(PankoParser::IF, i);
}

std::vector<PankoParser::If_blockContext *> PankoParser::If_statementContext::if_block() {
  return getRuleContexts<PankoParser::If_blockContext>();
}

PankoParser::If_blockContext* PankoParser::If_statementContext::if_block(size_t i) {
  return getRuleContext<PankoParser::If_blockContext>(i);
}

std::vector<tree::TerminalNode *> PankoParser::If_statementContext::ELSE() {
  return getTokens(PankoParser::ELSE);
}

tree::TerminalNode* PankoParser::If_statementContext::ELSE(size_t i) {
  return getToken(PankoParser::ELSE, i);
}

PankoParser::BlockContext* PankoParser::If_statementContext::block() {
  return getRuleContext<PankoParser::BlockContext>(0);
}


size_t PankoParser::If_statementContext::getRuleIndex() const {
  return PankoParser::RuleIf_statement;
}

void PankoParser::If_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_statement(this);
}

void PankoParser::If_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_statement(this);
}


antlrcpp::Any PankoParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::If_statementContext* PankoParser::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 18, PankoParser::RuleIf_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(PankoParser::IF);
    setState(211);
    if_block();
    setState(217);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(212);
        match(PankoParser::ELSE);
        setState(213);
        match(PankoParser::IF);
        setState(214);
        if_block(); 
      }
      setState(219);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
    setState(222);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PankoParser::ELSE) {
      setState(220);
      match(PankoParser::ELSE);
      setState(221);
      dynamic_cast<If_statementContext *>(_localctx)->final = block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_blockContext ------------------------------------------------------------------

PankoParser::If_blockContext::If_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::If_blockContext::OPAREN() {
  return getToken(PankoParser::OPAREN, 0);
}

PankoParser::ExpressionContext* PankoParser::If_blockContext::expression() {
  return getRuleContext<PankoParser::ExpressionContext>(0);
}

tree::TerminalNode* PankoParser::If_blockContext::CPAREN() {
  return getToken(PankoParser::CPAREN, 0);
}

PankoParser::BlockContext* PankoParser::If_blockContext::block() {
  return getRuleContext<PankoParser::BlockContext>(0);
}


size_t PankoParser::If_blockContext::getRuleIndex() const {
  return PankoParser::RuleIf_block;
}

void PankoParser::If_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_block(this);
}

void PankoParser::If_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_block(this);
}


antlrcpp::Any PankoParser::If_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitIf_block(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::If_blockContext* PankoParser::if_block() {
  If_blockContext *_localctx = _tracker.createInstance<If_blockContext>(_ctx, getState());
  enterRule(_localctx, 20, PankoParser::RuleIf_block);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    match(PankoParser::OPAREN);
    setState(225);
    expression(0);
    setState(226);
    match(PankoParser::CPAREN);
    setState(227);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_loopContext ------------------------------------------------------------------

PankoParser::While_loopContext::While_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::While_loopContext::WHILE() {
  return getToken(PankoParser::WHILE, 0);
}

tree::TerminalNode* PankoParser::While_loopContext::OPAREN() {
  return getToken(PankoParser::OPAREN, 0);
}

PankoParser::ExpressionContext* PankoParser::While_loopContext::expression() {
  return getRuleContext<PankoParser::ExpressionContext>(0);
}

tree::TerminalNode* PankoParser::While_loopContext::CPAREN() {
  return getToken(PankoParser::CPAREN, 0);
}

PankoParser::BlockContext* PankoParser::While_loopContext::block() {
  return getRuleContext<PankoParser::BlockContext>(0);
}


size_t PankoParser::While_loopContext::getRuleIndex() const {
  return PankoParser::RuleWhile_loop;
}

void PankoParser::While_loopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_loop(this);
}

void PankoParser::While_loopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_loop(this);
}


antlrcpp::Any PankoParser::While_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitWhile_loop(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::While_loopContext* PankoParser::while_loop() {
  While_loopContext *_localctx = _tracker.createInstance<While_loopContext>(_ctx, getState());
  enterRule(_localctx, 22, PankoParser::RuleWhile_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    match(PankoParser::WHILE);
    setState(230);
    match(PankoParser::OPAREN);
    setState(231);
    expression(0);
    setState(232);
    match(PankoParser::CPAREN);
    setState(233);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

PankoParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::Return_statementContext::RETURN() {
  return getToken(PankoParser::RETURN, 0);
}

PankoParser::ExpressionContext* PankoParser::Return_statementContext::expression() {
  return getRuleContext<PankoParser::ExpressionContext>(0);
}


size_t PankoParser::Return_statementContext::getRuleIndex() const {
  return PankoParser::RuleReturn_statement;
}

void PankoParser::Return_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_statement(this);
}

void PankoParser::Return_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_statement(this);
}


antlrcpp::Any PankoParser::Return_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitReturn_statement(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::Return_statementContext* PankoParser::return_statement() {
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 24, PankoParser::RuleReturn_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    match(PankoParser::RETURN);
    setState(236);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_declContext ------------------------------------------------------------------

PankoParser::Type_declContext::Type_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::Type_declContext::TYPE() {
  return getToken(PankoParser::TYPE, 0);
}

tree::TerminalNode* PankoParser::Type_declContext::IDENTIFIER() {
  return getToken(PankoParser::IDENTIFIER, 0);
}

tree::TerminalNode* PankoParser::Type_declContext::OBRACE() {
  return getToken(PankoParser::OBRACE, 0);
}

tree::TerminalNode* PankoParser::Type_declContext::CBRACE() {
  return getToken(PankoParser::CBRACE, 0);
}

std::vector<PankoParser::Func_declContext *> PankoParser::Type_declContext::func_decl() {
  return getRuleContexts<PankoParser::Func_declContext>();
}

PankoParser::Func_declContext* PankoParser::Type_declContext::func_decl(size_t i) {
  return getRuleContext<PankoParser::Func_declContext>(i);
}

std::vector<tree::TerminalNode *> PankoParser::Type_declContext::SEMICLN() {
  return getTokens(PankoParser::SEMICLN);
}

tree::TerminalNode* PankoParser::Type_declContext::SEMICLN(size_t i) {
  return getToken(PankoParser::SEMICLN, i);
}

std::vector<PankoParser::Var_declContext *> PankoParser::Type_declContext::var_decl() {
  return getRuleContexts<PankoParser::Var_declContext>();
}

PankoParser::Var_declContext* PankoParser::Type_declContext::var_decl(size_t i) {
  return getRuleContext<PankoParser::Var_declContext>(i);
}


size_t PankoParser::Type_declContext::getRuleIndex() const {
  return PankoParser::RuleType_decl;
}

void PankoParser::Type_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_decl(this);
}

void PankoParser::Type_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_decl(this);
}


antlrcpp::Any PankoParser::Type_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitType_decl(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::Type_declContext* PankoParser::type_decl() {
  Type_declContext *_localctx = _tracker.createInstance<Type_declContext>(_ctx, getState());
  enterRule(_localctx, 26, PankoParser::RuleType_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(PankoParser::TYPE);
    setState(239);
    match(PankoParser::IDENTIFIER);
    setState(240);
    match(PankoParser::OBRACE);
    setState(245); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(245);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
      case 1: {
        setState(241);
        dynamic_cast<Type_declContext *>(_localctx)->var_declContext = var_decl();
        dynamic_cast<Type_declContext *>(_localctx)->vars.push_back(dynamic_cast<Type_declContext *>(_localctx)->var_declContext);
        setState(242);
        match(PankoParser::SEMICLN);
        break;
      }

      case 2: {
        setState(244);
        dynamic_cast<Type_declContext *>(_localctx)->func_declContext = func_decl();
        dynamic_cast<Type_declContext *>(_localctx)->funcs.push_back(dynamic_cast<Type_declContext *>(_localctx)->func_declContext);
        break;
      }

      default:
        break;
      }
      setState(247); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PankoParser::KW_NULL)
      | (1ULL << PankoParser::INT)
      | (1ULL << PankoParser::FLOAT)
      | (1ULL << PankoParser::OPAREN)
      | (1ULL << PankoParser::OBRACKET)
      | (1ULL << PankoParser::IDENTIFIER))) != 0));
    setState(249);
    match(PankoParser::CBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Object_varContext ------------------------------------------------------------------

PankoParser::Object_varContext::Object_varContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::Object_varContext::IDENTIFIER() {
  return getToken(PankoParser::IDENTIFIER, 0);
}

tree::TerminalNode* PankoParser::Object_varContext::COLON() {
  return getToken(PankoParser::COLON, 0);
}

PankoParser::ExpressionContext* PankoParser::Object_varContext::expression() {
  return getRuleContext<PankoParser::ExpressionContext>(0);
}


size_t PankoParser::Object_varContext::getRuleIndex() const {
  return PankoParser::RuleObject_var;
}

void PankoParser::Object_varContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObject_var(this);
}

void PankoParser::Object_varContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObject_var(this);
}


antlrcpp::Any PankoParser::Object_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitObject_var(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::Object_varContext* PankoParser::object_var() {
  Object_varContext *_localctx = _tracker.createInstance<Object_varContext>(_ctx, getState());
  enterRule(_localctx, 28, PankoParser::RuleObject_var);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    match(PankoParser::IDENTIFIER);
    setState(252);
    match(PankoParser::COLON);
    setState(253);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binary_operatorContext ------------------------------------------------------------------

PankoParser::Binary_operatorContext::Binary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::Binary_operatorContext::OR() {
  return getToken(PankoParser::OR, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::AND() {
  return getToken(PankoParser::AND, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::EQ() {
  return getToken(PankoParser::EQ, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::NEQ() {
  return getToken(PankoParser::NEQ, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::GT() {
  return getToken(PankoParser::GT, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::LT() {
  return getToken(PankoParser::LT, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::GTEQ() {
  return getToken(PankoParser::GTEQ, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::LTEQ() {
  return getToken(PankoParser::LTEQ, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::ADD() {
  return getToken(PankoParser::ADD, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::SUB() {
  return getToken(PankoParser::SUB, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::MUL() {
  return getToken(PankoParser::MUL, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::DIV() {
  return getToken(PankoParser::DIV, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::MOD() {
  return getToken(PankoParser::MOD, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::XOR() {
  return getToken(PankoParser::XOR, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::BITAND() {
  return getToken(PankoParser::BITAND, 0);
}

tree::TerminalNode* PankoParser::Binary_operatorContext::BITOR() {
  return getToken(PankoParser::BITOR, 0);
}


size_t PankoParser::Binary_operatorContext::getRuleIndex() const {
  return PankoParser::RuleBinary_operator;
}

void PankoParser::Binary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_operator(this);
}

void PankoParser::Binary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_operator(this);
}


antlrcpp::Any PankoParser::Binary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitBinary_operator(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::Binary_operatorContext* PankoParser::binary_operator() {
  Binary_operatorContext *_localctx = _tracker.createInstance<Binary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 30, PankoParser::RuleBinary_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PankoParser::OR)
      | (1ULL << PankoParser::AND)
      | (1ULL << PankoParser::EQ)
      | (1ULL << PankoParser::NEQ)
      | (1ULL << PankoParser::GT)
      | (1ULL << PankoParser::LT)
      | (1ULL << PankoParser::GTEQ)
      | (1ULL << PankoParser::LTEQ)
      | (1ULL << PankoParser::ADD)
      | (1ULL << PankoParser::SUB)
      | (1ULL << PankoParser::MUL)
      | (1ULL << PankoParser::DIV)
      | (1ULL << PankoParser::MOD)
      | (1ULL << PankoParser::XOR)
      | (1ULL << PankoParser::BITOR)
      | (1ULL << PankoParser::BITAND))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_operatorContext ------------------------------------------------------------------

PankoParser::Unary_operatorContext::Unary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::Unary_operatorContext::BITNOT() {
  return getToken(PankoParser::BITNOT, 0);
}

tree::TerminalNode* PankoParser::Unary_operatorContext::NOT() {
  return getToken(PankoParser::NOT, 0);
}


size_t PankoParser::Unary_operatorContext::getRuleIndex() const {
  return PankoParser::RuleUnary_operator;
}

void PankoParser::Unary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_operator(this);
}

void PankoParser::Unary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_operator(this);
}


antlrcpp::Any PankoParser::Unary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitUnary_operator(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::Unary_operatorContext* PankoParser::unary_operator() {
  Unary_operatorContext *_localctx = _tracker.createInstance<Unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 32, PankoParser::RuleUnary_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    _la = _input->LA(1);
    if (!(_la == PankoParser::BITNOT

    || _la == PankoParser::NOT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_unary_operatorContext ------------------------------------------------------------------

PankoParser::Type_unary_operatorContext::Type_unary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::Type_unary_operatorContext::GT() {
  return getToken(PankoParser::GT, 0);
}

tree::TerminalNode* PankoParser::Type_unary_operatorContext::LT() {
  return getToken(PankoParser::LT, 0);
}

tree::TerminalNode* PankoParser::Type_unary_operatorContext::MUL() {
  return getToken(PankoParser::MUL, 0);
}


size_t PankoParser::Type_unary_operatorContext::getRuleIndex() const {
  return PankoParser::RuleType_unary_operator;
}

void PankoParser::Type_unary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_unary_operator(this);
}

void PankoParser::Type_unary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_unary_operator(this);
}


antlrcpp::Any PankoParser::Type_unary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitType_unary_operator(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::Type_unary_operatorContext* PankoParser::type_unary_operator() {
  Type_unary_operatorContext *_localctx = _tracker.createInstance<Type_unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 34, PankoParser::RuleType_unary_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PankoParser::GT)
      | (1ULL << PankoParser::LT)
      | (1ULL << PankoParser::MUL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_binary_operatorContext ------------------------------------------------------------------

PankoParser::Type_binary_operatorContext::Type_binary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::Type_binary_operatorContext::BITAND() {
  return getToken(PankoParser::BITAND, 0);
}

tree::TerminalNode* PankoParser::Type_binary_operatorContext::BITOR() {
  return getToken(PankoParser::BITOR, 0);
}


size_t PankoParser::Type_binary_operatorContext::getRuleIndex() const {
  return PankoParser::RuleType_binary_operator;
}

void PankoParser::Type_binary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_binary_operator(this);
}

void PankoParser::Type_binary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_binary_operator(this);
}


antlrcpp::Any PankoParser::Type_binary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitType_binary_operator(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::Type_binary_operatorContext* PankoParser::type_binary_operator() {
  Type_binary_operatorContext *_localctx = _tracker.createInstance<Type_binary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 36, PankoParser::RuleType_binary_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    _la = _input->LA(1);
    if (!(_la == PankoParser::BITOR

    || _la == PankoParser::BITAND)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignment_operatorContext ------------------------------------------------------------------

PankoParser::Assignment_operatorContext::Assignment_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PankoParser::Assignment_operatorContext::ASSIGN() {
  return getToken(PankoParser::ASSIGN, 0);
}

tree::TerminalNode* PankoParser::Assignment_operatorContext::ADDEQ() {
  return getToken(PankoParser::ADDEQ, 0);
}

tree::TerminalNode* PankoParser::Assignment_operatorContext::SUBEQ() {
  return getToken(PankoParser::SUBEQ, 0);
}

tree::TerminalNode* PankoParser::Assignment_operatorContext::MULEQ() {
  return getToken(PankoParser::MULEQ, 0);
}

tree::TerminalNode* PankoParser::Assignment_operatorContext::DIVEQ() {
  return getToken(PankoParser::DIVEQ, 0);
}

tree::TerminalNode* PankoParser::Assignment_operatorContext::MODEQ() {
  return getToken(PankoParser::MODEQ, 0);
}

tree::TerminalNode* PankoParser::Assignment_operatorContext::XOREQ() {
  return getToken(PankoParser::XOREQ, 0);
}

tree::TerminalNode* PankoParser::Assignment_operatorContext::BITANDEQ() {
  return getToken(PankoParser::BITANDEQ, 0);
}

tree::TerminalNode* PankoParser::Assignment_operatorContext::BITOREQ() {
  return getToken(PankoParser::BITOREQ, 0);
}


size_t PankoParser::Assignment_operatorContext::getRuleIndex() const {
  return PankoParser::RuleAssignment_operator;
}

void PankoParser::Assignment_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_operator(this);
}

void PankoParser::Assignment_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PankoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_operator(this);
}


antlrcpp::Any PankoParser::Assignment_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PankoVisitor*>(visitor))
    return parserVisitor->visitAssignment_operator(this);
  else
    return visitor->visitChildren(this);
}

PankoParser::Assignment_operatorContext* PankoParser::assignment_operator() {
  Assignment_operatorContext *_localctx = _tracker.createInstance<Assignment_operatorContext>(_ctx, getState());
  enterRule(_localctx, 38, PankoParser::RuleAssignment_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PankoParser::ASSIGN)
      | (1ULL << PankoParser::ADDEQ)
      | (1ULL << PankoParser::SUBEQ)
      | (1ULL << PankoParser::MULEQ)
      | (1ULL << PankoParser::DIVEQ)
      | (1ULL << PankoParser::MODEQ)
      | (1ULL << PankoParser::XOREQ)
      | (1ULL << PankoParser::BITOREQ)
      | (1ULL << PankoParser::BITANDEQ))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool PankoParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 4: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 5: return typeSempred(dynamic_cast<TypeContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool PankoParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 14);
    case 1: return precpred(_ctx, 11);
    case 2: return precpred(_ctx, 10);
    case 3: return precpred(_ctx, 8);

  default:
    break;
  }
  return true;
}

bool PankoParser::typeSempred(TypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 5);
    case 5: return precpred(_ctx, 6);
    case 6: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> PankoParser::_decisionToDFA;
atn::PredictionContextCache PankoParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PankoParser::_atn;
std::vector<uint16_t> PankoParser::_serializedATN;

std::vector<std::string> PankoParser::_ruleNames = {
  "file", "block", "func_decl", "statement", "expression", "type", "typed_identifier", 
  "argument_list", "var_decl", "if_statement", "if_block", "while_loop", 
  "return_statement", "type_decl", "object_var", "binary_operator", "unary_operator", 
  "type_unary_operator", "type_binary_operator", "assignment_operator"
};

std::vector<std::string> PankoParser::_literalNames = {
  "", "'type'", "'true'", "'false'", "'if'", "'else'", "'while'", "'for'", 
  "'null'", "'int'", "'float'", "'return'", "'module'", "'import'", "'||'", 
  "'&&'", "'=='", "'!='", "'>'", "'<'", "'>='", "'<='", "'+'", "'-'", "'*'", 
  "'/'", "'%'", "'^'", "'|'", "'&'", "'~'", "'!'", "'...'", "'='", "'+='", 
  "'-='", "'*='", "'/='", "'%='", "'^='", "'|='", "'&='", "'++'", "'--'", 
  "';'", "':'", "','", "'.'", "'('", "')'", "'{'", "'}'", "'['", "']'"
};

std::vector<std::string> PankoParser::_symbolicNames = {
  "", "TYPE", "TRUE", "FALSE", "IF", "ELSE", "WHILE", "FOR", "KW_NULL", 
  "INT", "FLOAT", "RETURN", "MODULE", "IMPORT", "OR", "AND", "EQ", "NEQ", 
  "GT", "LT", "GTEQ", "LTEQ", "ADD", "SUB", "MUL", "DIV", "MOD", "XOR", 
  "BITOR", "BITAND", "BITNOT", "NOT", "ELIPSIS", "ASSIGN", "ADDEQ", "SUBEQ", 
  "MULEQ", "DIVEQ", "MODEQ", "XOREQ", "BITOREQ", "BITANDEQ", "INC", "DEC", 
  "SEMICLN", "COLON", "COMMA", "PERIOD", "OPAREN", "CPAREN", "OBRACE", "CBRACE", 
  "OBRACKET", "CBRACKET", "IDENTIFIER", "INTLIT", "FLOATLIT", "COMMENT", 
  "SPACE"
};

dfa::Vocabulary PankoParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PankoParser::_tokenNames;

PankoParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x3c, 0x10c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x2f, 0xa, 
    0x2, 0xd, 0x2, 0xe, 0x2, 0x30, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x37, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x3a, 0xb, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 
    0x43, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x46, 0xb, 0x4, 0x5, 0x4, 0x48, 
    0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x5b, 0xa, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x68, 0xa, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x6e, 0xa, 0x6, 0xd, 0x6, 0xe, 
    0x6, 0x6f, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x76, 0xa, 
    0x6, 0xc, 0x6, 0xe, 0x6, 0x79, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x82, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0x85, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x8f, 0xa, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 
    0x6, 0x9f, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xa2, 0xb, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x7, 0x7, 0xad, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xb0, 0xb, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xb6, 0xa, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x7, 0x7, 0xc0, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xc3, 0xb, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xcb, 0xa, 
    0x9, 0xc, 0x9, 0xe, 0x9, 0xce, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0xd3, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x7, 0xb, 0xda, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xdd, 0xb, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0xe1, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x6, 0xf, 0xf8, 0xa, 0xf, 0xd, 
    0xf, 0xe, 0xf, 0xf9, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x2, 
    0x4, 0xa, 0xc, 0x16, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2, 
    0xa, 0x3, 0x2, 0x4, 0x5, 0x3, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0xa, 0xc, 0x3, 
    0x2, 0x10, 0x1f, 0x3, 0x2, 0x20, 0x21, 0x4, 0x2, 0x14, 0x15, 0x1a, 0x1a, 
    0x3, 0x2, 0x1e, 0x1f, 0x3, 0x2, 0x23, 0x2b, 0x2, 0x121, 0x2, 0x2a, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x34, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x5a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x8e, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xe, 0xc4, 0x3, 0x2, 0x2, 0x2, 0x10, 0xc7, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x14, 0xd4, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0xe2, 0x3, 0x2, 0x2, 0x2, 0x18, 0xe7, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0xed, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xf0, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x20, 0x101, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x103, 0x3, 0x2, 0x2, 0x2, 0x24, 0x105, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x107, 0x3, 0x2, 0x2, 0x2, 0x28, 0x109, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 
    0x7, 0xe, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x38, 0x2, 0x2, 0x2c, 0x2e, 0x7, 
    0x2e, 0x2, 0x2, 0x2d, 0x2f, 0x5, 0x8, 0x5, 0x2, 0x2e, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x33, 0x7, 0x2, 0x2, 0x3, 0x33, 0x3, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x38, 0x7, 0x34, 0x2, 0x2, 0x35, 0x37, 0x5, 0x8, 0x5, 0x2, 0x36, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x37, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x35, 0x2, 
    0x2, 0x3c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x5, 0xe, 0x8, 0x2, 
    0x3e, 0x47, 0x7, 0x32, 0x2, 0x2, 0x3f, 0x44, 0x5, 0xe, 0x8, 0x2, 0x40, 
    0x41, 0x7, 0x30, 0x2, 0x2, 0x41, 0x43, 0x5, 0xe, 0x8, 0x2, 0x42, 0x40, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x46, 0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 0x45, 0x48, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x47, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x49, 0x4a, 0x7, 0x33, 0x2, 0x2, 0x4a, 0x4b, 0x5, 0x4, 0x3, 0x2, 0x4b, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x5b, 0x5, 0x6, 0x4, 0x2, 0x4d, 0x4e, 
    0x5, 0x12, 0xa, 0x2, 0x4e, 0x4f, 0x7, 0x2e, 0x2, 0x2, 0x4f, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x5b, 0x5, 0x1c, 0xf, 0x2, 0x51, 0x5b, 0x5, 0x14, 
    0xb, 0x2, 0x52, 0x5b, 0x5, 0x18, 0xd, 0x2, 0x53, 0x5b, 0x5, 0x4, 0x3, 
    0x2, 0x54, 0x55, 0x5, 0x1a, 0xe, 0x2, 0x55, 0x56, 0x7, 0x2e, 0x2, 0x2, 
    0x56, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x5, 0xa, 0x6, 0x2, 0x58, 
    0x59, 0x7, 0x2e, 0x2, 0x2, 0x59, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x4c, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x51, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x52, 0x3, 0x2, 
    0x2, 0x2, 0x5a, 0x53, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x5d, 0x8, 0x6, 0x1, 0x2, 0x5d, 0x5e, 0x7, 0x32, 0x2, 0x2, 0x5e, 
    0x5f, 0x5, 0xa, 0x6, 0x2, 0x5f, 0x60, 0x7, 0x33, 0x2, 0x2, 0x60, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x5, 0x22, 0x12, 0x2, 0x62, 0x63, 0x5, 
    0xa, 0x6, 0xf, 0x63, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x7, 0x38, 
    0x2, 0x2, 0x65, 0x67, 0x7, 0x32, 0x2, 0x2, 0x66, 0x68, 0x5, 0x10, 0x9, 
    0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 
    0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x8f, 0x7, 0x33, 0x2, 0x2, 0x6a, 
    0x6d, 0x7, 0x38, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x31, 0x2, 0x2, 0x6c, 0x6e, 
    0x7, 0x38, 0x2, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x77, 0x7, 0x34, 0x2, 
    0x2, 0x72, 0x73, 0x5, 0x1e, 0x10, 0x2, 0x73, 0x74, 0x7, 0x30, 0x2, 0x2, 
    0x74, 0x76, 0x3, 0x2, 0x2, 0x2, 0x75, 0x72, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x7b, 0x5, 0x1e, 0x10, 0x2, 0x7b, 0x7c, 0x7, 0x35, 
    0x2, 0x2, 0x7c, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x83, 0x7, 0x36, 0x2, 
    0x2, 0x7e, 0x7f, 0x5, 0xa, 0x6, 0x2, 0x7f, 0x80, 0x7, 0x30, 0x2, 0x2, 
    0x80, 0x82, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 
    0x3, 0x2, 0x2, 0x2, 0x84, 0x86, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x86, 0x87, 0x5, 0xa, 0x6, 0x2, 0x87, 0x88, 0x7, 0x37, 
    0x2, 0x2, 0x88, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8f, 0x7, 0x38, 0x2, 
    0x2, 0x8a, 0x8f, 0x7, 0x39, 0x2, 0x2, 0x8b, 0x8f, 0x7, 0x3a, 0x2, 0x2, 
    0x8c, 0x8f, 0x9, 0x2, 0x2, 0x2, 0x8d, 0x8f, 0x7, 0xa, 0x2, 0x2, 0x8e, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x61, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x64, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x89, 0x3, 0x2, 
    0x2, 0x2, 0x8e, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x8f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0xc, 0x10, 0x2, 0x2, 0x91, 
    0x92, 0x5, 0x20, 0x11, 0x2, 0x92, 0x93, 0x5, 0xa, 0x6, 0x11, 0x93, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0xc, 0xd, 0x2, 0x2, 0x95, 0x96, 0x5, 
    0x28, 0x15, 0x2, 0x96, 0x97, 0x5, 0xa, 0x6, 0xe, 0x97, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x99, 0xc, 0xc, 0x2, 0x2, 0x99, 0x9f, 0x9, 0x3, 0x2, 
    0x2, 0x9a, 0x9b, 0xc, 0xa, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x36, 0x2, 0x2, 
    0x9c, 0x9d, 0x7, 0x39, 0x2, 0x2, 0x9d, 0x9f, 0x7, 0x37, 0x2, 0x2, 0x9e, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x94, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x98, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0xa1, 0xb, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0xa3, 0xa4, 0x8, 0x7, 0x1, 0x2, 0xa4, 0xa5, 0x7, 0x32, 0x2, 0x2, 
    0xa5, 0xa6, 0x5, 0xc, 0x7, 0x2, 0xa6, 0xa7, 0x7, 0x33, 0x2, 0x2, 0xa7, 
    0xb6, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x36, 0x2, 0x2, 0xa9, 0xae, 
    0x5, 0xc, 0x7, 0x2, 0xaa, 0xab, 0x7, 0x30, 0x2, 0x2, 0xab, 0xad, 0x5, 
    0xc, 0x7, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 0xb0, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xb2, 0x7, 0x37, 0x2, 0x2, 0xb2, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0xb6, 0x9, 0x4, 0x2, 0x2, 0xb4, 0xb6, 0x7, 0x38, 0x2, 0x2, 0xb5, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0xb5, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb3, 0x3, 
    0x2, 0x2, 0x2, 0xb5, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xc1, 0x3, 0x2, 
    0x2, 0x2, 0xb7, 0xb8, 0xc, 0x7, 0x2, 0x2, 0xb8, 0xb9, 0x5, 0x26, 0x14, 
    0x2, 0xb9, 0xba, 0x5, 0xc, 0x7, 0x8, 0xba, 0xc0, 0x3, 0x2, 0x2, 0x2, 
    0xbb, 0xbc, 0xc, 0x8, 0x2, 0x2, 0xbc, 0xc0, 0x5, 0x24, 0x13, 0x2, 0xbd, 
    0xbe, 0xc, 0x5, 0x2, 0x2, 0xbe, 0xc0, 0x7, 0x22, 0x2, 0x2, 0xbf, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0xc, 0x7, 0x2, 
    0xc5, 0xc6, 0x7, 0x38, 0x2, 0x2, 0xc6, 0xf, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xcc, 0x5, 0xa, 0x6, 0x2, 0xc8, 0xc9, 0x7, 0x30, 0x2, 0x2, 0xc9, 0xcb, 
    0x5, 0xa, 0x6, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xce, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0xcd, 0x11, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0xcf, 0xd2, 0x5, 0xe, 0x8, 0x2, 0xd0, 0xd1, 0x7, 0x23, 0x2, 0x2, 
    0xd1, 0xd3, 0x5, 0xa, 0x6, 0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd2, 
    0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0x13, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 
    0x7, 0x6, 0x2, 0x2, 0xd5, 0xdb, 0x5, 0x16, 0xc, 0x2, 0xd6, 0xd7, 0x7, 
    0x7, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x6, 0x2, 0x2, 0xd8, 0xda, 0x5, 0x16, 
    0xc, 0x2, 0xd9, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xde, 
    0xdf, 0x7, 0x7, 0x2, 0x2, 0xdf, 0xe1, 0x5, 0x4, 0x3, 0x2, 0xe0, 0xde, 
    0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x32, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0xa, 
    0x6, 0x2, 0xe4, 0xe5, 0x7, 0x33, 0x2, 0x2, 0xe5, 0xe6, 0x5, 0x4, 0x3, 
    0x2, 0xe6, 0x17, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x8, 0x2, 0x2, 
    0xe8, 0xe9, 0x7, 0x32, 0x2, 0x2, 0xe9, 0xea, 0x5, 0xa, 0x6, 0x2, 0xea, 
    0xeb, 0x7, 0x33, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x4, 0x3, 0x2, 0xec, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x7, 0xd, 0x2, 0x2, 0xee, 0xef, 0x5, 
    0xa, 0x6, 0x2, 0xef, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x3, 
    0x2, 0x2, 0xf1, 0xf2, 0x7, 0x38, 0x2, 0x2, 0xf2, 0xf7, 0x7, 0x34, 0x2, 
    0x2, 0xf3, 0xf4, 0x5, 0x12, 0xa, 0x2, 0xf4, 0xf5, 0x7, 0x2e, 0x2, 0x2, 
    0xf5, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 0x5, 0x6, 0x4, 0x2, 0xf7, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 
    0x3, 0x2, 0x2, 0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x35, 
    0x2, 0x2, 0xfc, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x38, 0x2, 
    0x2, 0xfe, 0xff, 0x7, 0x2f, 0x2, 0x2, 0xff, 0x100, 0x5, 0xa, 0x6, 0x2, 
    0x100, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x9, 0x5, 0x2, 0x2, 0x102, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x9, 0x6, 0x2, 0x2, 0x104, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x9, 0x7, 0x2, 0x2, 0x106, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0x107, 0x108, 0x9, 0x8, 0x2, 0x2, 0x108, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x109, 0x10a, 0x9, 0x9, 0x2, 0x2, 0x10a, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0x18, 0x30, 0x38, 0x44, 0x47, 0x5a, 0x67, 0x6f, 0x77, 0x83, 0x8e, 
    0x9e, 0xa0, 0xae, 0xb5, 0xbf, 0xc1, 0xcc, 0xd2, 0xdb, 0xe0, 0xf7, 0xf9, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PankoParser::Initializer PankoParser::_init;
