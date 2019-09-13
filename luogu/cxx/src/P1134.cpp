#include <iostream>
#include <string>

auto process(const int i) -> int {
    std::string s = std::to_string(i);
    for (auto it = s.end() - 1; it >= s.begin(); -- it) {
        if (*it != '0') return *it - '0';
    }

    return 0;
}

auto zeros(const int max) -> int {
    int result = 1;

    for(int i = 1; i <= max; ++ i) {
        result *= i;
        result = process(result);
    }

    return result;
}

auto main(int, char **) -> int {
    int i;

    std::cin >> i;

    std::cout << zeros(i) << std::endl;
}