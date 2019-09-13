//
// Created by hoshino on 18-8-25.
//

#ifndef LUOGU_3742_H
#define LUOGU_3742_H

#include <iostream>
#include <string>

const std::string *f(const std::string &x, const std::string &y) {
	auto *ans = new std::string();
	auto xIt = x.cbegin();
	auto yIt = y.cbegin();

	while (xIt != x.end()) {
		if (*xIt < *yIt) return nullptr;
		ans->push_back(*(*xIt == *yIt ? xIt : yIt));

		++xIt;
		++yIt;
	}

	return ans;
}

int main(int argc, char *argv[]) {
	int length;			//unused for C++
	std::string x, y;
	std::cin >> length >> x >> y;

	if (x.length() != length || y.size() != length) throw "length";

	auto ans = f(x, y);
	std::cout << (ans == nullptr ? "-1" : *ans) << std::endl;

	return 0;
}

#endif //LUOGU_3742_H
