#ifndef LUOGU_P1149_HPP
#define LUOGU_P1149_HPP

#include <iostream>
#include <string>

unsigned int _stick[10] = {
    6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};

auto stick(unsigned int i) -> unsigned int {
    if (i > 9) {
        unsigned int sum = 0;

        for (char c : std::to_string(i)) {
            sum += stick(c - '0');
        }
        
        return sum;
    } else return _stick[i];
}

auto search(unsigned int num) -> int {
    unsigned int match = 0;

    for (size_t i = 0; i < 1000; ++ i) {
        for (size_t j = 0; j < 1000; ++ j) {
            if (stick(i) + stick(j) + stick(i + j) == num) ++ match;
        }
    }

    return match;
}

auto main(int, char **) -> int {
    unsigned int num = 0;

    std::cin >> num;

    std::cout << search(num - 4) << std::endl;
}

#endif