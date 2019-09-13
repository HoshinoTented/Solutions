#ifndef LUOGU_P1464_HPP
#define LUOGU_P1464_HPP

#include <iostream>

typedef long long Int;

Int cache[21][21][21];

auto w(const Int a, const Int b, const Int c) -> Int {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    int result = cache[a][b][c];

    if (result == -1) {
        if (a < b && b < c) result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        else result = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    return cache[a][b][c] = result;
}

auto main(int, char **) -> int {
    for (int i = 0; i <= 20; ++ i) {
        for (int j = 0; j <= 20; ++ j) {
            for (int k = 0; k <= 20; ++ k) {
               cache[i][j][k] = -1;
            }
        }
    }

    Int a, b, c;

    while (true) {
        std::cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) break;

        std::cout << "w(" << a << ", " << b << ", " << c << ") = " 
            << w(a, b, c) << std::endl;
    }

    return 0;
}

#endif