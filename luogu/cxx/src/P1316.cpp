//
// Created by Administrator on 2019/8/16.
//

#include <iostream>
#include <algorithm>

namespace P1316 {
	unsigned int count, need;
	unsigned int items[100000];

	auto f(const unsigned int &mid) -> bool {
		unsigned int last = items[0], _count = need - 1;

		for (unsigned int i = 1; i < count; ++ i) {
			if (_count == 0) return true;

			if (items[i] - last >= mid) {
				_count --;
				last = items[i];
			}
		}

		return _count == 0;
	}

	auto binary() -> unsigned int {
		unsigned int left = 0, right = items[count - 1], ans = 0;

		while (left <= right) {
			unsigned int mid = (left + right) / 2;

			if (f(mid)) {
				ans = mid;
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		return ans;
	}

	auto main() -> void {
		std::cin >> count >> need;

		for (unsigned int i = 0; i < count; ++ i) {
			std::cin >> items[i];
		}

		std::sort(items, items + count);

		std::cout << binary() << std::endl;
	}
};

auto main(int, char **) -> int {
	P1316::main();

	return 0;
}