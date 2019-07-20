#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  int max = (n - 2) * (n - 1) / 2;  // 蜘蛛っぽい形の時
  std::vector<std::pair<int, int>> result;
  if (max >= k) {
    // まずはmaxを作る
    for (size_t i = 1; i < n; ++i) {
      result.push_back(std::make_pair(1, i + 1));
    }

    int i = 2;
    int e = max - k;  // 何本追加するか
    while (e > 0) {
      for (size_t j = 1; i + j <= n; ++j) {
        result.push_back(std::make_pair(i, i + j));
        if (--e == 0) {
          break;
        }
      }
      ++i;
    }
  }

  if (result.size() == 0) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << result.size() << std::endl;
    for (auto &p : result) {
      std::cout << p.first << " " << p.second << std::endl;
    }
  }
}
