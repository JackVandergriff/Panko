
// Generated from /home/jack/Documents/Panko/Panko.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  PankoLexer : public antlr4::Lexer {
public:
  enum {
    TYPE = 1, TRUE = 2, FALSE = 3, IF = 4, ELSE = 5, WHILE = 6, FOR = 7, 
    KW_NULL = 8, INT = 9, FLOAT = 10, RETURN = 11, MODULE = 12, IMPORT = 13, 
    OR = 14, AND = 15, EQ = 16, NEQ = 17, GT = 18, LT = 19, GTEQ = 20, LTEQ = 21, 
    ADD = 22, SUB = 23, MUL = 24, DIV = 25, MOD = 26, XOR = 27, BITOR = 28, 
    BITAND = 29, BITNOT = 30, NOT = 31, ASSIGN = 32, ADDEQ = 33, SUBEQ = 34, 
    MULEQ = 35, DIVEQ = 36, MODEQ = 37, XOREQ = 38, BITOREQ = 39, BITANDEQ = 40, 
    INC = 41, DEC = 42, SEMICLN = 43, COLON = 44, COMMA = 45, PERIOD = 46, 
    OPAREN = 47, CPAREN = 48, OBRACE = 49, CBRACE = 50, OBRACKET = 51, CBRACKET = 52, 
    IDENTIFIER = 53, INTLIT = 54, FLOATLIT = 55, COMMENT = 56, SPACE = 57
  };

  explicit PankoLexer(antlr4::CharStream *input);
  ~PankoLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

