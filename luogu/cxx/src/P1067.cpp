//
// Created by hoshino on 18-11-30.
//

#ifndef LUOGU_P1067_HPP
#define LUOGU_P1067_HPP

#include <bits/stdc++.h>

int begin;

auto print(const int &num, const int &pow) -> void {
	static auto getPow = [&pow]() -> std::string { if (pow == 1) return ""; else return "^" + std::to_string(pow); };

	if (pow) {
		if (num == 1 || num == - 1) {
			if (num == 1) std::cout << (pow == begin ? "" : "+") << "x" << getPow();
			else std::cout << "-x" << getPow();
		} else {
			if (pow != begin && num > 0) std::cout << "+";
			std::cout << num << "x" << getPow();
		}
	} else {
		if (pow != begin && num > 0) std::cout << "+";
		std::cout << num;
	}
}

auto main(int n, char **) -> int {
	std::cin >> begin;
	n = begin;

	for (int i = n; i >= 0; -- i) {
		int num;
		std::cin >> num;

		if (num) {
			print(num, i);
		}
	}

	std::cout << std::endl;

	return 0;
}

#endif //LUOGU_P1067_HPP
