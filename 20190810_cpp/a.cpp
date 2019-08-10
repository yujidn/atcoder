#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;

  std::cout << std::max(std::max(a + b, a - b), a * b) << std::endl;

  return 0;
}

