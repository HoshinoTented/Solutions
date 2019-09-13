//
// Created by hoshino on 18-10-8.
//

#ifndef LUOGU_1553_HPP
#define LUOGU_1553_HPP

#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>

auto reversePrint(std::string &str) -> void {
	auto _str = std::to_string(std::stoull(str));
	std::reverse(_str.begin(), _str.end());
	std::cout << std::stoull(_str);
	str.clear();
}

auto main(int, char **) -> int {
	std::string number;
	std::cin >> number;

	std::string str;

	for (char it : number) {
		if (! isdigit(it)) {
			reversePrint(str);
			std::cout << it;
		} else str.push_back(it);
	}

	if (! str.empty()) reversePrint(str);

	return 0;
}

#endif //LUOGU_1553_HPP
