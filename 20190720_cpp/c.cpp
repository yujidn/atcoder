#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> an(n);

  for (auto &a : an) {
    std::cin >> a;
  }
  auto copy = an;

  std::sort(copy.begin(), copy.end());
  auto champ = *(copy.end() - 1);
  auto schamp = *(copy.end() - 2);

  for (const auto a : an) {
    auto result = champ;
    if (champ == a) {
      result = schamp;
    }
    std::cout << result << std::endl;
  }
  return 0;
}

