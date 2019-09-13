#include <bits/stdc++.h>

bool **g;
bool **visited;
int h, w, sx, sy;

auto canVisit(const int &x, const int &y) -> bool {
  return x >= 0 && y >= 0 && x < h && y < w && g[x][y] && ! visited[x][y];
}

auto search(const int &x, const int &y) -> int {
  if (canVisit(x, y)) {
    visited[x][y] = true;

    return 1 + search(x + 1, y) + search(x - 1, y) + search(x, y + 1) + search(x, y - 1);
  } else return 0;
}

auto main(int, char **) -> int {
  std::cin >> w >> h;

  g = new bool*[h];
  visited = new bool*[h];
  
  for (int i = 0; i < h; ++ i) {
    g[i] = new bool[w];
    visited[i] = new bool[w];

    for (int j = 0; j < w; ++ j) {
      char c;
      std::cin >> c;

      switch (c) {
      case '.':
	g[i][j] = true;
	break;
      case '#':
	g[i][j] = false;
	break;
      case '@':
	sx = i;
	sy = j;
	g[i][j] = true;
	break;
      default: break;      
      }
    }
  }

  std::cout << search(sx, sy) << std::endl;

  return 0;
}
