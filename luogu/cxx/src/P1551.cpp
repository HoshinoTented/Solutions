#include <iostream>

struct union_find {
    int *arr;
    const int length;

    union_find(const int &len): arr(new int[len]), length(len) {
        for (size_t i = 0; i < len; ++ i) {
            arr[i] = i;
        }
    }

    auto ask(const int &x) -> int {
        if (arr[x] == x) return x;
        return arr[x] = ask(arr[x]);
    }

    auto concat(const int &x, const int &y) -> void {
        arr[ask(x)] = ask(y);
    }
};

auto main(int, char **) -> int {
    int n, m, p;

    std::cin >> n >> m >> p;

    union_find uf = {n + 1};

    for (size_t i = 0; i < m; ++ i) {
        int x, y;
        std::cin >> x >> y;

        uf.concat(x, y);
    }

    for (size_t i = 0; i < p; ++ i) {
        int x, y;
        std::cin >> x >> y;

        std::cout << (uf.ask(x) == uf.ask(y) ? "Yes" : "No") << std::endl;
    }

    return 0;
}