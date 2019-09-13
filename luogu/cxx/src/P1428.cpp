//
// Created by hoshino on 18-10-2.
//

#ifndef LUOGU_1428_HPP
#define LUOGU_1428_HPP

#include <iostream>
#include <vector>

auto main(int, char **) -> int {
	size_t c;
	std::cin >> c;
	std::vector<size_t> v;
	v.reserve(c);

	for (size_t i = 0; i < c; ++ i) {
		size_t tmp, lessCute = 0;
		std::cin >> tmp;
		for (auto cuteValue : v) {
			lessCute += (tmp > cuteValue);
		}

		v.push_back(tmp);

		std::cout << lessCute << " ";
	}

	std::cout << std::endl;


	return 0;
}

#endif //LUOGU_1428_HPP
