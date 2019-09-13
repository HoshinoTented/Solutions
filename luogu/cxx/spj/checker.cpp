//
// Created by Administrator on 2019/8/20.
//

#include "testlib.h"

#define MAXN 1001
#define FLOOR 0
#define ICE 1
#define STOP 2
#define END 3

namespace SPJ {
	int n;
	int graph[MAXN][MAXN];

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
	};

	auto check_index(Pos p) -> bool {
		return 0 <= p.x && p.x < n && 0 <= p.y && p.y < n;
	}

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

	auto readInput() -> void {
		n = inf.readInt();

		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				graph[i][j] = inf.readInt();
			}
		}
	}

	auto main() -> void {
		readInput();

		Pos current = {ouf.readInt() - 1, ouf.readInt() - 1};

		if (! check_index(current)) quitf(_wa, "Out of bounds: (%d, %d)", current.x, current.y);
		if (graph[current.x][current.y] != FLOOR) quitf(_wa, "(%d, %d) is not 0", current.x, current.y);

		int stepCount = ouf.readInt();
		ouf.readEoln();

		for (int i = 0; i < stepCount; ++ i) {
			char side = ouf.readChar();
			ouf.readEoln();

			switch (side) {
				case 'u':
					current = move(current, {- 1, 0});
					break;
				case 'd':
					current = move(current, {1, 0});
					break;
				case 'l':
					current = move(current, {0, - 1});
					break;
				case 'r':
					current = move(current, {0, 1});
					break;
				default:
					quitf(_wa, "Invalid side: %d", (int) side);
			}
		}

		if (graph[current.x][current.y] == END) {
			quitf(_ok, "you ak ioi!");
		} else quitf(_wa, "Current pos (%d, %d)", current.x, current.y);
	}
}

auto main(int argc, char **argv) -> int {
	registerTestlibCmd(argc, argv);

	SPJ::main();

	return 0;
}

