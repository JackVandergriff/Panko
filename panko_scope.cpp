//
// Created by jack on 2/19/21.
//

#include "panko_scope.h"

using namespace panko::scope;
using namespace panko;

void Context::pop() {
    context.pop_back();
}

void Context::push(const std::string& name) {
    context.push_back(name);
}

void Context::push_unique(const std::string& name) {
    context.push_back(name + std::to_string(id++));
}

util::Finally Context::push_local(const std::string& name) {
    push(name);
    return util::Finally{[this](){pop();}};
}

util::Finally Context::push_unique_local(const std::string& name) {
    push_unique(name);
    return util::Finally{[this](){pop();}};
}


[[nodiscard]] std::string Context::mangle(const std::string& name) const {
    std::string ret_val;

    for (auto& scope : context) {
        ret_val += scope + '.';
    }

    return ret_val + name;
}
