//
// Created by hoshino on 18-8-21.
// TODO

#ifndef LUOGU_1015_H
#define LUOGU_1015_H

#include <iostream>
#include <string>
#include <algorithm>

auto check(const int &i) -> bool {
	std::string str = std::to_string(i);
	std::string old = str;
	std::reverse(str.begin(), str.end());
	return old == str;
}

auto sum_with_self(const int &i) -> int {
	return i + i;
}

auto main(int argc, char *argv[]) -> int {
	int input;
	std::cin >> input;

	for (int i = 1; i <= 30; ++i) {
		input = sum_with_self(input);
		if (check(input)) {
			std::cout << "STEP=" << i + 1 << std::endl;
			return 0;
		}
	}

	std::cout << "Impossible!" << std::endl;

	return 0;
}

#endif //LUOGU_1015_H
