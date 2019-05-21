#include <iostream>
#include <queue>
#include <vector>

int main() {
  int N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int>> hint(N);
  std::vector<int> lut(N);

  for (int i = 0; i < M; ++i) {
    int x, y, z;
    std::cin >> x >> y >> z;
    hint[x - 1].push_back(y - 1);
    hint[y - 1].push_back(x - 1);
  }

  std::queue<int> chain;
  int num = 0;

  for (int i = 0; i < N; ++i) {
    int table;
    if (lut[i] == 0) {
      ++num;
      lut[i] = num;
    } else {
      continue;
    }

    chain.push(i);

    while (!chain.empty()) {
      auto c = chain.front();
      for (auto &h : hint[c]) {
        if (lut[h] == 0) {
          lut[h] = num;
          chain.push(h);
        }
      }
      hint[c].clear();
      chain.pop();
    }
  }

  int result = num;

  std::cout << result << std::endl;

  return 0;
}
