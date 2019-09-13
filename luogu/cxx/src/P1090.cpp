#include <iostream>
#include <vector>
#include <queue>

auto main(int, char **) -> int {
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++ i) {
		int cur;
		std::cin >> cur;
		q.push(cur);
	}

	int sum = 0;

	while (q.size() != 1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();

		sum += a + b;
		q.push(a + b);
	}

	std::cout << sum << std::endl;

	return 0;
}