#include <iostream>
#include <algorithm>

int n, c;
int rooms[100000];

auto ask(int x) -> bool {
    int count = c - 1;

    int last = rooms[0];
    for (int i = 1; i < n; ++ i) {
        if (count == 0) return true;
        
        if (rooms[i] - last >= x) {
            -- count;
            last = rooms[i];
        }
    }

    return count == 0;
}

auto main(int, char **) -> int {
    std::cin >> n >> c;

    for (int i = 0; i < n; ++ i) {
        std::cin >> rooms[i];
    }

    std::sort(rooms, rooms + n);

    int left = 0, right = rooms[n - 1] - rooms[0], ans;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (ask(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}