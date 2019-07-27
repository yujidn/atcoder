#include <iostream>

int main() {
  int64_t a, b;
  std::cin >> a >> b;
  if (a > b) {
    int t = b;
    b = a;
    a = t;
  }

  int64_t k = (b + a) / 2;
  if (std::abs(a - k) != std::abs(b - k)) {
    std::cout << "IMPOSSIBLE" << std::endl;
  } else {
    std::cout << k << std::endl;
  }
  return 0;
}

