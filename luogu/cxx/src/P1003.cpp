//
// Created by hoshino on 18-8-26.
//

#ifndef LUOGU_1003_H
#define LUOGU_1003_H

#include <iostream>
#include <vector>

#define self (*this)

struct Carpet;

std::vector<Carpet> carpets;

struct Carpet {
	typedef const unsigned int pos_type;
	typedef const unsigned int size_type;

	Carpet(pos_type x, pos_type y, size_type hLen, size_type vLen) :
			x(x), y(y), hLength(hLen), vLength(vLen) {}

	auto contains(pos_type x, pos_type y) -> bool {
		return self.x <= x && self.y <= y &&
			   self.x + hLength >= x && self.y + vLength >= y;
	}

private:
	pos_type x, y;
	size_type hLength, vLength;
};

auto put(
		Carpet::pos_type x,
		Carpet::pos_type y,
		Carpet::size_type horizontalLength,
		Carpet::size_type verticalLength) -> void {
	carpets.emplace_back(x, y, horizontalLength, verticalLength);
}

auto main(int argc, char *argv[]) -> int {
	int carpetCount;
	std::cin >> carpetCount;
	for (int i = 0; i < carpetCount; ++i) {
		unsigned int x, y;
		unsigned int hLength, vLength;
		std::cin >> x >> y >> hLength >> vLength;
		put(x, y, hLength, vLength);
	}

	unsigned int reqX, reqY;
	std::cin >> reqX >> reqY;

	for (auto i = carpets.size() - 1; i >= 0; --i) {
		auto carpet = carpets[i];
		if (carpet.contains(reqX, reqY)) {
			std::cout << i + 1 << std::endl;
			return 0;
		}
	}

	std::cout << -1 << std::endl;

	return 0;
}

#endif //LUOGU_1003_H
