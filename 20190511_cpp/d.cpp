#include <iostream>

int main() {
  int64_t N;
  std::cin >> N;
  int64_t sum = 0;

  int64_t same = 1;  // 商とあまり
  while (true) {
    int64_t temp = N - same;
    if ((temp % same) == 0) {
      int64_t fav = temp / same;
      std::cout << same << "," << fav << std::endl;
      sum += fav;
    }

    if ((temp / same) == 1) {
      break;
    }

    ++same;
  }

  std::cout << sum;

  return 0;
}

