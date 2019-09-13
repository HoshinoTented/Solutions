#include <bits/stdc++.h>
#define MAX 500000

size_t sum = 0;

auto merge(int *arr, int *out, const int &begin, const int &part, const int &end) -> void {
  int firstIx = begin, secondIx = part, outIx = begin;

  while (firstIx != part && secondIx != end) {
    if (arr[secondIx] < arr[firstIx]) {
      sum += part - firstIx;

      out[outIx ++] = arr[secondIx ++];
    } else out[outIx ++] = arr[firstIx ++];
  }

  while (firstIx != part) {
    out[outIx ++] = arr[firstIx ++];
  }

  while (secondIx != end) {
    out[outIx ++] = arr[secondIx ++];
  }
}

auto merge_sort(int *arr, int *out, const int &begin, const int &end) -> void {
  if (end - begin == 1) {
    out[begin] = arr[begin];
    return;
  }
  
  int part = (begin + end) / 2;

  int tmp[end];

  merge_sort(arr, tmp, begin, part);
  merge_sort(arr, tmp, part, end);
  merge(tmp, out, begin, part, end);
}

auto main(int, char **) -> int {
  int n;
  
  std::cin >> n;

  int arr[n], out[n];
  
  for (int i = 0; i < n; ++ i) {
    std::cin >> arr[i];
  }

  merge_sort(arr, out, 0, n);
  
  std::cout << sum << std::endl;

#ifdef HOSHINO_DEBUG
  for (int i = 0; i < n; ++ i) {
    std::cout << out[i] << ' ';
  }

  std::cout << std::endl;
#endif
  
  return 0; 
}
