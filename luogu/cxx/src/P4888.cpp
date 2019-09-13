//
// Created by hoshino on 18-9-23.
//

#ifndef LUOGU_4888_HPP
#define LUOGU_4888_HPP

#include <iostream>
#include <algorithm>

auto readMatrix(const size_t &max) -> char ** {
	char **matrix = new char *[max];
	for (size_t i = 0; i < max; ++ i) {
		char *line = new char[max];
		for (size_t j = 0; j < max; ++ j) {
			std::cin >> line[j];
		}

		matrix[i] = line;
	}

	return matrix;
}

auto isReversed(const std::string &str) -> bool {
	for (auto fromBegin = str.cbegin(), fromEnd = str.cend() - 1; fromBegin != fromEnd; ++ fromBegin, -- fromEnd) {
		if (*fromBegin != *fromEnd) return false;
	}

	return true;
}

auto solveRequest(char **matrix, const size_t &max, const size_t &x, const size_t &y) -> size_t {
	auto closer_v = std::min(x - 0, max - x - 1);
	auto closer_h = std::min(y - 0, max - y - 1);

	size_t maxHLength = 1;
	std::string str(1, matrix[x][y]);
	for (size_t h = 1; h <= closer_h; ++ h) {
		str.insert(str.cbegin(), matrix[x][y - h]);
		str.insert(str.cend(), matrix[x][y + h]);

		if (isReversed(str)) {
			maxHLength = 2 * h + 1;
		}
	}

	size_t maxVLength = 1;
	str = std::string(1, matrix[x][y]);
	for (size_t v = 1; v <= closer_v; ++ v) {
		str.insert(str.cbegin(), matrix[x - v][y]);
		str.insert(str.cend(), matrix[x + v][y]);

		if (isReversed(str)) {
			maxVLength = 2 * v + 1;
		}
	}
	return std::max(maxHLength, maxVLength);
}

auto main(int, char **) -> int {
	size_t max, req;
	std::cin >> max >> req;

	char **matrix = readMatrix(max);

	for (size_t i = 0; i < req; ++ i) {
		size_t x, y;
		std::cin >> x >> y;
		std::cout << solveRequest(matrix, max, x - 1, y - 1) << std::endl;
	}

	return 0;
}

#endif //LUOGU_4888_HPP
