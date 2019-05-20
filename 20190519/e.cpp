#include <iostream>
#include <tuple>
#include <vector>

class Hint {
 public:
  int y, z;
  Hint(int _y, int _z) : y(_y), z(_z){};
};

int main() {
  int N, M;
  std::cin >> N >> M;
  std::vector<std::vector<Hint>> hint(N);
  std::vector<int> lut(N);

  for (int i = 0; i < M; ++i) {
    int x, y, z;
    std::cin >> x >> y >> z;
    hint[x - 1].push_back(Hint(y - 1, z));
  }

  int num = 0;
  for (int i = 0; i < N; ++i) {
    int table;
    if (lut[i] == 0) {
      ++num;
      table = num;
    } else {
      table = lut[i];
    }

    for (auto &h : hint[i]) {
      lut[i] = table;
      lut[h.y] = table;
    }
  }

  int nohint = 0;
  for (auto &l : lut) {
    if (l == 0) {
      ++nohint;
    }
  }

  int result = num;
  if ((num == 1) && (nohint == 0)) {
    result = 0;
  }

  std::cout << result << std::endl;

  return 0;
}
