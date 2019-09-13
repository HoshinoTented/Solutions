#ifndef LUOGU_P3955_HPP
#define LUOGU_P3955_HPP

#include <bits/stdc++.h>

auto check(const std::string &b, const std::string &v) -> bool {
  if (b.size() < v.size()) return false;

  int begin = b.size() - v.size();
  
  for (size_t i = begin; i < b.size(); ++ i) {
    if (b[i] != v[i - begin]) return false;
  }

  return true;
}

auto main(int, char **) -> int {
  int n, q;
  std::cin >> n >> q;
  int bs[n];
  
  for (int i = 0; i < n; ++ i) {
    std::cin >> bs[i];
  }

  std::sort(bs, bs + n);

  for (int i = 0; i < q; ++ i) {
    int l, v;
    bool found = false;
    std::cin >> l >> v;
    
    for (int i = 0; i < n && ! found; ++ i) {
      if (check(std::to_string(bs[i]), std::to_string(v))) {
	std::cout << bs[i] << std::endl;
	found = true;
      }
    }

    if (! found) std::cout << -1 << std::endl;
  }
  
  return 0;
}

#endif //LUOGU_P3955_HPP
