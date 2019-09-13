#include <iostream>
#include <vector>
#include <queue>

struct node {
	std::vector<int> next;
	int in;
};

int n;
node nodes[100001];

auto topo() -> std::vector<int> {
	std::vector<int> result;
	std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

	for (int i = 1; i <= n; ++ i) {
		if (! nodes[i].in) {
			queue.push(i);
		}
	}

	while (! queue.empty()) {
		int index = queue.top();
		result.push_back(index);
		queue.pop();

		for (auto i : nodes[index].next) {
			nodes[i].in --;

			if (! nodes[i].in) {
				queue.push(i);
			}
		}
	}

	return result;
}

auto main(int, char **) -> int {
	std::cin >> n;

	for (int i = 0; i < n; ++ i) {
		int from, to;
		std::cin >> from >> to;

		nodes[from].next.push_back(to);
		nodes[to].in ++;
	}

	auto result = topo();

	for (auto v : result) {
		std::cout << v << std::endl;
	}

	return 0;
}