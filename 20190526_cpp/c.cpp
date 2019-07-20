#include <iostream>
#include <vector>

int main() {
  int N, M;
  std::cin >> N >> M;

  std::vector<std::vector<int>> sij(M);
  std::vector<int> p(M);

  for (int i = 0; i < M; ++i) {
    int k, s;
    std::cin >> k;
    sij[i].reserve(k);
    for (int j = 0; j < k; ++j) {
      std::cin >> s;
      sij[i].push_back(s - 1);
    }
  }
  for (int i = 0; i < M; ++i) {
    std::cin >> p[i];
  }

  int result = 0;
  for (int sw = 0, end = 1 << N; sw < end; ++sw) {
    bool ok = true;
    for (int i = 0; i < sij.size(); ++i) {
      auto &sj = sij[i];
      int sum = 0;
      for (auto s : sj) {
        sum += sw >> s;
      }
      if ((sum % 2) != p[i]) {
        ok = false;
        break;
      }
    }

    if (ok) {
      ++result;
    }
  }
  std::cout << result << std::endl;

  return 0;
}
