//
// Created by hoshino on 18-12-15.
//

#ifndef LUOGU_KRUSKAL_HPP
#define LUOGU_KRUSKAL_HPP

#include <bits/stdc++.h>

#define INF 65535
#define MAX 9

using T = int;
using Graph = T **;

struct Edge {
	size_t begin;
	size_t end;
	T weight;

	auto to_string() const -> std::string {
		return "(" + std::to_string(begin) + ", " + std::to_string(end) + ") = " + std::to_string(weight);
	}
};

auto find(const int *parent, int f) -> int {
	while (parent[f] > 0) f = parent[f];
	return f;
}

auto miniSpanTree(const std::vector<Edge> &edges) -> void {
	int parents[MAX];
	// std::memset(parents, 0, sizeof(size_t) * MAX);

	for (auto &v : parents) v = -1;

	for (const auto &edge : edges) {
		int n = find(parents, edge.begin);
		int m = find(parents, edge.end);

		if (n == -1) n = 0;
		if (m == -1) m = 0;

		if (n != m) {
			std::cout << edge.to_string() << std::endl;
			parents[n] = m;
		}
	}

	for (auto &v : parents) std::cout << v << " ";
	std::cout << std::endl;
}

auto main(int, char **) -> int {
	Graph graph = new int*[MAX] {
			new int[MAX] {   0,  10, INF, INF, INF,  11, INF, INF, INF },
			new int[MAX] {  10,   0,  18, INF, INF, INF,  16, INF,  12 },
			new int[MAX] { INF,  18,   0,  22, INF, INF, INF, INF,   8 },
			new int[MAX] { INF, INF,  22,   0,  20, INF, INF,  16,  21 },
			new int[MAX] { INF, INF, INF,  20,   0,  26, INF,   7, INF },
			new int[MAX] {  11, INF, INF, INF,  26,   0,  17, INF, INF },
			new int[MAX] { INF,  16, INF, INF, INF,  17,   0,  19, INF },
			new int[MAX] { INF, INF, INF,  16,   7, INF,  19,   0, INF },
			new int[MAX] { INF,  12,   8,  21, INF, INF, INF, INF,   0 },
	};

	std::vector<Edge> edges;
	for (size_t i = 0; i < MAX; ++ i) {
		for (size_t j = i + 1; j < MAX; ++ j) {
			if (graph[i][j] != INF && graph[i][j] > 0) edges.push_back({i, j, graph[i][j]});
		}
	}

	std::sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) { return a.weight < b.weight; });

	std::cout << std::endl;

	miniSpanTree(edges);

	return 0;
}

#endif //LUOGU_KRUSKAL_HPP
