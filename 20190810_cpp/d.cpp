#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>

int main() {
  int N, M;
  std::cin >> N >> M;
  std::map<int, std::vector<int>> baito;
  // std::vector<std::pair<int, int>> mergin;

  for (int i = 0; i < N; ++i) {
    int a, b;
    std::cin >> a >> b;
    // mergin.push_back(std::make_pair(b, a));
    if (baito.count(a) == 0) {
      std::vector<int> vec;
      vec.push_back(b);
      baito.insert(std::make_pair(a, vec));
    } else {
      baito[a].push_back(b);
    }
  }

  int count = 0;
  std::priority_queue<int> pq;
  for (int i = 1; i <= M; ++i) {
    if (baito.count(i) > 0) {
      for (auto m : baito[i]) {
        pq.push(m);
      }
    }

    if (!pq.empty()) {
      count += pq.top();
      pq.pop();
    }
  }
  std::cout << count << std::endl;
  return 0;
}
