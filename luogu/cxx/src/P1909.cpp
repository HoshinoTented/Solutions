#ifndef LUOGU_1909_H
#define LUOGU_1909_H

#include <iostream>

#define MAX_LIKE 3

auto main(int, char**) -> int {
  int need;
  int least_price = 0;
  std::cin >> need;

  for (int i = 0; i < MAX_LIKE; ++ i) {
    int result;
    int count, price;
    std::cin >> count >> price;
    result = (need / count + (need % count != 0)) * price;

    if (!least_price || result < least_price) least_price = result;
  }

  std::cout << least_price << std::endl;
  
  return 0;
}

#endif
