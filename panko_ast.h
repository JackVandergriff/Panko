//
// Created by jack on 1/24/21.
//

#ifndef PANKO_AST_H
#define PANKO_AST_H

#include <string>
#include <vector>
#include <functional>

#include "PankoBaseVisitor.h"
#include "panko_util.h"

namespace panko::ast {

    using type_hash = size_t;
    using variable_hash = size_t;
    using function_hash = size_t;

    enum class BinaryOperator {
        OR, AND, EQ, NEQ, GT, LT, GTEQ, LTEQ, ADD, SUB, MUL, DIV, MOD, XOR, BITAND, BITOR
    };

    enum class UnaryOperator {
        BITNOT, NOT
    };

    struct Node {
        virtual ~Node() = default;
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

    struct Variable : Node {
        util::string_hash name;
        type_hash type{};

        explicit Variable(const std::string& name): name{name} {}
        Variable(util::string_hash name, type_hash type): name{name}, type{type} {}
    };

    struct Function : Node {
        util::string_hash name;

        std::vector<Variable> parameters;
        type_hash return_type{};
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

    struct FunctionCall : Expression {
        function_hash function;
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
        variable_hash variable{};
        std::unique_ptr<Expression> assignment;
    };

    struct FunctionDeclaration : Statement {
        function_hash function{};
    };

    struct Identifier : Expression {
        variable_hash variable{};
    };

    struct SimpleAssignment : Expression {
        variable_hash variable;
        std::unique_ptr<Expression> expression;
    };

    struct ComplexAssignment : Expression {
        variable_hash variable{};
        bool increment{false};
    };

    struct IfStatement {
        std::unique_ptr<Block> if_block;
        std::unique_ptr<Block> else_block;
        std::unique_ptr<Expression> condition;
    };

    struct ReturnStatement : Statement {
        std::unique_ptr<Expression> expression;
    };

    struct File : Node {
        std::vector<std::unique_ptr<Statement>> statements;
    };

    struct AST {
        util::hasher<Type> types{};
        util::hasher<Variable> variables;
        util::hasher<Function> functions;
        std::vector<std::unique_ptr<File>> files{};
    };
}



#endif //PANKO_AST_H
