#include <iostream>

int main(void) {
  int n, x;
  std::cin >> n >> x;

  int count = 1;
  int pos = 0;
  for (int i = 0; i < n; ++i) {
    int temp;
    std::cin >> temp;
    pos += temp;
    if (pos <= x) {
      ++count;
    }
  }

  std::cout << count << std::endl;
}
