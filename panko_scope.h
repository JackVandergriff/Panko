//
// Created by jack on 2/2/21.
//

#ifndef PANKO_SCOPE_H
#define PANKO_SCOPE_H

#include "panko_util.h"

#include <vector>

namespace panko::scope {
    enum class Type {
        MODULE, FUNCTION, TYPE, BLOCK
    };

    struct HashFailure : util::Exception {
        using util::Exception::Exception;
    };

    class Context {
    private:
        std::vector<std::string> context;
        static inline int id = 0;

        static char getTypeChar(Type type) {
            switch(type) {
                case Type::MODULE:
                    return 'M';
                case Type::FUNCTION:
                    return 'F';
                case Type::TYPE:
                    return 'T';
                case Type::BLOCK:
                    return 'B';
            }
        }

    public:
        void push(Type type, const std::string& name) {
            context.push_back(getTypeChar(type) + name);
        }

        void push(Type type) {
            context.push_back(getTypeChar(type) + std::to_string(id++));
        }

        void pop() {
            context.pop_back();
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
                    std::cout << "Name found: " << ret_val + name << '\n';
                    return {hash, ptr};
                }
            }

            throw HashFailure{"Unable to find qualified name in " + mangle(name)};
        }
    };
}

#endif //PANKO_SCOPE_H
