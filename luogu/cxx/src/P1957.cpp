//
// Created by hoshino on 18-8-26.
//

#ifndef LUOGU_1957_H
#define LUOGU_1957_H

#include <iostream>
#include <string>
#include <sstream>

using value_type = int;

std::istream &in = std::cin;
char lastOperator = '\0';

class ComputeResult {
private:
	value_type a, b;
	value_type result;
	char op;
public:
	ComputeResult(const value_type &a, const value_type &b, const char &op) : a(a), b(b), op(op) {
		switch (op) {
			case '+': result = a + b; break;
			case '-': result = a - b; break;
			case '*': result = a * b; break;
			default: throw "UnSupportOperator";
		}
	}

	auto to_string() -> std::string {
		return std::to_string(a) + op + std::to_string(b) + "=" + std::to_string(result);
	}
};

auto to_value(const std::string &str) -> value_type {
	std::stringstream stream;
	stream << str;
	value_type v;
	stream >> v;
	return v;
}

auto computeWithNumber(const char &op, const value_type &a) -> ComputeResult {
	std::string arg;
	in >> arg;
	value_type b = to_value(arg);
	char realOperator;
	switch (op) {
		case 'a': realOperator = '+'; break;
		case 'b': realOperator = '-'; break;
		case 'c': realOperator = '*'; break;
		default: throw "UnSupportOperator";
	}

	return {a, b, realOperator};
}

auto computeWithOperator(const char &op) -> ComputeResult {
	std::string firstArg;
	in >> firstArg;
	return computeWithNumber(op, to_value(firstArg));
}

auto readWithCompute() -> ComputeResult {
	std::string first;
	in >> first;
	if (std::isalpha(*first.cbegin())) {
		lastOperator = *first.cbegin();
		return computeWithOperator(*first.cbegin());
	} else {
		return computeWithNumber(lastOperator, to_value(first));
	}
}

auto main(int argc, char *argv[]) -> int {
	unsigned int n;
	std::cin >> n;

	for (unsigned int i = 0; i < n; ++i) {
		std::string s = readWithCompute().to_string();
		std::cout << s << std::endl;
		std::cout << s.size() << std::endl;
	}

	return 0;
}

#endif //LUOGU_1957_H
