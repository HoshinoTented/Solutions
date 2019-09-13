//
// Created by hoshino on 18-10-2.
//

#ifndef LUOGU_1008_HPP
#define LUOGU_1008_HPP

#include <iostream>
#include <string>

auto isunique(const int &i, const int &j, const int &k) -> bool {
	bool c[9];

	for (auto b : std::to_string(i) + std::to_string(j) + std::to_string(k)) {
		if (b != '0' && ! c[b - '1']) {
			c[b - '1'] = true;
		} else return false;
	}

	return true;
}

auto main(int, char **) -> int {
	for (int i = 123; i <= 987; ++ i) {
		int a = i * 2;
		int b = i * 3;

		if (isunique(i, a, b)) std::cout << i << " " << a << " " << b << std::endl;
	}

	return 0;
}

#endif //LUOGU_1008_HPP
