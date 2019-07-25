#include <iostream>

int main() {
  int n, d;
  std::cin >> n >> d;

  int check = d * 2 + 1;
  int hito = n / check;
  if ((n % check) != 0) {
    hito += 1;
  }

  std::cout << hito << std::endl;
  return 0;
}
