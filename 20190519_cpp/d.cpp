#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

class tree {
 public:
  int v, w;
  tree(int _v, int _w) : v(_v), w(_w){};

  bool operator<(const tree &other) const { return v < other.v; }
};

int main() {
  int N;
  std::cin >> N;
  std::vector<std::vector<tree>> input(N + 1);

  for (int i = 0; i < N - 1; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    input[u].push_back(tree(v, w));
  }

  for (auto &t : input) {
    std::sort(t.begin(), t.end());
  }

  std::vector<int> result(N);

  for (int i = 1; i <= N; ++i) {
    auto &tre = input[i];
    for (int l = tre.size() - 1; 0 <= l; ++l) {
      if (tre[l] % 2 == 0) {
      }
    }
  }

  return 0;
}

