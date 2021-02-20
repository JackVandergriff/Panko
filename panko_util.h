//
// Created by jack on 1/28/21.
//

#ifndef PANKO_UTIL_H
#define PANKO_UTIL_H

#include <string>
#include <functional>
#include <concepts>
#include <exception>
#include <utility>
#include <variant>
#include <set>
#include <map>

namespace panko::ast {
    template<typename T> struct hash;
}

namespace panko::util {
    template<typename T>
    class hasher {
    private:
        struct Comparator {
            using is_transparent = void; // Allows lookup by hash

            bool operator()(const T& lhs, const T& rhs) const {
                return std::hash<T>()(lhs) < std::hash<T>()(rhs);
            }

            bool operator()(const T& lhs, size_t rhs) const {
                return std::hash<T>()(lhs) < rhs;
            }

            bool operator()(size_t lhs, const T& rhs) const {
                return lhs < std::hash<T>()(rhs);
            }
        };

        std::set<T, Comparator> lookup;
    public:
        template<typename... Args>
        size_t make(Args&&... args) {
            return std::hash<T>{}(*(lookup.template emplace(std::forward<Args>(args)...).first));
        }

        template<typename... Args>
        size_t hash(Args&&... args) {
            return std::hash<T>{}(T{std::forward<Args>(args)...});
        }

        const T* get(size_t hash) const {
            const auto iter = lookup.template find(hash);
            if (iter == lookup.end()) {
                return nullptr;
            } else {
                return &(*iter);
            }
        }
    };


    struct string_hash {
    private:
        static inline std::map<size_t, std::string> hash_map{};
        size_t hash;
    public:

        string_hash(const std::string& str);
        string_hash(const char* str);
        explicit operator std::string() const;

        [[nodiscard]] size_t getHash() const;

        friend bool operator==(const string_hash& lhs, const string_hash& rhs);
        friend bool operator<(const string_hash& lhs, const string_hash& rhs);
    };

    template<class... Ts> struct visitor : Ts... { using Ts::operator()...; };
    template<class... Ts> visitor(Ts...) -> visitor<Ts...>;

    template<typename T>
    concept Number = std::is_arithmetic_v<T>;

    template<typename Variant, typename... Args>
    auto visit(Variant&& variant, Args&&... lambdas) {
        return std::visit(visitor{lambdas...}, variant);
    }

    class Exception : public std::exception {
    private:
        const std::string message;
    public:
        [[nodiscard]] const char* what() const noexcept override {
            return message.c_str();
        }

        explicit Exception(std::string message) : message{std::move(message)} {}
    };

    class InvariantAccessException : public Exception {
        using Exception::Exception;
    };

    template<typename... Ts>
    class invariant {
    private:
        std::variant<Ts...> variant;
        bool initialized{true};
    public:
        // Easy constructors, just delegate to std::variant
        invariant() : variant{}, initialized{false} {};

        template<typename T>
        requires (!std::is_same_v<std::remove_cvref_t<T>, invariant>)
        constexpr invariant(T&& t) : variant{std::forward<T>(t)}{}

        template<typename T, typename... Args>
        constexpr explicit invariant(std::in_place_type_t<T>, Args&&... args) :
            variant{std::in_place_type<T>, std::forward<Args>(args)...}{};

        template<typename T, typename U, typename... Args>
        constexpr explicit invariant(std::in_place_type_t<T>, std::initializer_list<U>&& il, Args&&... args) :
            variant{std::in_place_type<T>, std::forward<std::initializer_list<U>>(il), std::forward<Args>(args)...} {};

        template<std::size_t I, typename... Args>
        constexpr explicit invariant(std::in_place_index_t<I>, Args&&... args) :
            variant{std::in_place_index<I>, std::forward<Args>(args)...} {};

        template<std::size_t I, typename U, typename... Args>
        constexpr explicit invariant(std::in_place_index_t<I>, std::initializer_list<U>&& il, Args&&... args) :
            variant{std::in_place_index<I>, std::forward<std::initializer_list<U>>(il), std::forward<Args>(args)...} {};


        // don't allow reassignment from incompatible type
        constexpr invariant(const invariant& other) = default;
        constexpr invariant& operator=(const invariant& other) {
            if (initialized) {
                std::visit(
                        [](auto &current, const auto &other) {
                            if constexpr (std::is_same_v<std::remove_cvref_t<decltype(other)>, std::remove_cvref_t<decltype(current)>>) {
                                current = other;
                            } else {
                                throw InvariantAccessException("Invariant types not equivalent");
                            }
                        },
                        variant, other.variant);
            } else {
                variant = other.variant;
                initialized = true;
            }

            return *this;
        };

        constexpr invariant(invariant&&) noexcept =default;
        constexpr invariant& operator=(invariant&& other) noexcept { // Just calling copy assignment
            *this = other;
            return *this;
        };

        template<typename T>
        requires (!std::is_same_v<std::remove_cvref_t<T>, invariant>)
        constexpr invariant& operator=(T&& t) {
            invariant inv{std::forward<T>(t)};
            *this = inv;
            return *this;
        }

        const std::variant<Ts...>& getVariant() const {
            return variant;
        }

        [[nodiscard]] size_t getIndex() const {
            return variant.index();
        }

        template<typename>
        friend decltype(auto) get(auto&&);
    };

    template<typename T>
    decltype(auto) get(auto&& invariant) {
        return std::get<T>(invariant.variant);
    }

    class Finally {
    private:
        std::function<void()> destructor;
    public:
        template<typename T> requires (!std::is_same_v<std::remove_cvref_t<T>, Finally>)
        explicit Finally(T&& destructor) : destructor{destructor} {}

        ~Finally() {
            destructor();
        }
    };

    template<typename T1, typename T2>
    bool typeEqual(const std::map<T1, T2>& lhs, const std::map<T1, T2>& rhs) {
        return lhs.size() == rhs.size()
            && std::equal(lhs.begin(), lhs.end(), rhs.begin(),
            [](const auto& lhs, const auto& rhs){return lhs.first == rhs.first;});
    }

    template<typename T1, typename T2>
    bool typeSubset(const std::map<T1, T2>& lhs, const std::map<T1, T2>& rhs) {
        if (lhs.size() > rhs.size()) return false;
        for (const auto& kv : lhs) {
            if (rhs.find(kv.first) == rhs.end()) {
                return false;
            }
        }
        return true;
    }

    template<typename T1, typename T2>
    bool typeSuperset(const std::map<T1, T2>& lhs, const std::map<T1, T2>& rhs) {
        return typeSubset(rhs, lhs);
    }
}

#endif //PANKO_UTIL_H
