#include <iostream>

int main() {
  int n, a, b;
  std::cin >> n >> a >> b;

  int train = a * n;
  int taxi = b;

  if (train > taxi)
    std::cout << taxi << std::endl;
  else
    std::cout << train << std::endl;
  return 0;
}

