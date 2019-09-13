//
// Created by hoshino on 18-11-10.
//

#ifndef LUOGU_U51941_HPP
#define LUOGU_U51941_HPP

#include <iostream>
#include <string>

auto main(int, char **) -> int {
	std::string title;
	std::getline(std::cin, title);
	size_t notBlack = 0;
	for (auto &c : title) if (c != ' ') ++ notBlack;

	std::cout << notBlack << std::endl;

	return 0;
}

#endif //LUOGU_U51941_HPP
