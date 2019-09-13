//
// Created by hoshino on 18-10-2.
//

#ifndef LUOGU_1079_HPP
#define LUOGU_1079_HPP

#include <iostream>
#include <string>

auto decode(const char &encoded, const char &key) -> const char {
	bool isUpper = std::isupper(encoded);
	char decoded = static_cast<char>((toupper(encoded) - toupper(key) + 26) % 26 + 'A');
	return static_cast<const char>(isUpper ? decoded : tolower(decoded));
}

auto main(int, char **) -> int {
	std::string encoded, key;
	std::cin >> key >> encoded;
	for (size_t i = 0, j = 0; i < encoded.size(); ++ i, ++ j) {
		if (j == key.size()) j = 0;
		std::cout << decode(encoded[i], key[j]);
	}

	return 0;
}

#endif //LUOGU_1079_HPP
