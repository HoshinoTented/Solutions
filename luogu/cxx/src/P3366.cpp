//
// Created by hoshino on 18-12-16.
//

#ifndef LUOGU_P3366_HPP
#define LUOGU_P3366_HPP

#include <bits/stdc++.h>
#define INF INT_MAX

using T = int;

struct Edge {
	T begin, end, weight;
};

auto main(int, char **) -> int {
	T n, m;
	std::cin >> n >> m;

	T **graph = new int*[n];

	for (int i = 0; i < n; ++ i) {
		T *line = new int[n];

		for (int j = 0; j < n; ++ j) {
			line[j] = i == j ? 0 : INF;
		}

		graph[i] = line;
	}

	for (T i = 0; i < m; ++ i) {
		T x, y, w;
		std::cin >> x >> y >> w;
		if (x != y && w < graph[x - 1][y - 1]) {
			graph[x - 1][y - 1] = w;
			graph[y - 1][x - 1] = w;
		}
	}

	Edge edges[n];
	int sum = 0;

	for (T i = 1; i < n; ++ i) {
		edges[i] = {0, i, graph[0][i]};
	}

	for (T i = 1; i < n; ++ i) {
		int min = INF;
		int v = 0;

		for (int j = 1; j < n; ++ j) {
			if (edges[j].weight != 0 && edges[j].weight < min) {
				min = edges[j].weight;
				v = j;
			}
		}

		sum += edges[v].weight;
		edges[v].weight = 0;

		for (int j = 1; j < n; ++ j) {
			if (edges[j].weight != 0 && graph[v][j] < edges[j].weight) {
				edges[j] = { v, j, graph[v][j] };
			}
		}
	}

	for (T i = 1; i < n; ++ i) {
		auto &edge = edges[i];
		if (edge.weight != 0) {
			std::cout << "orz" << std::endl;
			return 0;
		}
	}

	std::cout << sum << std::endl;


	return 0;
}

#endif //LUOGU_P3366_HPP
