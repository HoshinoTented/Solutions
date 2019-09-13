#include <bits/stdc++.h>

int m, n;
bool map[100][100];
int ids[100][100];

auto search(const int &x, const int &y, const int &id) -> void {
  if (x < 0 || x >= m || y < 0 || y >= n) return;
  if (! map[x][y] || ids[x][y]) return;

  ids[x][y] = id;
  
  search(x - 1, y, id);
  search(x + 1, y, id);
  search(x, y - 1, id);
  search(x, y + 1, id);
}

auto main(int, char **) -> int {
  char c;
  
  std::cin >> m >> n;
  
  std::memset(map, 0, sizeof(bool) * 10000);
  std::memset(ids, 0, sizeof(int) * 10000);
  
  for (int i = 0; i < m; ++ i) {
    for (int j = 0; j < n; ++ j) {
      std::cin >> c;
      map[i][j] = c - '0';
    }
  }

  int id = 0;
  for (int i = 0; i < m; ++ i) {
    for (int j = 0; j < n; ++ j) {
      if (map[i][j] && ! ids[i][j]) search(i, j, ++ id);
    }
  }

  std::cout << id << std::endl;
  
  return 0;
}
