#include <iostream>
#include <queue>

using force = unsigned long long;

std::priority_queue<force> forces;

auto volforce() -> force {
	force sum = 0;
	std::queue<int> poped;

	for (int i = 0; i < 20 && ! forces.empty(); ++ i) {
		force cur = forces.top();
		forces.pop();
		poped.push(cur);

		sum += cur;
	}

	while (! poped.empty()) {
		forces.push(poped.front());
		poped.pop();
	}

	return sum;
}

auto score(const force &lv, const force &score) -> int {
	force s = 25L;
	s = s * (lv + 1) * score / 1e7;

	return s;
}


auto main(int, char **) -> int {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++ i) {
		char req;

		std::cin >> req;

		if (req == 'P') {
			force lv, s;
			std::cin >> lv >> s;
			force f = score(lv, s);
			forces.push(f);
		} else {
			std::cout << volforce() << std::endl;
		}
	}

	return 0;
}