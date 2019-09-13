//
// Created by hoshino on 18-9-22.
//

#ifndef LUOGU_1305_HPP
#define LUOGU_1305_HPP

#include <iostream>
#include <algorithm>
#include <list>

auto main(int, char **) -> int {
	int i;
	std::list<char> str;
	std::cin >> i;

	for (int j = 0; j < i; ++ j) {
		char root, l, r;
		std::cin >> root >> l >> r;
		auto it = std::find(str.cbegin(), str.cend(), root);
		if (it == str.cend()) {
			str.push_back(root);
			it = str.cend();
		} else ++ it;

		if (l != '*') str.insert(it, l);
		if (r != '*') str.insert(it, r);
	}

	for (auto v : str) {
		std::cout << v;
	}

	return 0;
}

#endif //LUOGU_1305_HPP
