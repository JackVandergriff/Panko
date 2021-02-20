//
// Created by jack on 2/19/21.
//

#include "panko_util.h"

using namespace panko::util;

string_hash::string_hash(const std::string& str): hash{std::hash<std::string>{}(str)} {
    hash_map.emplace(hash, str);
}

string_hash::string_hash(const char* str): hash{std::hash<std::string_view>{}(str)} {
    hash_map.emplace(hash, str);
}

string_hash::operator std::string() const {
    return hash_map.at(hash);
}

size_t string_hash::getHash() const {
    return hash;
}

bool panko::util::operator==(const string_hash& lhs, const string_hash& rhs) {
    return lhs.hash == rhs.hash;
}

bool panko::util::operator<(const string_hash& lhs, const string_hash& rhs) {
    return lhs.hash < rhs.hash;
}