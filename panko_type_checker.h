//
// Created by jack on 3/19/21.
//

#ifndef PANKO_TYPE_CHECKER_H
#define PANKO_TYPE_CHECKER_H

#include "panko_ast_visitor.h"
#include "panko_resolver.h"

#include <stack>

#undef NULL

namespace panko::statics {
    struct ImproperAccess : util::Exception {
        using Exception::Exception;
    };

    struct ImproperAssignment : util::Exception {
        using Exception::Exception;
    };

    struct ImproperExpression : util::Exception {
        using Exception::Exception;
    };

    struct FailedSymbolResolution : util::Exception {
        using Exception::Exception;
    };

    struct ImproperReturnType : util::Exception {
        using Exception::Exception;
    };

    enum class TypeCategory {
        INT, FLOAT, BOOL, NULL, OBJECT, REF, ARRAY, TUPLE, SUPERSET, SUBSET, CONJUNCTION, DISJUNCTION
    };

    struct Type {
        TypeCategory category = TypeCategory::NULL;
        std::map<size_t, Type> subtypes;
        //std::vector<Type> subtypes;
        //std::vector<util::string_hash> object_keys;

        [[nodiscard]] const Type& decay() const {
            if (category == TypeCategory::REF) {
                return subtypes.at(0);
            } else if (category == TypeCategory::SUPERSET) {
                return subtypes.at(0);
            } else {
                return *this;
            }
        }

        [[nodiscard]] bool assignableFrom(const Type& other) const;

        friend std::ostream& operator<<(std::ostream& os, const Type& type);
    };

    Type typeFromASTType(const ast::AST& ast, const ast::TypeIdentifier* ast_type);
    Type referenceTo(const Type& other);

    class TypeChecker : public ast::BaseVisitor<Type> {
    public:
        explicit TypeChecker(const ast::AST& ast) : ast{ast} {}
    private:
        const ast::AST& ast;
        std::stack<Type> return_types;

        Type visitFile(ast::File* file) override {
            for (const auto& statement : file->statements) {
                std::cout << visit(statement.get()) << '\n';
            }
            return {};
        }

        Type visitIntegerLiteral(ast::IntegerLiteral*) override {
            return Type{TypeCategory::INT, {}};
        }

        Type visitFloatLiteral(ast::FloatLiteral*) override {
            return Type{TypeCategory::FLOAT, {}};
        }

        Type visitBoolLiteral(ast::BoolLiteral*) override {
            return Type{TypeCategory::BOOL, {}};
        }

        Type visitNullLiteral(ast::NullLiteral*) override {
            return Type{TypeCategory::NULL, {}};
        }

        Type visitObjectExpression(ast::ObjectExpression* object) override {
            Type ret_val;
            ret_val.category = TypeCategory::OBJECT;
            for (const auto& member : object->members) {
                //ret_val.object_keys.emplace_back(member.first);
                ret_val.subtypes.emplace(member.first.getHash(), visit(member.second.get())); // No decay here, will be handled in object assignment
            }

            return ret_val;
        }

        Type visitArrayAccessExpression(ast::ArrayAccessExpression* access) override {
            const Type& array = visit(access->reference.get()).decay();
            if (array.category != TypeCategory::ARRAY) {
                throw ImproperAccess{"Cannot call operator[] on non-container type"};
            } else {
                return array.subtypes.at(0);
            }
        }

        Type visitAccessExpression(ast::AccessExpression* access) override {
            Type object = visit(access->reference.get()).decay();
            for (const auto& accessor : access->accessors) {
                if (object.category != TypeCategory::OBJECT) {
                    throw ImproperAccess{"Cannot access member of non-object type"};
                }

                auto it = object.subtypes.find(util::string_hash{accessor}.getHash());
                if (it == object.subtypes.end()) {
                    throw ImproperAccess{"Object does not contain specified member"};
                } else {
                    object = it->second;
                }
            }

            return referenceTo(object);
        }

        Type visitSimpleAssignment(ast::SimpleAssignment* assn) override {
            Type var = visit(assn->reference.get());
            if (var.category != TypeCategory::REF) {
                throw ImproperAssignment{"Cannot assign to non-reference type"};
            }
            if (!var.subtypes.at(0).assignableFrom(visit(assn->expression.get()))) {
                throw ImproperAssignment{"Cannot assign from incompatible expression"};
            }

            return var.subtypes.at(0);
        }

        Type visitVariableDeclaration(ast::VariableDeclaration* decl) override {
            Type var = typeFromASTType(ast, ast.variables.get(decl->variable)->type.get());
            if (decl->assignment && !var.assignableFrom(visit(decl->assignment.get()))) {
                throw ImproperAssignment{"Cannot assign from incompatible expression"};
            }

            return var;
        }

        Type visitVariableExpression(ast::VariableExpression* var) override {
            const auto* var_ptr = resolveVar(ast, var->variable);
            if (!var_ptr) {
                throw FailedSymbolResolution{"Variable does not exist"};
            }
            return referenceTo(typeFromASTType(ast, var_ptr->type.get()));
        }

        Type visitIfStatement(ast::IfStatement* stat) override {
            for (const auto& block : stat->if_blocks) {
                if (visit(block.condition.get()).decay().category != TypeCategory::BOOL) {
                    throw ImproperExpression{"Cannot use non-bool type in if statement"};
                }
                visit(block.block.get());
            }
            visit(stat->else_block.get());
            return {};
        }

        Type visitWhileLoop(ast::WhileLoop* loop) override {
            if (visit(loop->condition.get()).decay().category != TypeCategory::BOOL) {
                throw ImproperExpression{"Cannot use non-bool type in while loop"};
            }
            visit(loop->body.get());
            return {};
        }

        Type visitBlock(ast::Block* block) override {
            for (const auto& statement : block->statements) {
                visit(statement.get());
            }
            return {};
        }

        Type visitComplexAssignment(ast::ComplexAssignment* assn) override {
            Type var = visit(assn->reference.get());
            if (var.category != TypeCategory::REF) {
                throw ImproperAssignment{"Cannot assign to non-reference type"};
            }

            return var.subtypes.at(0);
        }

        Type visitFunctionDeclaration(ast::FunctionDeclaration* decl) override {
            const auto func = ast.functions.get(decl->function);
            return_types.push(typeFromASTType(ast, func->return_type.get()));
            visit(func->body.get());
            return_types.pop();
            return {};
        }

        Type visitReturnStatement(ast::ReturnStatement* ret) override {
            if (!return_types.top().assignableFrom(visit(ret->expression.get()))) {
                throw ImproperReturnType{"Cannot return from incompatible type"};
            }
            return {};
        }
    };
}

#define NULL 0

#endif //PANKO_TYPE_CHECKER_H
