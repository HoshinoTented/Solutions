#include <bits/stdc++.h>

using T = long;

void merge(T *arr, T *out, const size_t &begin, const size_t &partition, const size_t &end) {
  size_t firstIndex = begin, secondIndex = partition, outIndex = begin;

  while (firstIndex != partition && secondIndex != end) {
    out[outIndex ++] = (arr[firstIndex] < arr[secondIndex]) ?
      arr[firstIndex ++] : arr[secondIndex ++];
  }

  size_t from, to;

  if (firstIndex == partition) {
    from = secondIndex;
    to = end;
  } else {
    from = firstIndex;
    to = partition;
  }

  while (from != to) {
    out[outIndex ++] = arr[from ++];
  }
}

void merge_sort(T *arr, T *out, const size_t &begin, const size_t &end) {
  if (end - begin == 1) out[begin] = arr[begin];
  else {
    size_t partition = (begin + end) / 2;
    T tmp[end];
    merge_sort(arr, tmp, begin, partition);
    merge_sort(arr, tmp, partition, end);
    merge(tmp, out, begin, partition, end);
  }
}

int main(int, char **) {
  int n;
  std::cin >> n;

  T arr[n];
  for (int i = 0; i < n; ++ i) std::cin >> arr[i];
  T out[n];

  merge_sort(arr, out, 0, n);

  for (T &v : out) std::cout << v << std::endl;
  
  return 0;
}
