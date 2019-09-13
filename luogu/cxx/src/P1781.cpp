//
// Created by hoshino on 18-9-16.
//

#ifndef LUOGU_1781_HPP
#define LUOGU_1781_HPP

#include <iostream>
#include <string>

// return a > b;
auto compare(const std::string &a, const std::string &b) -> bool {
	if (a.size() != b.size()) return a.size() > b.size();
	for (auto ai = a.cbegin(), bi = b.cbegin(); ai != a.cend(); ++ ai, ++ bi) {
		if (*ai != *bi) return *ai > *bi;
	}

	return false;
}

auto main(int, char **) -> int {
	int m;
	int id = 0;
	std::string max = "0";
	std::cin >> m;

	for (int i = 0; i < m; ++ i) {
		std::string tmp;
		std::cin >> tmp;
		if (compare(tmp, max)) {
			max = tmp;
			id = i + 1;
		}
	}

	std::cout << id << std::endl;
	std::cout << max;

	return 0;
}

#endif //LUOGU_1781_HPP
