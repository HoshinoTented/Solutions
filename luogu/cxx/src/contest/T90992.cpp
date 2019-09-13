#include <iostream>

auto main(int, char **) -> int {
	int n;
	std::cin >> n;

	int ms = 0, ss = 0;

	for (int i = 2; i < n; ++ i) {
		ms = 2 + ms;
		ss = ms + ss * 2;
	}

	std::cout << ss % 19260827 << std::endl;

	return 0;
}