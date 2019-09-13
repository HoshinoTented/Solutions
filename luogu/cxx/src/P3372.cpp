#include <iostream>
#include <cmath>

#define N 100000

typedef long long value_type;

int n, m, chunkLen;
value_type values[N], chunk[400];

auto rangeAdd(int begin, int end, value_type value) -> void {
	for (int i = 0; i < n; ++ i) {
		values[i] += value;
	}

	for (int i = begin / chunkLen + 0.5; i < end / chunkLen + 0.5; ++ i) {

	}
}

auto main(int, char **) -> int {
	std::cin >> n >> m;

	chunkLen = sqrt(n) + 0.5;

	for (int i = 0; i < m; ++ i) {

	}
}