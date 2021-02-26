//
// Created by jack on 1/24/21.
//

#ifndef PANKO_AST_H
#define PANKO_AST_H

#include "PankoBaseVisitor.h"
#include "panko_util.h"
#include "panko_scope.h"

#include <string>
#include <utility>
#include <vector>
#include <functional>

namespace panko::ast {

    enum class BinaryOperator {
        OR, AND, EQ, NEQ, GT, LT, GTEQ, LTEQ, ADD, SUB, MUL, DIV, MOD, XOR, BITAND, BITOR
    };

    enum class UnaryOperator {
        BITNOT, NOT
    };

    enum class TypeOperator {
        BASIC, SUBSET, SUPERSET, REFERENCE, CONJUNCTION, DISJUNCTION, TUPLE, ARRAY
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

        Type() = default;
        explicit Type(const std::string& name): name{name} {}
    };

    struct TypeIdentifier : Node {
        Identifier id;
        TypeOperator op{TypeOperator::BASIC};

        std::vector<std::unique_ptr<TypeIdentifier>> other_types;

        [[nodiscard]] TypeIdentifier clone() const {
            TypeIdentifier ret_val;
            ret_val.id = id;
            ret_val.op = op;
            for (const auto& ptr : other_types) {
                ret_val.other_types.push_back(std::make_unique<TypeIdentifier>(ptr->clone()));
            }
            return ret_val;
        }
    };

    struct Variable {
        util::string_hash name;
        std::unique_ptr<TypeIdentifier> type;

        explicit Variable(const std::string& name): name{name} {}
        Variable(util::string_hash name, std::unique_ptr<TypeIdentifier> type) : name{name}, type{std::move(type)} {}
    };

    struct Function {
        util::string_hash name;

        std::vector<Variable> parameters;
        std::unique_ptr<TypeIdentifier> return_type;
        std::unique_ptr<Block> body;

        explicit Function(const std::string& name): name{name} {}
    };
}

namespace std {
    template<> struct hash<panko::ast::Type> {
        size_t operator()(const panko::ast::Type& type) const {
            return type.name.getHash();
        }
    };

    template<> struct hash<panko::ast::Variable> {
        size_t operator()(const panko::ast::Variable& type) const {
            return type.name.getHash();
        }
    };

    template<> struct hash<panko::ast::Function> {
        size_t operator()(const panko::ast::Function& type) const {
            return type.name.getHash();
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

    struct NullLiteral : Expression {};

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

    struct TypeDeclaration : Statement {
        size_t type{};
    };

    struct VariableExpression : Expression {
        Identifier variable;
    };

    struct SimpleAssignment : Expression {
        std::unique_ptr<Expression> reference;
        std::unique_ptr<Expression> expression;
    };

    struct ComplexAssignment : Expression {
        std::unique_ptr<Expression> reference;
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

    struct AccessExpression : Expression {
        Identifier initial;
        std::vector<std::string> accessors;
    };

    struct ArrayAccessExpression : Expression {
        std::unique_ptr<Expression> reference;
        int index;
    };

    struct ObjectExpression : Expression {
        std::vector<std::pair<util::string_hash, std::unique_ptr<Expression>>> members;
    };

    struct ArrayExpression : Expression {
        std::vector<std::unique_ptr<Expression>> members;
    };

    struct AST {
        util::hasher<Type> types;
        util::hasher<Variable> variables;
        util::hasher<Function> functions;
        std::vector<std::unique_ptr<File>> files;
    };
}

#endif //PANKO_AST_H