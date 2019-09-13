//
// Created by hoshino on 18-8-28.
//

/* Comment
 * 感觉这道题有点过于简单了
 */

#ifndef LUOGU_1724_H
#define LUOGU_1724_H

#include <string>
#include <iostream>

using times_value = unsigned int;

struct Position {
	using value_type = long;
	value_type x, y;

	explicit Position(const value_type &x, const value_type &y) : x(x), y(y) { }

	auto operator+(const Position &other) -> Position {
		return Position(x + other.x, y + other.y);
	}

	auto to_string() -> std::string {
		return std::to_string(x) + " " + std::to_string(y);
	}

	static auto move(value_type &x, value_type &y, const char &c) -> void {
		switch (c) {
			case 'N': ++ y; break;
			case 'S': -- y; break;
			case 'E': ++ x; break;
			case 'W': -- x; break;
			default: throw "Unknown Command";
		}
	}
};

auto commands(const std::string &cs, const int &times) -> const Position {
	Position::value_type x = 0, y = 0;
	for (auto c : cs) {
		Position::move(x, y, c);
	}

	x *= times;
	y *= times;

	return Position(x, y);
}

auto main(int argc, char *argv[]) -> int {
	std::string cs;
	times_value times;
	std::cin >> cs >> times;

	times_value fullTimes, subTimes;
	fullTimes = times / cs.size();
	subTimes = times % cs.size();

	auto p0 = commands(cs, fullTimes);
	auto p1 = commands(cs.substr(0, subTimes), 1);

	std::cout << (p0 + p1).to_string() << std::endl;

	return 0;
}

#endif //LUOGU_1724_H
