#include <iostream>
#include <algorithm>

#define MAXN 10000

int n;
int dpArr[MAXN], src[MAXN];

auto dp() -> void {
	dpArr[0] = src[0];

	for (int i = 1; i < n; ++ i) {
		for (int j = 0; j < i; ++ j) {
			if (src[j] < src[i]) {
				dpArr[i] = std::max(dpArr[i], dpArr[j] + 1);
			}
		}
	}
}

auto main(int, char **) -> int {
	std::cin >> n;

	for (int i = 0; i < n; ++ i) {
		std::cin >> src[i];
	}

	dp();

	int ans = 0;

	for (int i = 0; i < n; ++ i) {
		ans = std::max(ans, dpArr[i]);
	}

	std::cout << ans << std::endl;

	return 0;
}