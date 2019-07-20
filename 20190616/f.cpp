#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

int dmaxmin(const std::vector<std::tuple<int, int>> &vec, int sec,
            const int minimm, const int maximm) {
  if (vec.size() == 0) {
    return maximm - minimm;
  }
  int min = minimm;
  int max = maximm;
  for (auto &v : vec) {
    auto pos = std::get<0>(v);
    auto vel = std::get<1>(v);
    pos += (vel * sec);
    if (pos < min) {
      min = pos;
    }
    if (max < pos) {
      max = pos;
    }
  }
  return max - min;
}

int main() {
  int n;
  std::vector<std::tuple<int, int>> x_mut, y_mut;
  std::vector<int> x_immut, y_immut;

  for (int i = 0; i < n; ++i) {
    int x, y;
    char d;
    std::cin >> x >> y >> d;
    switch (d) {
      case 'R':
        x_mut.push_back(std::make_tuple(x, 1));
        y_immut.push_back(y);
        break;
      case 'L':
        x_mut.push_back(std::make_tuple(x, -1));
        y_immut.push_back(y);
        break;
      case 'U':
        y_mut.push_back(std::make_tuple(y, 1));
        x_immut.push_back(x);
        break;
      case 'D':
        y_mut.push_back(std::make_tuple(y, -1));
        x_immut.push_back(x);
        break;
    }
  }

  int x_imm_max = *std::max_element(x_immut.begin(), x_immut.end()),
      x_imm_min = *std::min_element(x_immut.begin(), x_immut.end()),
      y_imm_max = *std::max_element(y_immut.begin(), y_immut.end()),
      y_imm_min = *std::min_element(y_immut.begin(), y_immut.end());

  return 0;
}
