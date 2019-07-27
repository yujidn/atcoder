#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> an(n + 1);
  std::vector<int> bn(n);
  for (auto &a : an) {
    std::cin >> a;
  }
  for (auto &b : bn) {
    std::cin >> b;
  }

  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    if (an[i] > bn[i]) {
      an[i] -= bn[i];
      sum += bn[i];
    } else {
      bn[i] -= an[i];
      sum += an[i];
      an[i] = 0;
      int before = an[i + 1];
      an[i + 1] = std::max(an[i + 1] - bn[i], 0);
      sum += before - an[i + 1];
    }
  }
  std::cout << sum << std::endl;
  return 0;
}

