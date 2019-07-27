#include <iostream>
#include <vector>

int main() {
  int k;
  std::cin >> k;
  int gx, gy;
  std::cin >> gx >> gy;
  int dist = std::abs(gx) + std::abs(gy);

  std::vector<std::pair<int, int>> ans;

  // 移動が偶数で距離が奇数の場合はどうしようもない
  if (((k & 0x01) == 0) && ((dist & 0x01) == 1)) {
    std::cout << -1 << std::endl;
  } else {
    if ((dist % k) == 0) {
      // 調整不要
      while (gx > 0) {
        if (gx > k) {
          ans.push_back(std::make_pair(gx - k, gy));
          gx -= k;
        } else {
          k -= gx;
          ans.push_back(std::make_pair(0, gy - k));
        }
      }
    }
  }
  return 0;
}
