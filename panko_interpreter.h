//
// Created by jack on 1/24/21.
//

#ifndef PANKO_INTERPRETER_H
#define PANKO_INTERPRETER_H

#include "panko_ast_visitor.h"

#include <iostream>
#include <variant>

namespace panko::runtime {

    struct BadOperatorCall : util::Exception {
        using util::Exception::Exception;
    };

    struct BadTypeConversion : util::Exception {
        using util::Exception::Exception;
    };

    struct ComplexValue;
    struct ReturnValue;
    struct Reference;

    struct Returning {};

    using Null = std::monostate;
    using Value = util::invariant<int, double, bool, Null, ComplexValue, Returning, Reference>;
    using WeakValue = std::variant<int, double, bool, Null, ComplexValue, Returning, Reference>;

    struct Reference {
        Value* value;
    };

    struct ComplexValue {
        std::map<util::string_hash, Value> attributes;

        ComplexValue()= default;
        ComplexValue(const ComplexValue&)=default;

        ComplexValue& operator=(const ComplexValue& other);
        ComplexValue(ComplexValue&&)=default;
        ComplexValue& operator=(ComplexValue&&)=default;
    };

    std::ostream& operator<<(std::ostream& os, const Value& val);

    struct Interpreter : ast::BaseVisitor<Value> {
        const ast::AST& ast;
        util::hasher<ast::Variable> params;
        std::map<size_t, Value> values;
        WeakValue return_value;
        size_t call_stack_size = 0;

        explicit Interpreter(const ast::AST& ast) : ast{ast} {}
        void run();

        static const Value& removeReference(const Value& value);
        static Value& getReferenceValue(const Value& ref);
        Reference makeReference(const ast::Identifier& id);

        std::tuple<size_t, const ast::Variable*> findVariableAndHash(const ast::Identifier& id);
        const ast::Variable* findVariable(const ast::Identifier& id);
        Value& findValue(const ast::Identifier& id);
        const ast::Type* findType(const ast::Identifier& id);
        const ast::Function* findFunction(const ast::Identifier& id);

        Value constructValue(const ast::Type& type);

        Value visitFile(ast::File *file) override;
        Value visitBinaryOperatorExpression(ast::BinaryOperatorExpression *expression) override;
        Value visitUnaryOperatorExpression(ast::UnaryOperatorExpression* expression) override;
        Value visitIntegerLiteral(ast::IntegerLiteral *literal) override;
        Value visitFloatLiteral(ast::FloatLiteral *literal) override;
        Value visitBoolLiteral(ast::BoolLiteral* literal) override;
        Value visitVariableDeclaration(ast::VariableDeclaration *var_decl) override;
        Value visitVariableExpression(ast::VariableExpression *identifier) override;
        Value visitComplexAssignment(ast::ComplexAssignment *assignment) override;
        Value visitSimpleAssignment(ast::SimpleAssignment *assignment) override;
        Value visitBlock(ast::Block *block) override;
        Value visitIfStatement(ast::IfStatement* if_stat) override;
        Value visitWhileLoop(ast::WhileLoop* loop) override;
        Value visitReturnStatement(ast::ReturnStatement* return_stat) override;
        Value visitFunctionDeclaration(ast::FunctionDeclaration *) override;
        Value visitFunctionCall(ast::FunctionCall* call) override;
        Value visitTypeDeclaration(ast::TypeDeclaration*) override;
        Value visitAccessExpression(ast::AccessExpression* access) override;
    };
}

#endif //PANKO_INTERPRETER_H
