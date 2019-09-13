//
// Created by hoshino on 18-10-11.
// TODO: WA

#ifndef LUOGU_P1558_HPP
#define LUOGU_P1558_HPP

#include <iostream>
#include <vector>

auto main(int, char **) -> int {
	int *cs;
	int length, colors, events;
	std::cin >> length >> colors >> events;

	cs = new int[length];

	for (int i = 0; i < length; ++ i) {
		cs[i] = 1;
	}

	for (int i = 0; i < events; ++ i) {
		int begin, end;
		char command;
		std::cin >> command >> begin >> end;

		begin -= 1;
		if (begin > end) std::swap(begin, end);

		if (command == 'C') {
			int color;
			std::cin >> color;

			while (begin != end) {
				cs[begin ++] = color;
			}
		} else if (command == 'P') {
			bool tmp[colors];

			for (int it = 0; it < colors; ++ it) {
				tmp[it] = false;
			}

			for (int j = 0; j < length; ++ j) {
				tmp[cs[j] - 1] = true;
			}

			unsigned int colorCount = 0;
			for (int it = 0; it < colors; ++ it) {
				colorCount += tmp[it];
			}

			std::cout << colorCount << std::endl;
		} else throw "QAQ There are something wrong...";
	}

	return 0;
}

#endif //LUOGU_P1558_HPP
