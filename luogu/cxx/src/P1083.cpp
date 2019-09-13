#include <iostream>

#define N 1000011

int dayC, reqC;
int days[N], d[N], l[N], r[N];

auto ask(int req) -> bool {
    int diff[N] = { 0 };
    int need[N] = { 0 };

    for (int i = 1; i <= req; ++ i) {
        diff[l[i]] += d[i];
        diff[r[i] + 1] -= d[i];
    }

    for (int i = 1; i <= dayC; ++ i) {
        need[i] = diff[i] + need[i - 1];

        if (need[i] > days[i]) return false;
    }

    return true;
}

auto main(int, char **) -> int {
    std::cin >> dayC >> reqC;

    for (int i = 1; i <= dayC; ++ i) {
        std::cin >> days[i];
    }

    for (int i = 1; i <= reqC; ++ i) {
        std::cin >> d[i] >> l[i] >> r[i];
    }

    if (ask(reqC)) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int left = 1, right = reqC;

    while (left < right) {
        int mid = (left + right) / 2;

        if (ask(mid)) left = mid + 1;
        else right = mid;
    }

    std::cout << -1 << std::endl << left << std::endl;

    return 0;
}