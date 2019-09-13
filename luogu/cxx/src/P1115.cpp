#include <iostream>
#include <algorithm>

#define MAXN 200000

auto main(int, char **) -> int {
	int n, ans, last;
	std::cin >> n;
	std::cin >> last;

	ans = last;

	for (int i = 1; i < n; ++ i) {
		int v;
		std::cin >> v;

		ans = std::max(ans, last = std::max(last + v, v));
	}

	std::cout << ans << std::endl;

	return 0;
}