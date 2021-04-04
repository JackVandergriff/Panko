//
// Created by jack on 3/22/21.
//

#include "panko_resolver.h"
#include "panko_scope.h"

#include <numeric>

using namespace panko;
using namespace panko::statics;

const ast::Variable* statics::resolveVar(const ast::AST &ast, const ast::Identifier& id) {
    const auto& context = id.context.getContext();
    const auto func_it = std::find_if(context.rbegin(), context.rend(), [](const auto& scope){
        return scope.starts_with(scope::getScopeChar(scope::ScopeType::FUNCTION));
    });

    if (func_it != context.rend()) {
        // Accumulate context up until function name, then append function name sans initial 'F'
        const auto func_str = std::accumulate(context.begin(), func_it.base() - 1, std::string{}, [](const auto& lhs, const auto& rhs){
           return lhs + rhs + '.';
        }) + (func_it->data() + 1);
        const ast::Function* func_ptr = ast.functions.get(util::string_hash{func_str}.getHash());

        for (const auto& param : func_ptr->parameters) {
            if (param.name == util::string_hash{id.identifier}) {
                return &param;
            }
        }
    }

    const auto [hash, var] = id.context.lookup(id.identifier, ast.variables);
    if (var) {
        return var;
    } else {
        return nullptr;
    }
}

const ast::Type* statics::resolveType(const ast::AST &ast, const ast::Identifier &id) {
    const auto [hash, type] = id.context.lookup(id.identifier, ast.types);
    if (type) {
        return type;
    } else {
        return nullptr;
    }
}