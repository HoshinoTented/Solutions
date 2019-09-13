//
// Created by hoshino on 18-9-7.
//

#ifndef LUOGU_1424_HPP
#define LUOGU_1424_HPP

#include <iostream>

#define LOD (150 + 100)

auto main(int, char **) -> int {
	int day, step, length = 0;
	std::cin >> day >> step;

	for (int i = 0; i < step; ++i) {
		if (day != 6 && day != 7) length += LOD;
		if (day == 7) day = 1; else ++ day;
	}

	std::cout << length << std::endl;

	return 0;
}

#endif //LUOGU_1424_HPP
