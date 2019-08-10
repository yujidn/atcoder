#include <iostream>

int main() {
  int k, x;
  std::cin >> k >> x;
  const int min_pos = -1000000;
  const int max_pos = 1000000;

  if (x - k < min_pos) {
  }

  for (int i = std::max(x - k + 1, min_pos), e = std::min(x + k, max_pos);
       i < e; ++i) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
