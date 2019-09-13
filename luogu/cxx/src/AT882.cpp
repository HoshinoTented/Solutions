//
// Created by hoshino on 18-12-10.
//

// TODO WA #4

#ifndef LUOGU_AT882_HPP
#define LUOGU_AT882_HPP

#include <bits/stdc++.h>

auto main(int, char **) -> int {
	int l, r;
	std::cin >> l >> r;

	int *ls = new int[31];
	std::memset(ls, 0, sizeof(int) * 31);

	for (int i = 0; i < l; ++ i) {
		int index;
		std::cin >> index;

		++ ls[index - 10];
	}

	int sum = 0;

	for (int i = 0; i < r; ++ i) {
		int index;
		std::cin >> index;

		index -= 10;

		if (ls[index]) {
			-- ls[index];
			++ sum;
		}
	}

	if (sum) {
		std::cout << sum << std::endl;
	} // else std::cout << std::endl;

	return 0;
}

#endif //LUOGU_AT882_HPP
