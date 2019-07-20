#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int64_t> an(n);

  for (auto& a : an) {
    std::cin >> a;
  }

  int64_t max = -1;
  int64_t color = 0;

  for (auto iter = an.rbegin(); iter != an.rend(); ++iter) {
    if (*iter >= max) {
      max = *iter;
      ++color;
    }
  }

  std::cout << color << std::endl;
  return 0;
}
