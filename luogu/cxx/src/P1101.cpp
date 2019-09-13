#include <bits/stdc++.h>

using pos = std::pair<int, int>;

int **matrix, **out, n;
std::vector<pos> starts;

auto isValid(const int &v) -> bool {
  return v >= 0 && v < n;
}

auto search() -> void {
  for (auto &p : starts) {
    int last;
    bool suc;

    // TOP
    last = 1;
    suc = false;
    for (int i = p.first - 1; isValid(i) && ! suc; -- i) {
      int v = matrix[i][p.second];
      if (v - last != 1) break;
      if (v == 7) suc = true;

      last = v;
    }

    if (suc) {
      for (int i = 0; i < 7; ++ i) {
	out[p.first - i][p.second] = matrix[p.first - i][p.second];
      }
    }

    // LEFT
    last = 1;
    suc = false;
    for (int i = p.second - 1; isValid(i) && ! suc; -- i) {
      int v = matrix[p.first][i];
      if (v - last != 1) break;
      if (v == 7) suc = true;

      last = v;
    }

    if (suc) {
      for (int i = 0; i < 7; ++ i) {
	out[p.first][p.second - i] = matrix[p.first][p.second - i];
      }
    }

    // RIGHT
    last = 1;
    suc = false;
    for (int i = p.second + 1; isValid(i) && ! suc; ++ i) {
      int v = matrix[p.first][i];
      if (v - last != 1) break;
      if (v == 7) suc = true;

      last = v;
    }

    if (suc) {
      for (int i = 0; i < 7; ++ i) {
	out[p.first][p.second + i] = matrix[p.first][p.second + i];
      }
    }

    // BOTTOM
    last = 1;
    suc = false;
    for (int i = p.first + 1; isValid(i) && ! suc; ++ i) {
      int v = matrix[i][p.second];
      if (v - last != 1) break;
      if (v == 7) suc = true;

      last = v;
    }

    if (suc) {
      for (int i = 0; i < 7; ++ i) {
	out[p.first + i][p.second] = matrix[p.first + i][p.second];
      }
    }

    // TOP_LEFT
    last = 1;
    suc = false;
    for (int i = p.first - 1, j = p.second - 1; isValid(i) && isValid(j) && ! suc; -- i, -- j) {
      int v = matrix[i][j];
      if (v - last != 1) break;
      if (v == 7) suc = true;

      last = v;
    }

    if (suc) {
      for (int i = 0; i < 7; ++ i) {
	out[p.first - i][p.second - i] = matrix[p.first - i][p.second - i];
      }
    }

    // TOP_RIGHT
    last = 1;
    suc = false;
    for (int i = p.first - 1, j = p.second + 1; isValid(i) && isValid(j) && ! suc; -- i, ++ j) {
      int v = matrix[i][j];
      if (v - last != 1) break;
      if (v == 7) suc = true;

      last = v;
    }

    if (suc) {
      for (int i = 0; i < 7; ++ i) {
	out[p.first - i][p.second + i] = matrix[p.first - i][p.second + i];
      }
    }

    // BOTTOM_LEFT
    last = 1;
    suc = false;
    for (int i = p.first + 1, j = p.second - 1; isValid(i) && isValid(j) && ! suc; ++ i, -- j) {
      int v = matrix[i][j];
      if (v - last != 1) break;
      if (v == 7) suc = true;

      last = v;
    }

    if (suc) {
      for (int i = 0; i < 7; ++ i) {
	out[p.first + i][p.second - i] = matrix[p.first + i][p.second - i];
      }
    }

    // BOTTOM_RIGHT
    last = 1;
    suc = false;
    for (int i = p.first + 1, j = p.second + 1; isValid(i) && isValid(j) && ! suc; ++ i, ++ j) {
      int v = matrix[i][j];
      if (v - last != 1) break;
      if (v == 7) suc = true;

      last = v;
    }

    if (suc) {
      for (int i = 0; i < 7; ++ i) {
	out[p.first + i][p.second + i] = matrix[p.first + i][p.second + i];
      }
    }
  }
}

auto readMatrix() -> void {
  matrix = new int*[n];
  out = new int*[n];
  
  for (int i = 0; i < n; ++ i) {
    matrix[i] = new int[n];
    out[i] = new int[n];
    std::memset(out[i], 0, sizeof(int) * n);
    
    for (int j = 0; j < n; ++ j) {
      char c;
      std::cin >> c;
      
      switch (c) {
      case 'y': matrix[i][j] = 1; starts.push_back(pos(i, j)); break;
      case 'i': matrix[i][j] = 2; break;
      case 'z': matrix[i][j] = 3; break;
      case 'h': matrix[i][j] = 4; break;
      case 'o': matrix[i][j] = 5; break;
      case 'n': matrix[i][j] = 6; break;
      case 'g': matrix[i][j] = 7; break;
      default: matrix[i][j] = 0; break;
      }
    }
  }
}

auto main(int, char **) -> int {
  std::cin >> n;

  readMatrix();
  search();

  char str[9] = "*yizhong";
  
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      std::cout << str[out[i][j]];
    }

    std::cout << std::endl;
  }
  
  return 0;
}
