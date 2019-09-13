//
// Created by hoshino on 18-9-16.
// TODO AC了, 但是想用递归方法做, 试着在 haskell 做这道题吧

#ifndef LUOGU_1739_HPP
#define LUOGU_1739_HPP

#include <iostream>
#include <string>
#include <stack>

auto match(std::string::const_iterator begin, std::string::const_iterator end) -> bool {
	std::stack<std::string::value_type> stack;

	while (begin != end) {
		if (*begin == '(') stack.push(*begin);
		if (*begin == ')') {
			if (! stack.empty() && stack.top() == '(') {
				stack.pop();
			} else return false;
		}

		++ begin;
	}

	return stack.empty();
}

auto main(int, char **) -> int {
	std::string formula;
	std::cin >> formula;

	std::cout << (match(formula.cbegin(), formula.cend()) ? "YES" : "NO") << std::endl;

	return 0;
}

#endif //LUOGU_1739_HPP
