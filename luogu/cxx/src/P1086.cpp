//
// Created by hoshino on 18-12-18.
//

#ifndef LUOGU_P1086_HPP
#define LUOGU_P1086_HPP

#include <bits/stdc++.h>

struct position : public std::pair<int, int> {
	int value;

	position(const int &x, const int &y, const int &value) : pair(x, y), value(value) {}
};

auto checkTimedOut(const position &pos, const int &tl) -> bool {
	return pos.first + 1 <= tl;
}

auto moveTo(const position &from, const position &to, const int &tl) -> int {
	return tl - (std::abs(from.first - to.first) + std::abs(from.second - to.second));
}

auto pick(const std::vector<position> &plants, const std::vector<position>::const_iterator &it, const int &tl) -> int {
	if (plants.end() != it && checkTimedOut(*it, tl - 1)) {
		auto newIt = it + 1;
		return it->value + pick(plants, newIt, moveTo(*it, *newIt, tl) - 1);
	} else return 0;
}

auto main(int, char **) -> int {
	int m, n, tl;
	std::cin >> m >> n >> tl;

	std::vector<position> plants;

	for (int i = 0; i < m; ++ i) {
		for (int j = 0; j < n; ++ j) {
			int v;
			std::cin >> v;
			if (v != 0) {
				plants.push_back(position(i, j, v));
			}
		}
	}

	std::sort(plants.begin(), plants.end(), [](const position &a, const position &b) { return a.value > b.value; });

	std::cout << pick(plants, plants.begin(), tl - plants[0].first - 1) << std::endl;

	return 0;
}

#endif //LUOGU_P1086_HPP
