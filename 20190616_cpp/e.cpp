#include <iostream>
#include <vector>

const int MOD = 1000 * 1000 * 1000 + 7;

int main(void) {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> s(n);
  std::vector<int> t(m);
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> t[i];
  }
  int sl = n + 1;
  int tl = m + 1;
  std::vector<int64_t> dp(sl * tl);
  std::vector<int64_t> sum(sl * tl);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i - 1] == t[j - 1]) {
        dp[i * tl + j] = (sum[(i - 1) * tl + j - 1] + 1) % MOD;
      }
      sum[i * tl + j] = (sum[(i - 1) * tl + j] + sum[i * tl + j - 1] -
                         sum[(i - 1) * tl + j - 1] + dp[i * tl + j] + MOD) %
                        MOD;
    }
  }

  std::cout << (sum[n * tl + m] + 1) % MOD << std::endl;

  std::cout << "sum matrix" << std::endl;

  for (int i = 0; i <= n; ++i) {
    if (i != 0) printf("%5d|", s[i - 1]);
    for (int j = 0; j <= m; ++j) {
      if (i == 0) {
        if (j == 0)
          std::cout << "     |";
        else
          printf("%5d ", t[j - 1]);
      } else {
        if (j != 0) printf("%5d ", sum[i * tl + j]);
      }
    }
    if (i == 0) {
      std::cout << std::endl;
      for (int j = 0; j <= m; ++j) {
        std::cout << "------";
      }
    }
    std::cout << std::endl;
  }

  std::cout << "dp matrix" << std::endl;
  for (int i = 0; i <= n; ++i) {
    if (i != 0) printf("%5d|", s[i - 1]);
    for (int j = 0; j <= m; ++j) {
      if (i == 0) {
        if (j == 0)
          std::cout << "     |";
        else
          printf("%5d ", t[j - 1]);
      } else {
        if (j != 0) printf("%5d ", dp[i * tl + j]);
      }
    }
    if (i == 0) {
      std::cout << std::endl;
      for (int j = 0; j <= m; ++j) {
        std::cout << "------";
      }
    }
    std::cout << std::endl;
  }
  return 0;
}

