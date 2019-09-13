#ifndef LUOGU_P1190_HPP
#define LUOGU_P1190_HPP

#include <iostream>
#include <queue>

unsigned int n, m;
std::queue<unsigned int> cost = std::queue<unsigned int>();

auto isEmpty(const unsigned int *arr, const size_t &length) -> bool {
    for (size_t i = 0; i < length; ++ i) {
        if (arr != 0) {
            return false;
        }
    }

    return true;
}

auto shortestTime() -> int {
    unsigned int time = 0;
    unsigned int *outputs = new unsigned int[m];


    while (! cost.empty() && ! isEmpty(outputs, m)) {
        ++ time;

        for (size_t i = 0; i < m; ++ i) {
            if (outputs[i] != 0) outputs[i] = outputs[i] - 1;
            else if (! cost.empty()) {
                outputs[i] = cost.front();
                cost.pop();
            }
        }
    }

    return time;
}

auto main(int, char **) -> int {
    std::cin >> n >> m;

    for (unsigned int i = 0; i < n; ++ i) {
        unsigned int tmp;
        std::cin >> tmp;

        cost.push(tmp);
    }

    std::cout << shortestTime() << std::endl;
}

#endif