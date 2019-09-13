//
// Created by hoshino on 18-11-13.
//

#include "range.hpp"

hoshino::range::range(const std::size_t &begin, const std::size_t &end) : pair(begin, end) {}

inline auto hoshino::range::length() const -> std::size_t { return second - first; }