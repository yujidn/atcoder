#include <iostream>

int main() {
  uint64_t l, r;
  std::cin >> l >> r;

  uint64_t result = 2019;
  if (((l % 2019) == 0) || ((r % 2019) == 0) || (r - l + 1 > 2019)) {
    result = 0;
  } else {
    for (size_t i = l; i + 1 <= r; ++i) {
      for (size_t j = i + 1; j <= r; ++j) {
        auto t = (i * j) % 2019;
        if (result > t) {
          result = t;
        }
      }
    }
  }
  std::cout << result << std::endl;

  return 0;
}

