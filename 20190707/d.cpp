#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> dam(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> dam[i];
  }
  std::vector<int> yama(n);

  yama[0] = 0;
  for (int i = 0; i < n; ++i) {
    yama[0] += (i % 2 == 0) ? dam[i] : -1 * dam[i];
  }

  for (int i = 1; i < n; ++i) {
    yama[i] = (dam[i - 1] - yama[i - 1] / 2) * 2;
  }

  for (int i = 0; i < n; ++i) {
    std::cout << yama[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
