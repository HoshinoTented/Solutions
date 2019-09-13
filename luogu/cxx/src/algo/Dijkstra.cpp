#include <iostream>
#include <queue>
#include <vector>

#define MAXN 10001
#define INF 65535

int n;
int graph[MAXN][MAXN];

auto dijkstra(int begin, int target) -> int {
	bool visited[MAXN] = {false};
	int shortest[MAXN] = {INF};

	for (int i = 1; i <= n; ++ i) {
		shortest[i] = INF;
	}

	std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

	shortest[begin] = 0;
	queue.push(begin);

	while (! queue.empty()) {
		int index = queue.top();
		queue.pop();

		if (! visited[index]) {
			visited[index] = true;
			for (int i = 1; i <= n; ++ i) {
				if (shortest[i] > shortest[index] + graph[index][i]) {
					shortest[i] = shortest[index] + graph[index][i];
					queue.push(i);
				}
			}
		}
	}

	return shortest[target];
}

auto main(int, char **) -> int {
	int m;
	std::cin >> n >> m;

	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			graph[i][j] = INF;
		}
	}

	for (int i = 0; i < m; ++ i) {
		int begin, to, weight;
		std::cin >> begin >> to >> weight;

		graph[begin][to] = weight;
		// graph[to][begin] = weight;
	}

	int begin, to;
	std::cin >> begin >> to;

	std::cout << dijkstra(begin, to) << std::endl;

	return 0;
}
