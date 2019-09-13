//
// Created by hoshino on 18-9-9.
//

#ifndef LUOGU_1914_HPP
#define LUOGU_1914_HPP

#include <iostream>
#include <string>

auto move(std::string::iterator &it, const unsigned int &moveCount) -> void {
	int c = *it + moveCount;
	while (c > 'z') {
		c = 'a' + c - 'z' - 1;
	}

	*it = static_cast<char>(c);
}

auto main(int, char **) -> int {
	unsigned int moveBit;
	std::string code;
	std::cin >> moveBit >> code;

	for (auto it = code.begin(); it != code.end(); ++ it) {
		move(it, moveBit);
	}

	std::cout << code << std::endl;

	return 0;
}

#endif //LUOGU_1914_HPP
