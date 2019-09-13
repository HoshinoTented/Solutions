//
// Created by hoshino on 18-10-22.
//

#ifndef LUOGU_BREADTH_FIRST_SEARCH_HPP
#define LUOGU_BREADTH_FIRST_SEARCH_HPP

#include <iostream>
#include <queue>

using T = int;

T **graph;
bool *visited;
std::queue<T> q;

auto bfs(const int &len, void (*action)(const T &)) -> void {
	int i = 0;
	for (i = 0; i < len; ++ i) {	//这个 for 的意义大概是图可能不是连通图
		if (! visited[i]) {
			visited[i] = true;
			q.push(i);

			action(i);

			while (! q.empty()) {
				i = q.front();
				q.pop();

				for (int j = 0; j < len; ++ j) {
					if (graph[i][j] && ! visited[j]) {
						visited[j] = true;
						q.push(j);

						action(j);
					}
				}
			}
		}
	}
}

auto main(int, char **) -> int { 
	constexpr int size = 9;

	graph = new T*[size] {
		new T[size]{0, 1, 0, 0, 0, 1, 0, 0, 0},
		new T[size]{1, 0, 1, 0, 0, 0, 1, 0, 1},
		new T[size]{0, 1, 0, 1, 0, 0, 0, 0, 1},
		new T[size]{0, 0, 1, 0, 1, 0, 1, 1, 1},
		new T[size]{0, 0, 0, 1, 0, 1, 0, 1, 0},
		new T[size]{1, 0, 0, 0, 1, 0, 1, 0, 0},
		new T[size]{0, 1, 0, 1, 0, 1, 0, 1, 0},
		new T[size]{0, 0, 0, 1, 1, 0, 1, 0, 0},
		new T[size]{0, 1, 1, 1, 0, 0, 0, 0, 0}
	};

	visited = new bool[size];
	q = std::queue<T>();

	bfs(size, [](const int& v) { std::cout << v << std::endl; });

	return 0;
}

#endif //LUOGU_BREADTH_FIRST_SEARCH_HPP
