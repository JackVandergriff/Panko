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
    public:
        size_t hash;

        string_hash(const std::string& str): hash{std::hash<std::string>{}(str)} {
            hash_map.emplace(hash, str);
        }

        string_hash(const char* str): hash{std::hash<std::string_view>{}(str)} {
            hash_map.emplace(hash, str);
        }

        explicit operator std::string() const {
            return hash_map.at(hash);
        }

        friend bool operator==(const string_hash& lhs, const string_hash& rhs) {
            return lhs.hash == rhs.hash;
        }

        friend bool operator<(const string_hash& lhs, const string_hash& rhs) {
            return lhs.hash < rhs.hash;
        }
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
    };
}

#endif //PANKO_UTIL_H
