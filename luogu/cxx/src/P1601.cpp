//
// Created by hoshino on 18-9-13.
//

#ifndef LUOGU_1601_HPP
#define LUOGU_1601_HPP

#include "BigInt.hpp"
#include <iostream>
#include <string>

auto main(int, char **) -> int {
	std::string si, sj;
	std::cin >> si >> sj;

	BigInt i(si), j(sj);

	std::cout << (i + j).to_string() << std::endl;

	return 0;
}

#endif //LUOGU_1601_HPP
