//
// Created by jack on 2/19/21.
//

#include "panko_scope.h"

#include <numeric>

using namespace panko::scope;
using namespace panko;

void Context::pop() {
    context.pop_back();
}

void Context::push(const std::string& name, ScopeType type) {
    context.push_back(getScopeChar(type) + name);
}

void Context::push_unique(const std::string& name, ScopeType type) {
    context.push_back(getScopeChar(type) + name + std::to_string(id++));
}

util::Finally Context::push_local(const std::string& name, ScopeType type) {
    push(name, type);
    return util::Finally{[this](){pop();}};
}

util::Finally Context::push_unique_local(const std::string& name, ScopeType type) {
    push_unique(name, type);
    return util::Finally{[this](){pop();}};
}


[[nodiscard]] std::string Context::mangle(const std::string& name) const {
    std::string ret_val;

    return std::accumulate(context.begin(), context.end(), std::string{}, [](const auto& lhs, const auto& rhs){
        return lhs + rhs + '.';
    }) + name;
}

const std::vector<std::string> &Context::getContext() const {
    return context;
}

char scope::getScopeChar(ScopeType scope) {
    switch (scope) {
        case ScopeType::FUNCTION:
            return 'F';
        case ScopeType::BLOCK:
            return 'B';
        case ScopeType::MODULE:
            return 'M';
    }
}
