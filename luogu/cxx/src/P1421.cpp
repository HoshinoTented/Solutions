//
// Created by hoshino on 18-8-25.
//

#ifndef LUOGU_1421_H
#define LUOGU_1421_H

#include <iostream>

#define PRICE 19

const int compute(const int &a) {
	return a / PRICE;
}

const int compute(const int &a, const int &b) {
	return compute(a * 10 + b);
}

int main(int argc, char *argv[]) {
	int a, b;
	std::cin >> a >> b;
	std::cout << compute(a, b) << std::endl;

	return 0;
}

#endif //LUOGU_1421_H
