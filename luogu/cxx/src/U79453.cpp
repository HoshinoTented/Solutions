#include <iostream>
#include <vector>
#include <algorithm>

#define TIME_MAX 1001

struct note {
	int l, r;

	auto operator<(const note &a) const -> bool {
		return this->l < a.l;
	}

	auto operator>(const note &a) const -> bool {
		return this->l > a.l;
	}
};

int n, w;
std::vector<note> notes[1001];

// 0 -> left
// 1 -> right
auto nearest(int cur, note &n, note &next) -> bool {
	int l = std::abs(cur - n.l);
	int r = std::abs(cur - n.r);

	if (l == r) {
		nearest()
	}
}

auto main(int, char **) -> int {
	std::cin >> n >> w;

	for (int i = 0; i < n; ++ i) {
		int time, left, right;
		std::cin >> time >> left >> right;

		notes[time].push_back(note{left, right});
	}


	int sum = 0;
	int left = 0, right = w;
	for (int i = 0; i < 1001; ++ i) {
		std::vector<note> &cur = notes[i];

		if (cur.empty()) continue;

		if (cur.size() == 2) {
			note first = std::min(cur[0], cur[1]);
			note last = std::max(cur[0], cur[1]);

			sum += std::abs(left - first.l);
			left = first.l;
			sum += std::abs(right - last.r);
		} else {
			note first = cur[0];

			if (first.l > left) {

			}
		}
	}

	return 0;
}