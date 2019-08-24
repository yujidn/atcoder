#include <iostream>

int main() {
  int M, D;
  std::cin >> M >> D;

  int64_t count = 0;

  for (int m = 1; m <= M; ++m) {
    for (int d2 = 2, ed2 = D / 10; d2 <= ed2; ++d2) {
      for (int d1 = 2; d1 < 10; ++d1) {
        if (d2 * 10 + d1 > D) {
          break;
        }

        if (d2 * d1 == m) {
          ++count;
        }
      }
    }
  }

  std::cout << count << std::endl;
  return 0;
}
