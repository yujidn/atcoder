#include <cstring>
#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  --k;
  int size = n + 1;
  std::vector<int64_t> dp(size * k);

  for (int64_t i = 0; i < k; ++i) {
    dp[i * size + 0] = 0;
    for (int64_t j = 1; j < size; ++j) {
      const int64_t inc = dp[j] - dp[j - 1];
      const int64_t &up = dp[(i - 1) * size + j];
      const int64_t &left = dp[i * size + j - 1];
      const int64_t &lu = dp[(i - 1) * size + j - 1];
      int64_t &now = dp[i * size + j];

      if (i == 0)
        now = n / j + left;
      else
        now = inc * (up - lu) + left;
    }
  }

  std::cout << *(dp.end() - 1) << std::endl;

  printf("     |");
  for (int j = 0; j < size; ++j) {
    printf("%5d", j);
  }
  std::cout << "\n----------------------\n";
  for (int i = 0; i < k; ++i) {
    printf("%5d|", i + 2);
    for (int j = 0; j < size; ++j) {
      printf("%5d", dp[i * size + j]);
    }
    std::cout << std::endl;
  }

  return 0;
}

