#ifndef LUOGU_P3367_HPP
#define LUOGU_P3367_HPP

#include <bits/stdc++.h>

auto find(int *set, int a) -> int {
	if (set[a] == a) return a;
	return set[a] = find(set, set[a]);
}

auto main(int, char **) -> int {
	int n, m;
	std::cin >> n >> m;

	int set[10001];
	for (int i = 0; i < 10001; ++ i) {
		set[i] = i;
	}

	for (int i = 0; i < m; ++ i) {
		int a, x, y;
		std::cin >> a >> x >> y;

		int m = find(set, x);
		int n = find(set, y);

		if (a == 2) {
			std::cout << (m == n ? "Y" : "N") << std::endl;
		} else {
			set[m] = n;
		}
	}

	return 0;
}

#endif