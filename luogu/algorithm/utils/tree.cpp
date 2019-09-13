//
// Created by hoshino on 18-11-13.
//

#include "tree.hpp"

template<typename value_type>
hoshino::tree<value_type>::tree(const value_type &v, tree *l, tree *r) : value(v), l(l), r(r) {}

template<class value_type>
auto hoshino::tree<value_type>::to_string(std::__cxx11::string (*_to_string)(value_type)) const -> std::string {
	auto lS = l ? l->to_string(_to_string) : "null";
	auto rS = r ? r->to_string(_to_string) : "null";
	return "(" + _to_string(value) + " " + lS + " " + rS + ")";
}