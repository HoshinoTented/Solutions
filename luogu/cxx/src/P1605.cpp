#ifndef LUOGU_P1605_HPP
#define LUOGU_P1605_HPP

#include <bits/stdc++.h>

using T = size_t;
using V = int;
using Line = V *;
using Graph = Line *;
using Pos = std::pair<T, T>;

auto get(Graph graph, const Pos &pos) -> V & {
	return graph[pos.first][pos.second];
}

auto visit(Graph graph, const Pos &pos) -> V & {
	auto &v = get(graph, pos);
	v = 2;

	return v;
}

auto unvisit(Graph graph, const Pos &pos) -> void {
	get(graph, pos) = 1;
}

auto canVisit(Graph graph, const Pos &len, const Pos &pos) -> bool {
	return ! (pos.first < 0 || pos.first >= len.first || pos.second < 0 || pos.second >= len.second || get(graph, pos) != 1);
}

auto moveUp(Pos pos) -> Pos {
	pos.first -= 1;
	return pos;
}

auto moveDown(Pos pos) -> Pos {
	pos.first += 1;
	return pos;
}

auto moveLeft(Pos pos) -> Pos {
	pos.second -= 1;
	return pos;
}

auto moveRight(Pos pos) -> Pos {
	pos.second += 1;
	return pos;
}

/**
 * 0 为障碍
 * 1 为通路
 * 2 为已访问过的通路
 * @param graph
 * @return
 */
auto dfs(Graph graph, const Pos &len, Pos pos, const Pos &end) -> int {
	if (canVisit(graph, len, pos)) {
		if (pos == end) {
			return 1;
		}

		visit(graph, pos);

		auto result = dfs(graph, len, moveUp(pos), end)
					  + dfs(graph, len, moveLeft(pos), end)
					  + dfs(graph, len, moveRight(pos), end)
					  + dfs(graph, len, moveDown(pos), end);

		unvisit(graph, pos);

		return result;
	}

	return 0;
}

auto main(int, char **) -> int {
	T n, m, t;
	T sX, sY, eX, eY;
	std::cin >> n >> m >> t >> sX >> sY >> eX >> eY;

	int **g = new int *[n];
	for (T i = 0; i < n; ++ i) {
		int *line = new int[m];

		for (T j = 0; j < m; ++ j) {
			line[j] = 1;
		}

		g[i] = line;
	}

	for (T i = 0; i < t; ++ i) {
		T x, y;
		std::cin >> x >> y;
		g[x - 1][y - 1] = 0;
	}

	std::cout << dfs(g, Pos{n, m}, Pos{sX - 1, sY - 1}, Pos{eX - 1, eY - 1}) << std::endl;

	return 0;
}

#endif