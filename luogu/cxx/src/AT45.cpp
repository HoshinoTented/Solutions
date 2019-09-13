//
// Created by hoshino on 18-8-26.
//

#ifndef LUOGU_45_H
#define LUOGU_45_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

auto main(int argc, char *argv[]) -> int {
	int n, a, b, c, d;
	a = b = c = d = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		char tmp;
		std::cin >> tmp;
		switch (tmp) {
			case '1': ++ a; break;
			case '2': ++ b; break;
			case '3': ++ c; break;
			case '4': ++ d; break;
			default: throw "Unknown input";
		}
	}

	std::vector<int> v{a, b, c, d};
	std::sort(v.begin(), v.end());

	std::cout << *--v.cend() << " " << *v.cbegin() << std::endl;

	return 0;
}

#endif //LUOGU_45_H
