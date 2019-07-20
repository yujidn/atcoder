#include <cmath>
#include <iostream>
#include <vector>

int main() {
  int n, d;
  std::cin >> n >> d;

  std::vector<std::vector<int>> points;
  for (int i = 0; i < n; ++i) {
    std::vector<int> point(d);
    for (int j = 0; j < d; ++j) {
      int x;
      std::cin >> point[j];
    }
    points.push_back(point);
  }

  int count = 0;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      auto &pi = points[i];
      auto &pj = points[j];

      int sum = 0;
      for (int k = 0; k < d; ++k) {
        auto diff = pi[k] - pj[k];
        sum += diff * diff;
      }

      int rt = std::sqrt(sum);

      if (rt * rt == sum) {
        ++count;
      }
    }
  }

  std::cout << count << std::endl;
  return 0;
}

