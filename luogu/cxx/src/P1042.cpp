#include <iostream>
#include <vector>

auto push(std::vector<std::pair<int, int>> &v, const int &win, const int &lose) -> void {
  v.push_back(std::pair<int, int>(win, lose));
}

auto isFinish(const int &max, const int &win, const int &lose) -> bool {
  int diff = std::abs(win - lose) >= 2;
  if (max > win && max > lose) return false;
  if (diff && ((win == max && max > lose) || (lose == max && max > win))) return true;
  return std::abs(win - lose) == 2;
}

auto main(int, char **) -> int {
  int win11, lose11;
  int win21, lose21;
  std::vector<std::pair<int, int>> wins11, wins21;
  char c;

  win11 = lose11 = win21 = lose21 = 0;

  while (true) {
    std::cin >> c;

    if (c == 'E') {
      push(wins11, win11, lose11);
      push(wins21, win21, lose21);
      
      break;
    }
    
    if (c == 'W') {
      ++ win11;
      ++ win21;
    } else {
      ++ lose11;
      ++ lose21;
    }

    if (isFinish(11, win11, lose11)) {
      push(wins11, win11, lose11);
      win11 = lose11 = 0;
    }

    if (isFinish(21, win21, lose21)) {
      push(wins21, win21, lose21);
      win21 = lose21 = 0;
    }
  }

  for (auto &wins : wins11) {
    std::cout << wins.first << ':' << wins.second << std::endl;
  }

  std::cout << std::endl;

  for (auto &wins : wins21) {
    std::cout << wins.first << ':' << wins.second << std::endl;
  }

  return 0;
}
