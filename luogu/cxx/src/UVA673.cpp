//
// Created by hoshino on 18-10-24.
//

#ifndef LUOGU_UVA673_HPP
#define LUOGU_UVA673_HPP

#include <iostream>
#include <string>
#include <stack>

bool check(const std::string &str) {
	std::stack<std::string::value_type> s;
	for (const char &c : str) {
		if (c == '(' || c == '[') s.push(c);
		else if ((! s.empty()) && ((c == ')' && s.top() == '(') || (c == ']' && s.top() == '['))) s.pop();
		else return false;
	}

	return s.empty();
}

int main(int n, char **) {
	std::cin >> n;
	for (int i = 0; i < n; ++ i) {
		std::string tmp;
		std::cin >> tmp;
		std::cout << (check(tmp) ? "Yes" : "No") << std::endl;
	}

	return 0;
}

#endif //LUOGU_UVA673_HPP
