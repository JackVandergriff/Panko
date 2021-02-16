//
// Created by jack on 2/2/21.
//

#ifndef PANKO_SCOPE_H
#define PANKO_SCOPE_H

#include "panko_util.h"

#include <vector>

namespace panko::scope {

    struct HashFailure : util::Exception {
        using util::Exception::Exception;
    };

    class Context {
    private:
        std::vector<std::string> context;
        static inline int id = 0;
    public:
        void pop() {
            context.pop_back();
        }

        void push(const std::string& name) {
            context.push_back(name);
        }

        void push_unique(const std::string& name) {
            context.push_back(name + std::to_string(id++));
        }

        util::Finally push_local(const std::string& name) {
            push(name);
            return util::Finally{[this](){pop();}};
        }

        util::Finally push_unique_local(const std::string& name) {
            push_unique(name);
            return util::Finally{[this](){pop();}};
        }


        [[nodiscard]] std::string mangle(const std::string& name) const {
            std::string ret_val;

            for (auto& scope : context) {
                ret_val += scope + '.';
            }

            return ret_val + name;
        }

        template<typename T>
        std::tuple<size_t, const T*> lookup(const std::string& name, const util::hasher<T>& hasher) const {
            for (auto end = context.end(); end >= context.begin(); end--) {
                std::string ret_val;
                for (auto scope = context.begin(); scope < end; scope++) {
                    ret_val += *scope + '.';
                }

                auto hash = std::hash<T>{}(T{ret_val + name});
                if (auto ptr = hasher.get(hash)) {
                    return {hash, ptr};
                }
            }

            return {0, nullptr};
        }
    };
}

#endif //PANKO_SCOPE_H
