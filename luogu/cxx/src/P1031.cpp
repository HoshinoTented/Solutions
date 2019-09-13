#include <bits/stdc++.h>

int n, request, moveSum;
int *nums;

// pure
auto req(const int &n) -> int {
  return request - n;
}

auto sumOfDiff(const int &b, const int &e) -> int {
  if (b == e) return 0;
  return req(nums[b]) + sumOfDiff(b + 1, e);
}

auto move() -> void {
  moveSum = 0;
  
  for (int i = 0; i < n; ++ i) {
    int reqValue = req(nums[i]);
    
    if (reqValue >= 0) continue;
    
    int reqL = sumOfDiff(0, i);
    int reqR = sumOfDiff(i + 1, n);

    nums[i] = request;
    
    if (! reqL) {
      nums[i + 1] -= reqValue;
    } else if (! reqR) {
      nums[i - 1] -= reqValue;
      i -= 2;
    } else {
      nums[i - 1] += reqL;
      nums[i + 1] += reqR;

      i -= 2;
      
      ++ moveSum;
    }

    ++ moveSum;
  }
}

auto main(int, char **) -> int {
  int sum = 0;
  
  std::cin >> n;

  nums = new int[n];

  for (int i = 0; i < n; ++ i) {
    std::cin >> nums[i];
    sum += nums[i];
  }

  request = sum / n;

  move();
  
  std::cout << moveSum << std::endl;
  
  return 0;
}
