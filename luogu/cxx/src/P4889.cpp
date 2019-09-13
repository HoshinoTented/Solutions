//
// Created by hoshino on 18-9-23.
// TODO TLE

#ifndef LUOGU_4889_HPP
#define LUOGU_4889_HPP

#include <iostream>
#include <hash_map>

using length = size_t;

// b竹竿的高度 -> g竹竿的高度 -> 竹竿之间的距离 -> 顶端是否重叠
auto check(const length &bl, const length &gl, const length &length) -> bool {
	return bl == gl - length || gl == bl - length || bl + gl == length;
}

auto main(int, char **) -> int {
	length max, maxH;
	std::cin >> max >> maxH;
	length flags[max];

	for (length i = 0; i < max; ++ i) {
		std::cin >> flags[i];
	}

	int count = 0;
	for (length i = 0; i < max - 1; ++ i) {
		for (length j = i + 1; j < max; ++ j) {
			if (check(i, j, j - i)) ++ count;
		}
	}

	std::cout << count << std::endl;

	return 0;
}

#endif //LUOGU_4889_HPP
