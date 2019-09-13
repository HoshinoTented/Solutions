#include <bits/stdc++.h>

int m, n, ids[100][100];
bool graph[100][100];

auto search(const int &x, const int &y, const int &id) -> void {
  if (x >= 0 && y >= 0 && x < m && y < n && graph[x][y] && ids[x][y] == 0) {
    ids[x][y] = id;

    for (int i = -1; i <= 1; ++ i) {
      for (int j = -1; j <= 1; ++ j) {
	if (i != 0 || j != 0) search(x + i, y + j, id);
      }
    }
  }
}

auto main(int, char **) -> int {
  std::memset(ids, 0, sizeof(int) * 10000);

  std::cin >> m >> n;
  if (m == 0) return 0;

  for (int i = 0; i < m; ++ i) {
    for (int j = 0; j < n; ++ j) {
      char c;
      std::cin >> c;
      graph[i][j] = c == '@';
    }
  }

  int id = 0;
  
  for (int i = 0; i < m; ++ i) {
    for (int j = 0; j < n; ++ j) {
      if (graph[i][j] && ids[i][j] == 0) search(i, j, ++ id);
    }
  }

  std::cout << id << std::endl;

  return main(0, nullptr);
}
