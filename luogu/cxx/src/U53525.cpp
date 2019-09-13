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
    int n;

    std::cin >> n;

    int arr[n] = { 0 };

    std::cin >> arr[0];
    for (size_t i = 1; i < n; ++ i) {
        int v;
        std::cin >> v;
        arr[i] = arr[i - 1] + v;
    }

    for (size_t i = 0; i < n; ++ i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}