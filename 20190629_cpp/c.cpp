#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> d;
  for (int i = 0; i < n; ++i) {
    int td;
    std::cin >> td;
    d.push_back(td);
  }

  std::sort(d.begin(), d.end());
  int low = d[d.size() / 2 - 1];
  int high = d[d.size() / 2];

  std::cout << high - low << std::endl;
}
