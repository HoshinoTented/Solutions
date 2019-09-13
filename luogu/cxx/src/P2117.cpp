//
// Created by hoshino on 18-9-16.
// TODO TLE

#ifndef LUOGU_2117_HPP
#define LUOGU_2117_HPP

#include <iostream>
#include <cmath>

using line_type = unsigned long;

auto horizontal(line_type *m, const int &len, const int &line) -> void {
	m[line] = ~ m[line];
}

auto vertical(line_type *m, const int &len, const int &row) -> void {
	for (int i = 0; i < len; ++ i) {

	}
}

auto eval(line_type *m, const int &len) -> int {
	int sum = 0;
	for (int i = 0; i < len; ++ i) {
		for (int j = 0; j < len; ++ j) {
			sum += m[i][j] * m[j][i];
		}
	}

	return 0;
}

auto main(int, char **) -> int {
	int len, commandCount;
	std::cin >> len >> commandCount;
	line_type matrix[len];

	for (int i = 0; i < len; ++ i) {
		for (int j = 0; j < len; ++ j) {
			int tmp;
			std::cin >> tmp;
			matrix[i] |= static_cast<int>(pow(tmp, len - j - 1));
		}
	}

	for (int i = 0; i < commandCount; ++ i) {
		int id, arg;
		std::cin >> id;
		switch (id) {
			case 1:
				std::cin >> arg;
				horizontal(matrix, len, arg - 1);
				break;
			case 2:
				std::cin >> arg;
				vertical(matrix, len, arg - 1);
				break;
			case 3:
				std::cout << eval(matrix, len);
				break;
			default:
				throw std::runtime_error("Unknown ID");
		}
	}

	return 0;
}

#endif //LUOGU_2117_HPP
