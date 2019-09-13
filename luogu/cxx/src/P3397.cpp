//
// Created by Administrator on 2019/8/17.
//

#include <iostream>

#define MAXN 1001

namespace P3397 {
	struct pos {
		int x, y;
	};

	int n, m;
	int range[MAXN][MAXN];

	auto rangeAdd(pos start, pos end) -> void {
		for (int x = start.x; x <= end.x; ++ x) {
			range[x][start.y] += 1;
			range[x][end.y + 1] -= 1;
		}
	}

	auto generate() -> void {
		for (int i = 0; i < n; ++ i) {
			int last = range[i][0];
			std::cout << last << " ";

			for (int j = 1; j < n; ++ j) {
				std::cout << last + range[i][j] << " ";
				last = last + range[i][j];
			}

			std::cout << std::endl;
		}
	}

	auto main() -> void {
		std::cin >> n >> m;

		for (int i = 0; i < m; ++ i) {
			int sx, sy, ex, ey;
			std::cin >> sx >> sy >> ex >> ey;

			rangeAdd({sx - 1, sy - 1}, {ex - 1, ey - 1});
		}

		generate();
	}
}

auto main(int, char **) -> int {
	P3397::main();

	return 0;
}