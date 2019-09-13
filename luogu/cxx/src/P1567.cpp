//
// Created by hoshino on 18-10-2.
//

#ifndef LUOGU_1567_HPP
#define LUOGU_1567_HPP

#include <iostream>

auto main(int, char **) -> int {
	unsigned int max = 0, tmp = 0, lst = 0, c;
	std::cin >> c;

	for (unsigned int i = 0; i < c; ++ i) {
		unsigned int t;
		std::cin >> t;
		++ tmp;
		if (t < lst) {
			if (max < tmp) max = tmp;
			tmp = 0;
		}

		lst = t;
	}

	std::cout << max << std::endl;

	return 0;
}

#endif //LUOGU_1567_HPP
