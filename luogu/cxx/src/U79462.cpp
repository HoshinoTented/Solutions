#include <algorithm>
#include <iostream>

int line_bit[9][9], line[30], n, ans;

auto one_count(int x) -> int {
	int count = 0;

	for (int i = 0; i < 32; ++ i) {
		if (x & (1 << i)) count ++;
	}

	return count;
}

auto dfs(int bits, int i) -> void {
	if (i == n + 1) {
		ans = std::max(ans, one_count(bits));
	} else {
		dfs(bits, i + 1);               // 跳过此边
		if (bits & line[i]) return;     // 如果有边相同，则直接返回
		dfs(bits ^ line[i], i + 1);     // 如果没有，加入此边
	}
}

auto main(int, char **) -> int {
	int bit = 0;
	for (int i = 1; i <= 7; ++ i) {
		for (int j = i + 1; j <= 8; ++ j) {
			line_bit[i][j] = line_bit[j][i] = 1 << (bit ++);
		}
	}

	std::cin >> n;

	for (int i = 1; i <= n; ++ i) {
		int m, last;
		std::cin >> m >> last;

		for (int j = 1; j < m; ++ j) {
			int cur;
			std::cin >> cur;
			line[i] |= line_bit[last][cur];
			last = cur;
		}
	}

	dfs(0, 1);

	std::cout << ans << std::endl;

	return 0;
}