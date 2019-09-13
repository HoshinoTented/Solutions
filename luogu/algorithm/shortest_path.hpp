#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <cmath>

#define INF 65535

constexpr int len = 9;
int graph[len][len] = {
  {  0,   1,   5, INF, INF, INF, INF, INF, INF}, 
  {  1,   0,   3,   7,   5, INF, INF, INF, INF},
  {  5,   3,   0, INF,   1,   7, INF, INF, INF},
  {INF,   7, INF,   0,   2, INF,   3, INF, INF},
  {INF,   5,   1,   2,   0,   3,   6,   9, INF},
  {INF, INF,   7, INF,   3,   0, INF,   5, INF},
  {INF, INF, INF,   3,   6, INF,   0,   2,   7},
  {INF, INF, INF, INF,   9,   5,   2,   0,   4},
  {INF, INF, INF, INF, INF, INF,   7,   4,   0}
};

auto search(const int &begin, int *nearest, int *shortest) -> void {
  bool finished[len];

  for(size_t i = 0; i < len; i++) {
    shortest[i] = (i == begin ? 0 : INF);
    nearest[i] = 0; 
    finished[i] = false;
  }

  for(size_t i = 0; i < len; i++) {
    int nv = INF, ni = -1;   // nearest weight and index

    for(size_t j = 0; j < len; j++) {
      if (! finished[j] && shortest[j] <= nv) {
        nv = shortest[ni = j];
      }
    }
    
    finished[ni] = true;

    for(size_t j = 0; j < len; j++) {
      shortest[j] = std::min(shortest[j], shortest[ni] + graph[ni][j]);

      if (! finished[j]) nearest[j] = ni;
    }
  }
}

auto main(int, char **) -> int {
  int begin = 0;
  auto *ns = new int[len];
  auto *ss = new int[len];
  search(begin, ns, ss);

  for (int i = 0; i < len; ++ i) {
    std::cout << ss[i] << " ";
  }

  std::cout << std::endl;

  for (int i = 0; i < len; ++ i) {
    std::cout << ns[i] << " ";
  }

  std::cout << std::endl;
  
  return 0;
}
