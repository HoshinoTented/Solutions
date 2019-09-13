#ifndef LUOGU_P1030_HPP
#define LUOGU_P1030_HPP

#include <iostream>
#include <string>
#include <algorithm>

auto preorder(const std::string &mid, const std::string &p, const size_t &len, const std::string::const_iterator &mBegin, const std::string::const_iterator &pBegin) -> void {
  if (! len) return;
  char rootC = *(pBegin + len - 1);
  std::cout << rootC;
  if (len > 1) {
    auto mRootIt = std::find(mBegin, mBegin + len, rootC);
    auto nLLen = static_cast<size_t>(mRootIt - mBegin);
    auto nRLen = static_cast<size_t>(mBegin + len - (mRootIt + 1));
    
    preorder(mid, p, nLLen, mBegin, pBegin);
    preorder(mid, p, nRLen, mRootIt + 1, pBegin + nLLen);
  }
}

auto main(int, char**) -> int {
  std::string mid, post;
  std::cin >> mid >> post;

  preorder(mid, post, mid.size(), mid.begin(), post.begin());

  std::cout << std::endl;
  
  return 0;
}

#endif
