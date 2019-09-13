//
// Created by hoshino on 18-9-16.
//

#ifndef LUOGU_2142_HPP
#define LUOGU_2142_HPP

#include <iostream>
#include "BigInt.hpp"

auto main(int, char **) -> int {
	BigInt i("-100");

	std::cout << i.to_string() << std::endl;

	return 0;
}

#endif //LUOGU_2142_HPP
