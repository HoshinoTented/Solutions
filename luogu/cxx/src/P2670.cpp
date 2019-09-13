#ifndef LUOGU_P2670_HPP
#define LUOGU_P2670_HPP

#include <bits/stdc++.h>

auto main(int, char **) -> int {
  int n, m;
  std::cin >> n >> m;

  int map[n][m];
  std::memset(map, 0, sizeof(int) * n * m);

  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < m; ++ j) {
      char c;
      std::cin >> c;
      if (c == '*') {
	map[i][j] = -1;

	for (int k = -1; k < 2; ++ k) {
	  for (int l = -1; l < 2; ++ l) {
	    if (!k && !l) continue;
	    int x = i + k, y = j + l;

	    if (!(x < 0 || x >= n || y < 0 || y >= m) && map[x][y] != -1) {
	      ++ map[x][y];
	    }
	  }
	}
      }
    }
  }

  for (auto &l : map) {
    for (auto &v : l) {
      std::cout << (v == -1 ? "*" : std::to_string(v));
    }

    std::cout << std::endl;
  }

  
  return 0;
}

#endif
