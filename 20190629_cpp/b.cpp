#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> p;

  for (int i = 0; i < n; ++i) {
    int tp;
    std::cin >> tp;
    p.push_back(tp);
  }

  int count = 0;
  for (int i = 0, e = p.size(); i + 2 < e; ++i) {
    if ((p[i] < p[i + 1]) && (p[i + 1] < p[i + 2])) {
      ++count;
    } else if ((p[i] > p[i + 1]) && (p[i + 1] > p[i + 2])) {
      ++count;
    }
  }

  std::cout << count << std::endl;
}
