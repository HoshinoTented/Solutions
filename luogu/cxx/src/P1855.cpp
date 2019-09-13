//
// Created by hoshino on 18-9-18.
//

#ifndef LUOGU_1855_HPP
#define LUOGU_1855_HPP

#include <iostream>
#include <vector>
#include <algorithm>

struct Dream {
	int cost, time;

	Dream(const int &cost, const int &time) : cost(cost), time(time) {}
};

auto main(int, char **) -> int {
	int c, m, t;
	std::cin >> c >> m >> t;

	std::vector<Dream> dreams;

	for (int i = 0; i < c; ++ i) {
		int costMoney, costTime;
		std::cin >> costMoney >> costTime;
		dreams.push_back({costMoney, costTime});
	}

	std::sort(dreams.begin(), dreams.end(), [](const Dream &a, const Dream &b) -> bool {
		return a.cost == b.cost ? a.time < b.time : a.cost < b.cost;
	});

	int count = 0;

	for (auto d : dreams) {
		int tmp_m = m - d.cost;
		int tmp_t = t - d.time;

		if (tmp_m < 0 || tmp_t < 0) continue;
		m = tmp_m;
		t = tmp_t;
		++ count;
	}

	std::cout << count << std::endl;

	return 0;
}

#endif //LUOGU_1855_HPP
