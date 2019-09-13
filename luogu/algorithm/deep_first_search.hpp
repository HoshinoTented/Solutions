//
// Created by hoshino on 18-10-21.
//

#ifndef LUOGU_DEEP_FIRST_SEARCH_HPP
#define LUOGU_DEEP_FIRST_SEARCH_HPP

#include <iostream>

auto dfs(int **graph, bool *visited, const int &len, const int &current, void (*action)(const int &)) -> void {
	visited[current] = true;
	action(current);

	for (int i = 0; i < len; ++ i) {
		if (graph[current][i] && ! visited[i]) dfs(graph, visited, len, i, action);
	}
}

auto main(int, char **) -> int {
	int **graph = new int *[4]{
			new int[4]{0, 1, 1, 1},
			new int[4]{1, 0, 1, 0},
			new int[4]{1, 1, 0, 1},
			new int[4]{1, 0, 1, 0},
	};

	dfs(graph, new bool[4], 4, 0, [](const int &i) -> void { std::cout << i << std::endl; });

	return 0;
}

#endif //LUOGU_DEEP_FIRST_SEARCH_HPP
