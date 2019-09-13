#include <vector>
#include <iostream>
#include <algorithm>

struct edge {
	int from, to;
	int weight;

	auto operator<(const edge &other) const -> bool {
		return weight < other.weight;
	}
};

struct uf {
	int arr[100001];

	uf() {
		for (int i = 1; i <= 10000; ++ i) {
			arr[i] = i;
		}
	}

	auto find(const int &x) -> int {
		return arr[x] = (arr[x] == x ? x : find(arr[x]));
	}

	auto push(const int &x, const int &y) -> void {
		arr[find(x)] = find(y);
	}
};

int n;
uf minTree;

auto kruskal(std::vector<edge> edges) -> int {
	int sum = 0;

	for (auto e : edges) {
		if (minTree.find(e.from) != minTree.find(e.to)) {
			minTree.push(e.from, e.to);
			sum += e.weight;
		}
	}

	return sum;
}

auto main(int, char **) -> int {
	int m;
	std::vector<edge> es;

	std::cin >> n >> m;

	for (int i = 0; i < m; ++ i) {
		int from, to, weight;
		std::cin >> from >> to >> weight;

		es.push_back({from, to, weight});
	}

	std::sort(es.begin(), es.end());

	int sum = kruskal(es);
	int last = minTree.find(1);

	for (int i = 2; i <= n; ++ i) {
		if (minTree.find(i) != last) {
			std::cout << "orz" << std::endl;
			return 0;
		}
	}

	std::cout << sum << std::endl;

	return 0;
}