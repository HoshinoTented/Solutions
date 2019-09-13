//
// Created by hoshino on 18-9-15.
//

#ifndef LUOGU_1059_HPP
#define LUOGU_1059_HPP

#include <iostream>
#include <vector>

template<typename T>
auto insert(std::vector<T> &vector, const T &value) -> void {
	if (! vector.empty()) {
		auto it = vector.cbegin();
		while (it != vector.cend()) {
			if (*it == value) return;
			if (*it > value) {
				vector.insert(it, value);
				return;
			}

			++ it;
		}

		vector.push_back(value);
	} else vector.push_back(value);
}

auto main(int, char **) -> int {
	int length;
	std::cin >> length;

	std::vector<int> v;
	for (int i = 0; i < length; ++ i) {
		int tmp;
		std::cin >> tmp;
		insert(v, tmp);
	}

	std::cout << v.size() << std::endl;
	for (auto value : v) std::cout << value << " ";

	std::cout << std::endl;

	return 0;
}

#endif //LUOGU_1059_HPP
