#include <iostream>
#include <queue>

#define MAXN 1000

int n, m;
int sideX[] = {- 1, 1, 0, 0}, sideY[] = {0, 0, - 1, 1};
int colorCount[100002];
int map[MAXN][MAXN];

auto checkIndex(std::pair<int, int> pos) -> bool {
	return 0 <= pos.first && pos.first < n && 0 <= pos.second && pos.second < n;
}

auto bfs(std::pair<int, int> pos, int id) -> void {
	std::queue<std::pair<int, int>> q;
	q.push(pos);

	int count = 0;

	while (! q.empty()) {
		auto cur = q.front();
		q.pop();

		auto &curId = map[cur.first][cur.second];

		if (curId >= 2) continue;

		for (int i = 0; i < 4; ++ i) {
			std::pair<int, int> targetPos = {sideX[i] + cur.first, sideY[i] + cur.second};

			if (! checkIndex(targetPos)) continue;

			auto &target = map[targetPos.first][targetPos.second];

			if (target < 2 && target != curId) {
				q.push(targetPos);
			}
		}

		curId = id;

		++ count;
	}

	colorCount[id] = count;
}

auto main(int, char **) -> int {
	std::cin >> n >> m;

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			char c;
			std::cin >> c;

			map[i][j] = c - '0';
		}
	}

	int id = 2;

	for (int i = 0; i < m; ++ i) {
		int x, y;
		std::cin >> x >> y;

		x -= 1;
		y -= 1;

		if (map[x][y] < 2) {
			bfs({x, y}, id ++);
		}

		std::cout << colorCount[map[x][y]] << std::endl;
	}

	return 0;
}