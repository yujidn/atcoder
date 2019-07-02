#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  // 経路
  std::vector<std::vector<int>> path(n);

  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    // 順経
    path[u].push_back(v);
  }

  int s, t;
  std::cin >> s >> t;
  --s, --t;

  const int goal = 3 * t;

  // 到着タグ
  std::vector<int> visited(3 * n);
  std::memset(&visited[0], -1, sizeof(int) * visited.size());

  visited[3 * s] = 0;

  std::queue<int> order;
  order.push(3 * s);

  while (!order.empty() && (visited[goal] == -1)) {
    int now = order.front();
    order.pop();

    int step = visited[now] + 1;

    auto &next_list = path[now / 3];
    const auto kenpa = step % 3;
    for (auto next : next_list) {
      int next_pos = 3 * next + kenpa;
      auto &v = visited[next_pos];
      if (v == -1) {
        v = step;
        order.push(next_pos);
      }
    }
  }

  if (visited[goal] != -1) {
    std::cout << visited[goal] / 3 << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }

  // // debug
  // std::cout << "=====" << std::endl;
  // for (int i = 0; i < visited.size(); i += 3) {
  //   printf("%5d %5d %5d\n", visited[i], visited[i + 1], visited[i + 2]);
  // }
}
