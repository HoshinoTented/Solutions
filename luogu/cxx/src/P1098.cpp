//
// Created by hoshino on 18-9-22.
//

#ifndef LUOGU_1098_HPP
#define LUOGU_1098_HPP

#include <iostream>
#include <string>
#include <algorithm>

struct Mode {
	using mode = int;
	mode extensionMode, fillCount, isReverse;

	Mode(const mode &extensionMode, const mode &fillCount, const mode &isReverse) : extensionMode(extensionMode),
																					fillCount(fillCount),
																					isReverse(isReverse) {}

	// Only print between begin and last
	auto fill(const char &begin, const char &last) const -> void {
		if (std::isdigit(begin) == std::isdigit(last) && begin < last) {
			char start = static_cast<char>(begin + 1), end = last;
			int step = 1;
			if (isReverse - 1) {
				start = static_cast<char>(last - 1);
				end = begin;
				step = - 1;
			}

			for (char c = start; c != end; c += step) {
				for (int i = 0; i < fillCount; ++ i) {
					switch (extensionMode) {
						case 1:
							std::cout << static_cast<char>(std::tolower(c));
							break;
						case 2:
							std::cout << static_cast<char>(std::toupper(c));
							break;
						case 3:
							std::cout << '*';
							break;
						default:
							throw "Unknown ExtensionMode";
					}
				}
			}
		} else std::cout << '-';
	}
};


auto main(int, char **) -> int {
	Mode::mode extensionMode, fillCount, isReverse;
	std::string code;
	std::cin >> extensionMode >> fillCount >> isReverse >> code;

	Mode mode(extensionMode, fillCount, isReverse);

	char last = '\0';

	for (auto i = code.cbegin(); i < code.cend(); ++ i) {
		if (*i == '-') {
			if (last != '\0') {
				char end = *++ i;
				std::cout << last;
				mode.fill(last, end);
				last = end;
			} else std::cout << *i;
		} else {
			if (last != '\0') std::cout << last;
			last = *i;
		}
	}

	if (last != '\0') std::cout << last;

	return 0;
}

#endif //LUOGU_1098_HPP
