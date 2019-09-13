#include <iostream>

int n, k;

auto dfs(int count, int rest, int last) -> int {
	if (count == k) return rest == 0;
	if (rest == 0) return count == k;

	int sum = 0;

	for (int i = last; i <= rest; ++ i) {
		sum += dfs(count + 1, rest - i, i);
	}

	return sum;
}

auto main(int, char **) -> int {
	std::cin >> n >> k;

	std::cout << dfs(0, n, 1) << std::endl;
}