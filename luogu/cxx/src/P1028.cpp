//
// Created by hoshino on 18-10-7.
//

#ifndef LUOGU_1028_HPP
#define LUOGU_1028_HPP

#include <iostream>

#define MAX 1001

int cache[MAX];

auto add(const int &max) -> int {
	if (cache[max] == - 1) {
		int count = 1;
		for (int i = 1; i <= max; ++ i) {
			int _max = i / 2;
			count += _max ? add(_max) : 1;
		}

		cache[max] = count;

		return count;
	} else return cache[max];
}

auto main(int, char **) -> int {
	for (int &i : cache) {
		i = - 1;
	}

	int n;
	std::cin >> n;
	std::cout << add(n / 2) << std::endl;

	return 0;
}

#endif //LUOGU_1028_HPP
