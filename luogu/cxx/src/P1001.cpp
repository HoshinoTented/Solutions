//
// Created by hoshino on 18-8-21.
//

#ifndef LUOGU_1001_HPP
#define LUOGU_1001_HPP

#include <iostream>

int main(int argc, char *argv[]) {
	auto add = [] (const int &a, const int &b) { return a + b; };
	int a, b;
	std::cin >> a >> b;
	std::cout << add(a, b) << std::endl;

	return 0;
}

#endif //LUOGU_1001_HPP
