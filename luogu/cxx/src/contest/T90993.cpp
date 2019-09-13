#include <iostream>
#include <algorithm>
#include <cmath>

auto main(int, char **) -> int {
	int ax, ay, px, py, sx, sy;
	std::cin >> ax >> ay >> px >> py >> sx >> sy;

	int h = std::abs(ax - px), v = std::abs(ay - py);

	printf("%.2f", sqrt(h * h + v * v));

	return 0;
}