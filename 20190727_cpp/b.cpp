#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> pn(n);

  for (auto &p : pn) {
    std::cin >> p;
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (pn[i] != i + 1) {
      ++count;
    }
  }

  if (count == 2 || count == 0) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  return 0;
}
