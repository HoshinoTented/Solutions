//
// Created by hoshino on 18-11-3.
//

#ifndef LUOGU_1192_HPP
#define LUOGU_1192_HPP

#include <iostream>
#include <cstring>

#define MOD 100003

using value_type = int;

value_type *cache;

auto dfs(const value_type &c, const value_type &step_max) -> value_type {
  value_type k = 0;
  if (c != 0) {
    for (value_type i = 1; i <= c && i <= step_max; ++ i) {
      value_type new_c = c - i;
      k += cache[new_c] == - 1 ? dfs(new_c, step_max) : cache[new_c];
    }
  } else k = 1;

  k %= MOD;

  cache[c] = k;

  return k;
}

auto main(int, char **) -> int {
  value_type c, step_max;
  std::cin >> c >> step_max;

  cache = new value_type[c + 1];
  memset(cache, -1, sizeof(value_type) * (c + 1));

  std::cout << dfs(c, step_max) << std::endl;

  return 0;
}

#endif //LUOGU_1192_HPP
