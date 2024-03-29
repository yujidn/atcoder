#include <iostream>
#include <vector>

const int64_t MOD = 1000 * 1000 * 1000 + 7;

int main() {
  int64_t n, k;
  std::cin >> n >> k;

  std::vector<int64_t> cand;
  std::vector<int64_t> num;
  cand.push_back(0);
  num.push_back(0);

  for (int64_t i = 1;;) {
    auto div = n / i;
    cand.push_back(div);
    auto next = n / div + 1;
    num.push_back(next - i);
    i = next;
    if (div == 1) {
      break;
    }
  }

  --k;
  auto size = cand.size();
  std::vector<int64_t> dp(size * k);

  dp[0] = 0;
  for (int64_t j = 1; j < size; ++j) {
    int64_t &now = dp[j];
    const int64_t &left = dp[j - 1];
    now = ((cand[j] * num[j]) % MOD + left) % MOD;
  }

  for (int64_t i = 1; i < k; ++i) {
    dp[i * size + 0] = 0;
    for (int64_t j = 1; j < size; ++j) {
      int64_t &now = dp[i * size + j];
      const int64_t &val = dp[i * size - j];
      const int64_t &left = dp[i * size + j - 1];

      now = ((val * num[j]) % MOD + left) % MOD;
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

