#include <iostream>

int main() {
  int r, D, x2000;
  std::cin >> r >> D >> x2000;

  for (int i = 0; i < 10; ++i) {
    x2000 = r * x2000 - D;
    int result = x2000;
    std::cout << result << std::endl;
  }

  return 0;
}
