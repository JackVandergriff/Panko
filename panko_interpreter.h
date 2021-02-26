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
    struct Array;
    struct Tuple;
    struct Interpreter;

    struct Returning {};

    using Null = std::monostate;
    using Value = util::invariant<int, double, bool, Null, ComplexValue, Returning, Reference, Array, Tuple>;

    struct Reference {
        const ast::TypeIdentifier* type;
        Value* value;
    };

    struct ComplexValue {
        std::map<util::string_hash, Value> attributes;

        ComplexValue()= default;
        ComplexValue(const ComplexValue&)=default;

        ComplexValue& operator=(const ComplexValue& other);
        ComplexValue(ComplexValue&&)=default;
        ComplexValue& operator=(ComplexValue&& other); // Can't be noexcept, could throw BadTypeConversion
    };

    struct Array {
        const ast::TypeIdentifier* type = nullptr;
        const Interpreter* interpreter = nullptr; // Needs access to remove_reference for conversions
        std::vector<Value> values;

        Array() = delete;
        explicit Array(const ast::TypeIdentifier* type, const Interpreter* interpreter): type{type}, interpreter{interpreter} {}

        Value& operator[](size_t index) {
            return values.at(index);
        }

        Array(const Array&)=default;
        Array& operator=(const Array& other);
        Array(Array&&)=default;
        Array& operator=(Array&&)=default;
    };

    struct Tuple {
        const Interpreter* interpreter = nullptr; // Needs access to remove_reference for conversions
        std::vector<const ast::TypeIdentifier*> types;
        std::vector<Value> values;

        Tuple()=delete;
        explicit Tuple(const Interpreter* interpreter) : interpreter{interpreter} {}
        Tuple(const Tuple&)=default;
        Tuple& operator=(const Tuple& other);
        Tuple(Tuple&&)=default;
        Tuple& operator=(Tuple&&)=default;
    };

    using WeakValue = std::remove_cvref_t<decltype(Value{}.getVariant())>; // Get the variant inside Value

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

        Value convert(const Value& other, const ast::TypeIdentifier* type) const;
        [[nodiscard]] std::tuple<size_t, const ast::Variable*> findVariableAndHash(const ast::Identifier& id) const;
        [[nodiscard]] const ast::Variable* findVariable(const ast::Identifier& id) const;
        [[nodiscard]] Value& findValue(const ast::Identifier& id);
        [[nodiscard]] const ast::Type* findType(const ast::Identifier& id) const;
        [[nodiscard]] const ast::Function* findFunction(const ast::Identifier& id) const;

        Value constructValue(const ast::TypeIdentifier* type) const;

        Value visitFile(ast::File *file) override;
        Value visitBinaryOperatorExpression(ast::BinaryOperatorExpression *expression) override;
        Value visitUnaryOperatorExpression(ast::UnaryOperatorExpression* expression) override;
        Value visitIntegerLiteral(ast::IntegerLiteral *literal) override;
        Value visitFloatLiteral(ast::FloatLiteral *literal) override;
        Value visitBoolLiteral(ast::BoolLiteral* literal) override;
        Value visitNullLiteral(ast::NullLiteral *literal) override;
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
        Value visitArrayAccessExpression(ast::ArrayAccessExpression* access) override;
        Value visitObjectExpression(ast::ObjectExpression* object) override;
        Value visitArrayExpression(ast::ArrayExpression* array) override;
    };
}

#endif //PANKO_INTERPRETER_H
