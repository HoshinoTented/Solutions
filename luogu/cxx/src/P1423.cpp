//
// Created by hoshino on 18-9-7.
//

#ifndef LUOGU_1423_H
#define LUOGU_1423_H

#include <iostream>

auto main(int, char **) -> int {
	int step = 0;
	double speed = 2;
	double length = 0.0, target;
	std::cin >> target;

	while (length < target) {
		length += speed;
		++ step;
		speed *= 0.98;
	}

	std::cout << step << std::endl;

	return 0;
}

#endif //LUOGU_1423_H
