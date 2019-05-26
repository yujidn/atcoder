#include <iostream>

int main() {
  int N, M;
  std::cin >> N >> M;
  int lmax = -1, rmin = 999999999;
  for (int i = 0; i < M; ++i) {
    int L, R;
    std::cin >> L >> R;
    if (L > lmax) lmax = L;
    if (rmin > R) rmin = R;
  }

  int result = rmin - lmax + 1;

  if (result < 0) result = 0;
  std::cout << result << std::endl;

  return 0;
}
