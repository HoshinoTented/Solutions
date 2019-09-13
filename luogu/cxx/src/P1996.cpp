//
// Created by hoshino on 18-9-16.
//

#ifndef LUOGU_1996_HPP
#define LUOGU_1996_HPP

#include <iostream>
#include <vector>

auto main(int, char **) -> int {
	int max, step;
	std::cin >> max >> step;

	std::vector<int> seq;
	seq.reserve(static_cast<unsigned long>(max));
	for (int i = 0; i < max; ++ i) {
		seq.push_back(i + 1);
	}

	for (size_t i = 0; ! seq.empty();) {
		size_t target = (i + step - 1) % seq.size();
		auto it = seq.begin() + target;
		std::cout << *it << " ";
		seq.erase(it);
		i = target;
	}

	return 0;
}

#endif //LUOGU_1996_HPP
