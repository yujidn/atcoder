#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int64_t n, k;
  std::cin >> n >> k;

  std::vector<int64_t> sum;
  int64_t count = 0, start = 0;

  for (int64_t i = 0, s = 0; i < n; ++i) {
    int temp;
    std::cin >> temp;
    s += temp;
    sum.push_back(s);
  }
  while ((sum[start] < k) && (start < n)) {
    ++start;
    if (sum[start] >= k) {
      break;
    }
  }
  auto begin = sum.begin();
  auto end = sum.end();
  for (int i = start; i < n; ++i) {
    auto dif = std::max((int64_t)0, sum[i] - k);
    auto iter = std::upper_bound(begin, end, dif);
    count += iter - begin + 1;
  }

  std::cout << count << std::endl;

  return 0;
}

