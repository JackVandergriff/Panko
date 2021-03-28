//
// Created by jack on 3/22/21.
//

#ifndef PANKO_RESOLVER_H
#define PANKO_RESOLVER_H

#include "panko_ast.h"

namespace panko::statics {
    struct Type;

    const ast::Variable* resolveVar(const ast::AST& ast, const ast::Identifier& id);
    const ast::Type* resolveType(const ast::AST& ast, const ast::Identifier& id);
    std::vector<const ast::Function*> resolveFunc(const ast::AST& ast, const ast::Identifier& id);
    const ast::Function* resolveFunc(const ast::AST& ast, const ast::Identifier& id, std::vector<Type> parameters, Type return_type);
}

#endif //PANKO_RESOLVER_H
