#ifndef LUOGU_ALGO_RANGEADD_CPP
#define LUOGU_ALGO_RANGEADD_CPP

#include <iostream>

struct RangeAddable {
    int *p;

    const int length;

    RangeAddable(const int &length): p(new int[length + 1]), length(length) {
        for (int i = 0; i < length + 1; ++ i) p[i] = 0;
    }

    auto rangeAdd(const int &left, const int &right, const int &value) {
        p[left] += value;
        p[right + 1] -= value;
    }

    auto construct() -> int * {
        int *newArr = new int[length];

        newArr[0] = p[0];
        for (int i = 1; i < length; ++ i) {
            newArr[i] = p[i] + newArr[i - 1];
        }

        return newArr;
    }
};

auto main(int, char **) -> int {
    RangeAddable ra = { 5 };
    ra.rangeAdd(1, 4, 1);
    ra.rangeAdd(0, 2, 10);
    ra.rangeAdd(3, 4, 100);
    ra.rangeAdd(1, 3, 1000);

    int *arr = ra.construct();
    for (int i = 0; i < ra.length; ++ i) {
        std::cout << arr[i] << std::endl;
    }
}

#endif