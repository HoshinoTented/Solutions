//
// Created by hoshino on 18-9-16.
// TODO WA

#ifndef LUOGU_1020_HPP
#define LUOGU_1020_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#define IN_MAX 599999

using value_type = int;

struct Racket {
	value_type height, id;

	Racket(const value_type &h, const value_type &id) : height(h), id(id) {}
};

auto main(int, char **) -> int {
	char i[IN_MAX];
	std::cin.getline(i, IN_MAX);

	std::string tmp;
	std::vector<Racket> missiles;

	for (auto c : i) {
		if (c == '\0') break;
		if (c != ' ') tmp.push_back(c);
		else {
			missiles.push_back({std::stoi(tmp), static_cast<const value_type &>(missiles.size())});
			tmp = std::string();
		}
	}

	if (! tmp.empty()) missiles.push_back({std::stoi(tmp), static_cast<const value_type &>(missiles.size())});

	std::sort(missiles.begin(), missiles.end(),
			  [](const Racket &a, const Racket &b) -> bool { return a.height > b.height; });

	int max = 0;        //这里弄个max, 下面就不需要排序了
	std::vector<int> blockTimes;

	while (! missiles.empty()) {
		int count = 0;
		Racket last(50001, - 1);
		auto it = missiles.cbegin();
		while (it != missiles.cend()) {
			if (it->height <= last.height && it->id > last.id) {
				last = *it;
				count ++;
				missiles.erase(it);        //不需要 ++
			} else ++ it;
		}

		if (count > max) max = count;
		blockTimes.push_back(count);
	}

	std::cout << max << std::endl;
	std::cout << blockTimes.size() << std::endl;

	return 0;
}

#endif //LUOGU_1020_HPP
