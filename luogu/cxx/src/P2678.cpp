#ifndef LUOGU_P2678_HPP
#define LUOGU_P2678_HPP

#include <iostream>

int needRemove(int *arr, int length, int low) {
    int start = 0, count = 0;
    for (size_t i = 0; i < length; ++ i) {
        if (arr[i] - start < low) {
            count ++;
        } else start = arr[i];
    }

    return count;
}

auto main(int, char **) -> int {
    int l, n, m;
    std::cin >> l >> n >> m;

    int arr[n + 1];

    arr[n] = l;

    for (size_t i = 0; i < n; ++ i) {
        std::cin >> arr[i];
    }

    int left = 0, right = l, ans;

    while (left <= right) {
        int mid = (right + left) / 2;

        int count = needRemove(arr, n, mid);

        if (count > m) right = mid - 1;
        else {
            ans = mid;
            left = mid + 1;
        }
    }

    std::cout << ans << std::endl;
}

#endif