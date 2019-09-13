#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 1001

int n;
int _dp[MAXN][MAXN];
int lines[MAXN][MAXN];

auto dp() -> void {
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j <= i; ++ j) {
			_dp[n - 1][j] = lines[n - 1][j];
		}
	}

	for (int i = n - 2; i > - 1; -- i) {
		for (int j = 0; j <= i; ++ j) {
			_dp[i][j] = std::max(_dp[i + 1][j], _dp[i + 1][j + 1]) + lines[i][j];
		}
	}
}

auto main(int, char **) -> int {
	std::cin >> n;

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j <= i; ++ j) {
			std::cin >> lines[i][j];
		}
	}

	dp();

	std::cout << _dp[0][0] << std::endl;

	return 0;
}
