#include <algorithm>
#include <cmath>
#include <iostream>

// あまり大きな数字を入れると桁溢れする
uint64_t comb(uint64_t n, uint64_t r) {
  // 組み合わせ計算時のかぶっている部分を取り除く
  r = std::min(n - r, r);
  uint64_t result = 1;
  for (int i = 1; i <= r; ++i) {
    result *= (n - i + 1);
    result /= i;
  }
  return result;
}

int main() {
  int N, M, K;
  std::cin >> N >> M >> K;

  uint64_t xsum = 0;
  int M2 = M * M;
  for (int xdiff = 1; xdiff <= N; ++xdiff) {
    xsum = xsum + xdiff * M2 * (N - xdiff);
  }

  uint64_t ysum = 0;
  int N2 = N * N;
  for (int ydiff = 1; ydiff <= N; ++ydiff) {
    ysum = ysum + ydiff * N2 * (M - ydiff);
  }

  // uint64_t result = (xsum + ysum) * p / k % (1000 * 1000 * 1000 + 7);
  uint64_t result = (xsum + ysum) * comb(N * M - 2, K - 2);
  std::cout << result << std::endl;

  return 0;
}
