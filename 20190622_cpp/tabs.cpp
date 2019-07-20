#include <cmath>
#include <iostream>

int main() {
  std::cout << std::abs(-1) << std::endl;
  std::cout << std::abs(0) << std::endl;
  std::cout << std::abs(1) << std::endl;

  size_t i = 0;
  std::cout << std::abs(-1 + i) << std::endl;
  return 0;
}
