#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

#define MAXN 1000
#define FLOOR 0
#define ICE 1
#define STOP 2
#define END 3

struct Pos {
	int x, y;

	auto reverse() const -> Pos {
		return Pos{- x, - y};
	}

	auto operator+(const Pos &other) const -> Pos {
		return Pos{x + other.x, y + other.y};
	}

	auto operator-(const Pos &other) const -> Pos {
		return Pos{x - other.x, y - other.y};
	}

	auto operator==(const Pos &other) const -> bool {
		return x == other.x && y == other.y;
	}

	auto operator!=(const Pos &other) const -> bool {
		return ! ((*this) == other);
	}

	auto to_string() const -> std::string {
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}

} up = {- 1, 0}, down = {1, 0}, left = {0, - 1}, right = {0, 1};      // 方向

int n;
int graph[MAXN][MAXN], from[MAXN][MAXN];
Pos sides[] = {{- 1, - 1}, up, down, left, right};
std::vector<Pos> starts;

auto check_index(Pos p) -> bool {
	return 0 <= p.x && p.x < n && 0 <= p.y && p.y < n;
}

/**
 * 移动
 * @params from 开始的坐标
 * @params modify 移动的方向
 * @return 返回移动后的坐标
 */
auto move(Pos from, Pos modify) -> Pos {
	Pos cur = from;

	do {
		cur = cur + modify;

		if (! check_index(cur)) return cur - modify;
	} while (graph[cur.x][cur.y] == ICE);

	if (graph[cur.x][cur.y] == STOP) {
		cur = cur - modify;
	}

	return cur;
}

auto time_back(Pos start, Pos end) -> std::vector<char> {
	std::vector<char> path;
	Pos cur = end;

	while (cur != start) {
		Pos side = sides[from[cur.x][cur.y]];

		if (side == up) {
			path.push_back('u');
		} else if (side == down) {
			path.push_back('d');
		} else if (side == left) {
			path.push_back('l');
		} else if (side == right) {
			path.push_back('r');
		}

		cur = move(cur, side.reverse());
	}

	return path;
}

auto bfs(Pos start) -> std::vector<char> {
	int visited[MAXN][MAXN];

	memset(from, 0, sizeof(int) * MAXN * MAXN);

	std::queue<Pos> q;
	q.push(start);

	while (! q.empty()) {
		Pos cur = q.front();
		q.pop();

		if (visited[cur.x][cur.y]) continue;

		visited[cur.x][cur.y] = true;

		for (int i = 1; i <= 4; ++ i) {
			Pos side = sides[i];
			Pos result = move(cur, side);

			if (visited[result.x][result.y]) continue;
			from[result.x][result.y] = i;

			if (graph[result.x][result.y] == END) {
				return time_back(start, result);
			}

			q.push(result);
		}
	}

	return std::vector<char>{};
}

auto main(int, char **) -> int {
	std::cin >> n;

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			std::cin >> graph[i][j];

			if (graph[i][j] == 0) {
				starts.push_back({i, j});
			}
		}
	}

	for (Pos &start : starts) {
		std::cout << start.to_string() << std::endl;
		std::vector<char> path = bfs(start);

		if (path.empty()) continue;


		std::cout << start.x + 1 << " " << start.y + 1 << " " << path.size() << std::endl;
		for (int i = path.size() - 1; i >= 0; -- i) {
			std::cout << path[i] << std::endl;
		}
	}

	return 0;
}