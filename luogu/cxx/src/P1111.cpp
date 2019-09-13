//
// Created by Administrator on 2019/8/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 1001

struct road {
	int from, to, time;

	auto operator<(const road &other) const -> bool {
		return time < other.time;
	}
};

struct uf {
	int set[MAXN];

	uf() {
		for (int i = 0; i < MAXN; ++ i) {
			set[i] = i;
		}
	}

	auto find(int i) -> int {
		return i == set[i] ? i : set[i] = find(set[i]);
	}

	auto concat(int a, int b) -> void {
		set[find(a)] = find(b);
	}
};

int vCount, rCount;
std::vector<road> roads;
uf set{};

auto check() -> bool {
	int last = set.find(1);

	for (int i = 2; i <= vCount; ++ i) {
		if (set.find(i) != last) return false;
	}

	return true;
}

auto main(int, char **) -> int {
	std::cin >> vCount >> rCount;

	for (int i = 0; i < rCount; ++ i) {
		road r{};
		std::cin >> r.from >> r.to >> r.time;

		roads.push_back(r);
	}

	std::sort(roads.begin(), roads.end());

	for (road &r : roads) {
		set.concat(r.from, r.to);

		if (check()) {
			std::cout << r.time << std::endl;
			return 0;
		}
	}

	std::cout << - 1 << std::endl;

	return 0;
}