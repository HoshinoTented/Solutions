//
// Created by hoshino on 19-1-6.
//

#ifndef LUOGU_P1219_HPP
#define LUOGU_P1219_HPP

#include <bits/stdc++.h>

bool line[13];        // 列
bool l[25], r[32];        // 对角线, 为什么这里的 r 需要开 32 呢
int n, curAns = 0;
int ans[13];

auto lC(int x, int y) -> bool & {
	bool b = false;
	if (y > x) {		// 原本应该是 y < x 的, 但是最后一个点会 TLE, 不知道为什么
		b = true;
		std::swap(x, y);
	}

	return l[n - y + x - 1 + (b ? n : 0)];
}

auto rC(int x, int y) -> bool & {
	return r[x + y];
}

auto dfs(const int &x) -> void {
	if (x == n) {
		if (curAns < 3) {
			for (int i = 0; i < n; ++ i) {
				std::cout << ans[i] + 1 << " ";
			}

			std::cout << std::endl;
		}

		++ curAns;
		return;
	}

	for (int y = 0; y < n; ++ y) {
		auto &r_lC = lC(x, y);
		auto &r_rC = rC(x, y);

		if (! (line[y] || r_lC || r_rC)) {
			line[y] = r_lC = r_rC = true;
			ans[x] = y;
			dfs(x + 1);
			ans[x] = - 1;
			line[y] = r_lC = r_rC = false;
		}
	}
}

auto main(int, char **) -> int {
	std::cin >> n;

	dfs(0);

	std::cout << curAns << std::endl;

	return 0;
}

#endif //LUOGU_P1219_HPP
