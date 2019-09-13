// TODO WA && TLE

#include <bits/stdc++.h>

int map[400][400];
int n, m, sx, sy;

struct UnknownStruct {
  int x, y, step;

  UnknownStruct(const int &x, const int &y, const int &step) : x(x), y(y), step(step) {}
};

auto canVisit(const int &x, const int &y) -> bool {
  return x >= 0 && y >= 0 && x < n && y < m;
}

auto search(const int &x, const int &y) -> void {
  std::queue<UnknownStruct> q;

  q.emplace(x, y, 0);

  while (! q.empty()) {
    auto &front = q.front();
    auto &x = front.x, &y = front.y, &step = front.step;

    q.pop();
    
    if (! canVisit(x, y)) continue;
    if (map[x][y] != -1 && map[x][y] <= step) continue;

    map[x][y] = step;
    
    q.emplace(x + 2, y + 1, step + 1);
    q.emplace(x + 2, y - 1, step + 1);
    q.emplace(x + 1, y + 2, step + 1);
    q.emplace(x + 1, y - 2, step + 1);
    q.emplace(x - 2, y + 1, step + 1);
    q.emplace(x - 2, y - 1, step + 1);
    q.emplace(x - 1, y + 2, step + 1);
    q.emplace(x - 1, y - 2, step + 1);
  }
}

auto main(int, char **) -> int {
  std::cin >> n >> m >> sx >> sy;
  sx -= 1;
  sy -= 1;

  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < m; ++ j) {
      map[i][j] = -1;
    }
  }

  search(sx, sy);

  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < m; ++ j) {
      std::string str = std::to_string(map[i][j]);
      std::cout << str;

      for (size_t k = 0; k < 5 - str.size(); ++ k) std::cout << ' ';
    }

    std::cout << std::endl;
  }
  
  return 0;
}
