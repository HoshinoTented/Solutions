#include <iostream>

#define MAXN 100001

int n, m, start = 1;
int next[MAXN], prev[MAXN];

auto insert(int ix, int tar, int mode) -> void {
	if (mode == 0) {
		if (tar == start) {
			start = ix;
		}

		next[prev[tar]] = ix;
		prev[ix] = prev[tar];
		next[ix] = tar;
		prev[tar] = ix;
	} else {
		prev[next[tar]] = ix;
		next[ix] = next[tar];
		next[tar] = ix;
		prev[ix] = tar;
	}
}

auto remove(int ix) -> void {
	if (ix == start) {
		start = next[ix];
	}

	next[prev[ix]] = next[ix];
	prev[next[ix]] = prev[ix];
	next[ix] = prev[ix] = 0;
}

auto inserts() -> void {
	for (int i = 2; i <= n; ++ i) {
		int k, p;
		std::cin >> k >> p;

		insert(i, k, p);
	}
}

auto removes() -> void {
	for (int i = 0; i < m; ++ i) {
		int ix;
		std::cin >> ix;

		remove(ix);
	}
}

auto printArr(int *arr) -> void {
	for (int i = 1; i <= n; ++ i) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

auto main(int, char **) -> int {
	std::cin >> n;
	inserts();

	std::cin >> m;
	removes();

	for (int i = start; i != 0; i = next[i]) {
		std::cout << i;

		if (next[i]) {
			std::cout << " ";
		}
	}

	std::cout << std::endl;

	return 0;
}