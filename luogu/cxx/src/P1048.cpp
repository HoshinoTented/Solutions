#include <iostream>
#include <algorithm>

struct item {
	int time, price;
};

item items[100];
int bagDp[1001], itemCount, costTime;

auto dp() -> void {
	for (int i = 0; i < itemCount; ++ i) {
		for (int j = costTime; j >= items[i].time; -- j) {
			bagDp[j] = std::max(bagDp[j], bagDp[j - items[i].time] + items[i].price);
		}
	}
}

auto main(int, char **) -> int {
	std::cin >> costTime >> itemCount;

	for (int i = 0; i < itemCount; ++ i) {
		int t, p;
		std::cin >> t >> p;

		items[i] = {t, p};
	}

	dp();

	std::cout << bagDp[costTime] << std::endl;

	return 0;
}