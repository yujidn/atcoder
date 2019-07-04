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

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      auto &now = dp[tl * i + j];
      auto &left = dp[tl * i + j - 1];
      auto &up = dp[tl * (i - 1) + j];
      auto &lu = dp[tl * (i - 1) + j - 1];

      now = (left + up) % MOD;
      if (s[i - 1] == t[j - 1])
        now = (now + 1) % MOD;
      else
        now = (now + MOD - lu) % MOD;
    }
  }

  std::cout << (dp[n * tl + m] + 1) % MOD << std::endl;

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

