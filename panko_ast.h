//
// Created by jack on 1/24/21.
//

#ifndef PANKO_AST_H
#define PANKO_AST_H

#include <string>
#include <utility>
#include <vector>
#include <functional>

#include "PankoBaseVisitor.h"
#include "panko_util.h"
#include "panko_scope.h"

namespace panko::ast {

    enum class BinaryOperator {
        OR, AND, EQ, NEQ, GT, LT, GTEQ, LTEQ, ADD, SUB, MUL, DIV, MOD, XOR, BITAND, BITOR
    };

    enum class UnaryOperator {
        BITNOT, NOT
    };

    struct Node {
        virtual ~Node() = default;
    };

    struct Identifier {
        std::string identifier;
        scope::Context context;
    };

    struct Statement : Node {
    };

    struct Block : Node {
        std::vector<std::unique_ptr<Statement>> statements;
    };

    struct Expression : Statement {
    };

    struct Variable;
    struct Function;

    struct Type {
        util::string_hash name;

        std::vector<Variable> attributes;
        std::vector<Function> methods;

        explicit Type(const std::string& name): name{name} {}
    };

    struct Variable {
        util::string_hash name;
        Identifier type;

        explicit Variable(const std::string& name): name{name} {}
        Variable(util::string_hash name, Identifier type) : name{name}, type{std::move(type)} {}
    };

    struct Function {
        util::string_hash name;

        std::vector<Variable> parameters;
        Identifier return_type;
        std::unique_ptr<Block> body;

        explicit Function(const std::string& name): name{name} {}
    };
}

namespace std {
    template<> struct hash<panko::ast::Type> {
        size_t operator()(const panko::ast::Type& type) const {
            return type.name.hash;
        }
    };

    template<> struct hash<panko::ast::Variable> {
        size_t operator()(const panko::ast::Variable& type) const {
            return type.name.hash;
        }
    };

    template<> struct hash<panko::ast::Function> {
        size_t operator()(const panko::ast::Function& type) const {
            return type.name.hash;
        }
    };
}

namespace panko::ast {

    const static inline Type Integer{"int"};
    const static inline Type Float{"float"};
    const static inline Type Bool{"bool"};


    struct IntegerLiteral : Expression {
        int value{};
    };

    struct FloatLiteral : Expression {
        double value{};
    };

    struct BoolLiteral : Expression {
        bool value{};
    };

    struct FunctionCall : Expression {
        Identifier function;
        std::vector<std::unique_ptr<Expression>> arguments;
    };

    struct BinaryOperatorExpression : Expression {
        std::unique_ptr<Expression> lhs;
        std::unique_ptr<Expression> rhs;
        BinaryOperator op{};
    };

    struct UnaryOperatorExpression : Expression {
        std::unique_ptr<Expression> lhs;
        UnaryOperator op{};
    };

    struct VariableDeclaration : Statement {
        size_t variable;
        std::unique_ptr<Expression> assignment;
    };

    struct FunctionDeclaration : Statement {
        size_t function{};
    };

    struct VariableExpression : Expression {
        Identifier variable;
    };

    struct SimpleAssignment : Expression {
        Identifier variable;
        std::unique_ptr<Expression> expression;
    };

    struct ComplexAssignment : Expression {
        Identifier variable;
        bool increment{false};
    };

    struct IfBlock {
        std::unique_ptr<Expression> condition;
        std::unique_ptr<Block> block;
    };

    struct IfStatement : Statement {
        std::vector<IfBlock> if_blocks;
        std::unique_ptr<Block> else_block;
    };

    struct WhileLoop : Statement {
        std::unique_ptr<Expression> condition;
        std::unique_ptr<Block> body;
    };

    struct ReturnStatement : Statement {
        std::unique_ptr<Expression> expression;
    };

    struct File : Node {
        std::string module;
        std::vector<std::unique_ptr<Statement>> statements;
    };

    struct AST {
        util::hasher<Type> types;
        util::hasher<Variable> variables;
        util::hasher<Function> functions;
        std::vector<std::unique_ptr<File>> files;
    };
}



#endif //PANKO_AST_H
