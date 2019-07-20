#include <iostream>
#include <map>
#include <vector>

int main() {
  int Q;
  std::cin >> Q;
  int64_t a, b, base;
  int64_t l_slope = -1, r_slope = 1;
  int64_t base_count = 1;
  int64_t bsum = 0;

  std::cin >> a >> base >> bsum;
  std::map<int64_t, int64_t> l;
  std::map<int64_t, int64_t> r;

  std::vector<std::pair<int64_t, int64_t>> result;

  int qtype;
  for (int i = 1; i < Q; ++i) {
    std::cin >> qtype;
    if (qtype == 1) {
      std::cin >> a >> b;
      bsum += b;
      if (base == a) {
        --l_slope;
        ++r_slope;
        ++base_count;
      } else if (base > a) {
        l.insert(std::make_pair(a, a));
        ++l_slope;
        ++r_slope;
      } else {
        r.insert(std::make_pair(a, a));
        --l_slope;
        --r_slope;
      }
    } else {
      auto slope = l_slope + r_slope;
      int x = 0;
      if (slope == 0) {
        x = base;
      } else if (slope > 0) {
        int pos = l.size() - r_slope / 2;

        auto iter = l.rbegin();
        int p = 0;
        for (; p != pos; ++p, iter++) {
        }
        x = (*iter).first;
      } else {
        int pos = -l_slope / 2 - 1;

        auto iter = r.begin();
        int p = 0;
        for (; p != pos; ++p, iter++) {
        }
        x = (*iter).first;
      }

      int64_t xasum = std::abs(x - base) * base_count;

      for (auto &_l : l) {
        xasum += std::abs(x - _l.first);
      }
      for (auto &_r : r) {
        xasum += std::abs(x - _r.first);
      }
      result.push_back(std::make_pair(x, xasum + bsum));
    }
  }
  for (auto &r : result) {
    std::cout << r.first << " " << r.second << std::endl;
  }
  return 0;
}
