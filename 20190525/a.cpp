#include <iostream>

int main() {
  int A, B;
  std::cin >> A >> B;

  if (A <= 12) {
    if (6 <= A) {
      B /= 2;
    } else {
      B = 0;
    }
  }

  int result = B;
  std::cout << result << std::endl;

  return 0;
}
