#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  int size = n + 1;
  std::vector<int> dp(size * k);

  dp[0] = 0;
  for (int i = 1; i < size; ++i) {
    dp[i] = 1;
  }

  for (int i = 1; i < k; ++i) {
    dp[i * size + 0] = 0;
    for (int j = 1; j < size; ++j) {
      const int &up = dp[(i - 1) * size + j];
      const int &left = dp[i * size + j - 1];
      int &now = dp[i * size + j];
      if (j * j <= n)
        now = n / j * up + left;
      else
        now = n / j + left;
    }
  }

  std::cout << *(dp.end() - 1) << std::endl;

  for (auto d : dp) {
    std::cout << d << std::endl;
  }
  return 0;
}

