#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>

int main() {
  int n;

  std::cin >> n;

  std::vector<int> an(n);

  for (auto &a : an) {
    std::cin >> a;
  }

  std::vector<int> result(n, 0);
  int box_num = 0;

  for (int i = n; i >= 1; --i) {
    int check_num = n / i;

    auto target = an[i - 1];
    auto sum = 0;
    while (check_num > 0) {
      sum += result[i * check_num - 1];
      --check_num;
    }
    result[i - 1] = sum & 0x01 ^ target;
    box_num += result[i - 1];
  }

  std::cout << box_num << std::endl;
  auto out = false;
  for (int i = 0; i < n; ++i) {
    if (result[i] == 1) {
      std::cout << i + 1 << " ";
      out = true;
    }
  }
  if (out) std::cout << std::endl;
  return 0;
}

