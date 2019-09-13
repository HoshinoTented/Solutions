#ifndef LUOGU_1085_H
#define LUOGU_1085_H

#include <iostream>
#include <string>

#define MAX 7

struct UnHappy {
  int hour;
  int day;

  explicit UnHappy(const int &h, const int &d) : hour(h), day(d) {}

  auto to_string() -> std::string {
    return std::to_string(day);
  }
};

auto main(int, char**) -> int {
  UnHappy most(0, 0);
  for (int i = 1; i <= MAX; ++ i) {
    int a, b;
    std::cin >> a >> b;
    UnHappy tmp(a + b, i);
    if (most.hour < tmp.hour) most = tmp;
  }

  std::cout << most.to_string() << std::endl;

  return 0;
}

#endif
