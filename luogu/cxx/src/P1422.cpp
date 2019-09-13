#ifndef LUOGU_1422_H
#define LUOGU_1422_H

#include <iostream>

auto add(double &sum, const int &kwh, const int &bottom, const int &top, const double &cost) -> void {
  if (bottom <= kwh)
    sum += ((top == -1 || kwh <= top) ? kwh - bottom + 1 : top - bottom + 1) * cost;
}

auto compute(const int &kwh) -> double {
  double sum = 0.0;
  add(sum, kwh, 1, 150, 0.4463);
  add(sum, kwh, 151, 400, 0.4663);
  add(sum, kwh, 401, -1, 0.5663);

  return sum;
}

auto main(int, char**) -> int {
  int kwh;
  std::cin >> kwh;

  printf("%.1f\n", compute(kwh));

  return 0;
}

#endif
