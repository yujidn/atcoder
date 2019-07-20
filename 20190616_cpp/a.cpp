#include <iostream>

int main(void) {
  int X, A;
  std::cin >> X >> A;
  if (X < A) {
    std::cout << 0 << std::endl;
  } else {
    std::cout << 10 << std::endl;
  }
  return 0;
}

