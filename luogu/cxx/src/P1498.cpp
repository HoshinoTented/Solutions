#include <bits/stdc++.h>

using String = std::string;
using Int32 = int;

auto draw(const int &n) -> String * {
    size_t mLines = 1 << n;

    if (n == 1) {
        return new String[mLines]
        {" /\\ ",
         "/__\\"};
    } else {
        size_t lines = 1 << (n - 1);

        auto cs = draw(n - 1);
        auto spaces = String(lines, ' ');
        
        String *result = new String[mLines];

        for(size_t i = 0; i < lines; i++) {
            result[i] = "";
            result[i] += spaces;
            result[i] += cs[i];
            result[i] += spaces;
        }

        for(size_t i = lines; i < mLines; i++) {
            result[i] = "";
            result[i] += cs[i - lines];
            result[i] += cs[i - lines];
        }

        delete[] cs;        // 小心核泄露
        
        return result;
    }
}

auto main(int n, char **) -> int {
    std::cin >> n;

    auto arr = draw(n);

    for(size_t i = 0; i < static_cast<size_t>(1 << n); i++) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}