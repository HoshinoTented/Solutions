// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

struct Member {
  int id, time;
};

auto main(int, char **) -> int {
  int n, time;
  std::cin >> n;

  Member m[n];

  for (int i = 0; i < n; ++ i) {
    std::cin >> time;
    m[i] = Member{i, time};
  }

  std::sort(m, m + n, [](Member& a, Member &b) { return a.time == b.time ? a.id < b.id : a.time < b.time; });

  long sum = 0;
  
  for (int i = 0; i < n; ++ i) {
    auto &v = m[i];
    std::cout << v.id + 1 << ' ';
    sum += v.time * (n - i - 1);
  }

  std::cout << std::endl;
  printf("%.2f\n", (double) sum / n);
  
  return 0;
}
