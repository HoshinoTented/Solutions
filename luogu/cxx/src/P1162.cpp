//
// Created by hoshino on 18-12-20.
//

#ifndef LUOGU_P1162_HPP
#define LUOGU_P1162_HPP

#include <bits/stdc++.h>

using pos = std::pair<int, int>;

auto renderPos(int **graph, const int &n, const pos &p) -> void {
	if (p.first < 0 || p.second < 0 || p.first >= n || p.second >= n) return;

	if (graph[p.first][p.second] == 0) {
		graph[p.first][p.second] = 2;

		renderPos(graph, n, {p.first - 1, p.second});
		renderPos(graph, n, {p.first + 1, p.second});
		renderPos(graph, n, {p.first, p.second - 1});
		renderPos(graph, n, {p.first, p.second + 1});
	}
}

auto render(int **graph, const int &n) -> void {
	pos *p = nullptr;
	for (int i = 0; i < n && ! p; ++ i) {
		for (int j = 0; j < n && ! p; ++ j) {
			auto &v = graph[i][j];
			if (v) {
				if (graph[i + 1][j] == 0) {
					p = new pos{i + 1, j};
				}
			}
		}
	}

	renderPos(graph, n, *p);
}

auto main(int, char **) -> int {
	int n;
	std::cin >> n;
	int **graph = new int*[n];

	for (int i = 0; i < n; ++ i) {
		auto line = new int[n];
		for (int j = 0; j < n; ++ j) {
			std::cin >> line[j];
		}

		graph[i] = line;
	}

	render(graph, n);

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			std::cout << graph[i][j] << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}

#endif //LUOGU_P1162_HPP
