//
// Created by jack on 3/19/21.
//

#include "panko_type_checker.h"

using namespace panko;
using namespace panko::statics;

bool Type::assignableFrom(const Type &other) const {
    const Type& ldecay = decay();
    const Type& rdecay = other.decay();

    if (category == TypeCategory::REF && other.category != TypeCategory::REF) {
        return false;
    } else if (rdecay.category == TypeCategory::INT && ldecay.category == TypeCategory::FLOAT) {
        return true;
    } else if (ldecay.category != rdecay.category) {
        return false;
    } else if (ldecay.category != TypeCategory::OBJECT && rdecay.category != TypeCategory::OBJECT) {
        if (ldecay.subtypes.size() != rdecay.subtypes.size()) return false;
        for (size_t i = 0; i < ldecay.subtypes.size(); i++) {
            if (!ldecay.subtypes.at(i).assignableFrom(rdecay.subtypes.at(i))) return false;
        }
        return true;
    } else {
        const Type* obj = this;
        if (category == TypeCategory::REF) {
            obj = &subtypes.at(0);
        }

        if (obj->category == TypeCategory::OBJECT) {
            if (ldecay.subtypes.size() != rdecay.subtypes.size()) return false;
            return std::all_of(ldecay.subtypes.begin(), ldecay.subtypes.end(), [&rdecay](const auto& kv){
                const auto it = rdecay.subtypes.find(kv.first);
                if (it == rdecay.subtypes.end() || !kv.second.assignableFrom(it->second)) {
                    return false;
                }
                return true;
            });
        } else if (obj->category == TypeCategory::SUPERSET) {
            if (ldecay.subtypes.size() <= rdecay.subtypes.size()) return false;
            return std::all_of(ldecay.subtypes.begin(), ldecay.subtypes.end(), [&rdecay](const auto& kv){
                const auto it = rdecay.subtypes.find(kv.first);
                if (it == rdecay.subtypes.end() || !kv.second.assignableFrom(it->second)) {
                    return false;
                }
                return true;
            });
        } else if (obj->category == TypeCategory::SUBSET) {
            return false; //TODO actually implement
        }

        return false;
    }
}

#undef NULL
std::ostream &statics::operator<<(std::ostream &os, const Type &type) {
    static int tab_depth = 0;

    switch (type.category) {
        case TypeCategory::INT:
            return os << "Int";
        case TypeCategory::FLOAT:
            return os << "Float";
        case TypeCategory::BOOL:
            return os << "Bool";
        case TypeCategory::NULL:
            return os << "Null";
        case TypeCategory::OBJECT:
            os << "Object:";
            tab_depth++;
            for (const auto& subtype : type.subtypes) {
                os << '\n' << std::string(tab_depth * 2, ' ');
                os << util::string_hash::reverseHash(subtype.first) << ": ";
                os << subtype.second;
            }
            tab_depth--;
            break;
        case TypeCategory::REF:
            return os << "Ref to " << type.subtypes.at(0);
        case TypeCategory::ARRAY:
            return os << "Array of " << type.subtypes.at(0);
        case TypeCategory::TUPLE:
            break;
        case TypeCategory::SUPERSET:
            return os << "Superset of " << type.subtypes.at(0);
        case TypeCategory::SUBSET:
            return os << "Subset of " << type.subtypes.at(0);
        case TypeCategory::CONJUNCTION:
            break;
        case TypeCategory::DISJUNCTION:
            break;
    }

    return os;
}

Type statics::typeFromASTType(const ast::AST& ast, const ast::TypeIdentifier* ast_type) {
    Type type;
    switch (ast_type->op) {
        case ast::TypeOperator::BASIC: {
            type.category = TypeCategory::OBJECT;
            const ast::Type *obj_type = resolveType(ast, ast_type->id);
            if (obj_type->name == ast::Integer.name) {
                type.category = TypeCategory::INT;
            } else if (obj_type->name == ast::Float.name) {
                type.category = TypeCategory::FLOAT;
            } else if (obj_type->name == ast::Bool.name) {
                type.category = TypeCategory::BOOL;
            } else if (obj_type->name == ast::Null.name) {
                type.category = TypeCategory::NULL;
            } else {
                for (const auto& member : obj_type->attributes) {
                    type.subtypes.emplace(member.name.getHash(), typeFromASTType(ast, member.type.get()));
                }
            }

            break;
        } case ast::TypeOperator::SUBSET:
            type.category = TypeCategory::SUBSET;
            type.subtypes.emplace(0, typeFromASTType(ast, ast_type->other_types.at(0).get()));
            break;
        case ast::TypeOperator::SUPERSET:
            type.category = TypeCategory::SUPERSET;
            type.subtypes.emplace(0, typeFromASTType(ast, ast_type->other_types.at(0).get()));
            break;
        case ast::TypeOperator::REFERENCE:
            type.category = TypeCategory::REF;
            type.subtypes.emplace(0, typeFromASTType(ast, ast_type->other_types.at(0).get()));
            break;
        case ast::TypeOperator::CONJUNCTION:
            type.category = TypeCategory::CONJUNCTION;
            type.subtypes.emplace(0, typeFromASTType(ast, ast_type->other_types.at(0).get()));
            type.subtypes.emplace(1, typeFromASTType(ast, ast_type->other_types.at(1).get()));
            break;
        case ast::TypeOperator::DISJUNCTION:
            type.category = TypeCategory::DISJUNCTION;
            type.subtypes.emplace(0, typeFromASTType(ast, ast_type->other_types.at(0).get()));
            type.subtypes.emplace(1, typeFromASTType(ast, ast_type->other_types.at(1).get()));
            break;
        case ast::TypeOperator::TUPLE:
            type.category = TypeCategory::TUPLE;
            type.subtypes.emplace(0, typeFromASTType(ast, ast_type->other_types.at(0).get()));
            break;
        case ast::TypeOperator::ARRAY:
            type.category = TypeCategory::ARRAY;
            type.subtypes.emplace(0, typeFromASTType(ast, ast_type->other_types.at(0).get()));
            break;
    }

    return type;
}

Type statics::referenceTo(const Type &other) {
    if (other.category != TypeCategory::REF) {
        Type type;
        type.category = TypeCategory::REF;
        type.subtypes.emplace(0, other);
        return type;
    } else {
        return other;
    }
}

#define NULL 0
