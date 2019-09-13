#include <iostream>

auto main(int, char **) -> int {
	int n;
	std::cin >> n;

	if (n == 1) std::cout << 10;
	else std::cout << (n - 1) * 14;

	std::cout << std::endl;

	return 0;
}