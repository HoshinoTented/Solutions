//
// Created by hoshino on 18-9-9.
//

#ifndef LUOGU_1540_HPP
#define LUOGU_1540_HPP

#include <iostream>
#include <list>

using dictionary = std::list<int>;

auto find(const dictionary &dic, const int &word) -> bool {
	for (int it : dic) {
		if (it == word) return true;
	}

	return false;
}

auto main(int, char **) -> int {
	int times = 0;
	unsigned int unitCount, length;
	std::cin >> unitCount >> length;

	dictionary dic;

	for (unsigned int i = 0; i < length; ++i) {
		int word;
		std::cin >> word;
		if (! find(dic, word)) {
			if (dic.size() == unitCount) {
				dic.pop_front();
			}

			dic.push_back(word);

			++ times;
		}
	}

	std::cout << times << std::endl;

	return 0;
}

#endif //LUOGU_1540_HPP
