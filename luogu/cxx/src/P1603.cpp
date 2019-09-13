//
// Created by hoshino on 18-9-17.
//

#ifndef LUOGU_163_HPP
#define LUOGU_163_HPP

#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <sstream>

#define MAX 6

auto main(int, char **) -> int {
	std::map<std::string, int> map;
	std::string n0[]{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve",
					 "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
	std::string n1[]{"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth",
					 "eleventh", "twelfth", "thirteenth", "fourteenth", "fifteenth", "sixteenth", "seventeenth",
					 "eighteenth", "nineteenth", "twentieth"};

	map.insert({"a", 1});

	for (int i = 1; i <= 20; ++ i) {
		map.insert({n0[i - 1], i});
		map.insert({n1[i - 1], i});
	}

	std::string buffer;

	for (int i = 0; i < MAX; ++ i) {
		std::string tmp;
		std::cin >> tmp;
		auto it = map.find(tmp);
		if (it != map.end()) {
			int v = static_cast<int>(std::pow((*it).second, 2)) % 100;
			char c[2];
			sprintf(c, "%02d", v);
			buffer.insert(buffer.size(), std::string(c));
		}
	}

	auto it = buffer.begin();
	while (it != buffer.end()) {
		if (*it == '0') buffer.erase(it);
		else break;
	}

	std::cout << (buffer.empty() ? "0" : buffer) << std::endl;

	return 0;
}

#endif //LUOGU_163_HPP
