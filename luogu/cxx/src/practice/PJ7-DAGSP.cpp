#include <iostream>
#include <algorithm>

#define MAXN 10001
#define MAGIC 19260817

int n, m;
int graph[MAXN][MAXN];
int shortest[MAXN];     // shortest[n] 代表 0 到 n 的最短距离

auto dp() -> void {
	for (int i = 0; i < n; ++ i) {
		shortest[i] = MAGIC;
	}

	shortest[0] = 0;

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			if (graph[i][j] != MAGIC) {
				shortest[j] = std::min(shortest[j], shortest[i] + graph[i][j]);
				printf("shortest[%d] = %d\n", j, shortest[j]);
			}
		}
	}
}

auto main(int, char **) -> int {
	std::cin >> n >> m;

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			graph[i][j] = MAGIC;
		}
	}

	for (int i = 0; i < m; ++ i) {
		int from, to, weight;
		std::cin >> from >> to >> weight;
		graph[from][to] = weight;
	}

	dp();

	std::cout << shortest[n - 1] << std::endl;

	return 0;
}