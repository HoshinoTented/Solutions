#include <iostream>
#include <algorithm>

#define MAXN 100000

struct Item {
	int weight, price;
};

int _dp[MAXN], itemCount, bagWeight;
Item items[MAXN];

auto dp() -> void {
	for (int i = 0; i < itemCount; ++ i) {
		for (int j = bagWeight; j >= items[i].weight; -- j) {
			_dp[j] = std::max(_dp[j], _dp[j - items[i].weight] + items[i].price);
		}
	}
}

auto main(int, char **) -> int {
	scanf("%d%d", &itemCount, &bagWeight);

	for (int i = 0; i < itemCount; ++ i) {
		int w, p;
		scanf("%d%d", &w, &p);
		items[i] = {w, p};
	}

	dp();

	std::cout << _dp[bagWeight] << std::endl;

	return 0;
}