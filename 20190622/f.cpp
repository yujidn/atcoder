#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

const int N = 1e5 + 5;
int xy[N][N];

void check_and_add(std::map<int, std::vector<int>> &map, int x, int y) {
  if (map.count(x) == 0) {
    std::vector<int> vec;
    vec.push_back(y);
    map[x] = vec;
  } else {
    map[x].push_back(y);
  }
}

int pointcount(const std::map<int, std::vector<int>> &xmap,
               const std::map<int, std::vector<int>> &ymap) {
  int count = 0;

  for (const auto &xp : xmap) {
    const auto &fx = xp.first;
    const auto &yvec = xp.second;

    for (const auto fy : yvec) {
      const auto &xvec = ymap.at(fy);
      for (const auto sx : xvec) {
        count += (xy[sx][fy] ^ 1);
      }
    }
  }
  return count;
}

int main() {
  int n;
  std::cin >> n;
  std::map<int, std::vector<int>> xmap;
  std::map<int, std::vector<int>> ymap;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;

    check_and_add(xmap, x, y);
    check_and_add(ymap, y, x);
    xy[x][y] = 1;
  }
  std::cout << pointcount(xmap, ymap) << std::endl;

  return 0;
}

