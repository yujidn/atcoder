#include <iostream>
#include <string>
#include <vector>

const int64_t MOD = 1000 * 1000 * 1000 + 7;

int main() {
  std::string s;
  std::cin >> s;

  // i番目の文字を見た時に13との剰余がnになる個数を数え上げる
  std::vector<int64_t> dp(s.length() * 13);

  {
    int val = -1;
    if (s[0] != '?') val = s[0] - '0';
    if (val == -1) {
      for (int i = 0; i < 10; ++i) {
        dp[i % 13] = 1;
      }
    } else {
      dp[val % 13] = 1;
    }
    // % 13は不要だけど定義に帰るため
  }

  for (int i = 1, e = s.length(); i < e; ++i) {
    int val = -1;
    if (s[i] != '?') val = s[i] - '0';
    if (val == -1) {
      for (int here = 0; here < 10; ++here) {
        for (int pre = 0; pre < 13; ++pre) {
          auto &here_dp = dp[i * 13 + ((pre * 10 + here) % 13)];
          const auto &pre_dp = dp[(i - 1) * 13 + pre];
          here_dp = (here_dp + pre_dp) % MOD;
        }
      }
    } else {
      for (int pre = 0; pre < 13; ++pre) {
        auto &here_dp = dp[i * 13 + ((pre * 10 + val) % 13)];
        const auto &pre_dp = dp[(i - 1) * 13 + pre];
        here_dp = (here_dp + pre_dp) % MOD;
      }
    }
  }

  std::cout << dp[(s.length() - 1) * 13 + 5] << std::endl;

  // for (int i = 0, e = s.length(); i < e; ++i) {
  // for (int j = 0; j < 13; ++j) {
  //   printf("%5d", dp[i * 13 + j]);
  // }
  // std::cout << std::endl;
  //}
  return 0;
}
