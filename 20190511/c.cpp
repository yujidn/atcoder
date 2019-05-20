#include <iostream>
#include <string>
#include <vector>

int main() {
  int N;
  std::vector<std::string> s_vec;
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    std::string sin;
    std::cin >> sin;
    s_vec.push_back(sin);
  }

  int frontB = 0;
  int endA = 0;
  int fBeA = 0;
  int insertAB = 0;

  for (auto &s : s_vec) {
    const int &size = s.size();
    if (size == 0) {
      continue;
    }
    bool flag = (s[0] == 'B');
    if (flag) ++frontB;

    for (int i = 1; i < size; ++i) {
      if (s[i - 1] == 'A' && s[i] == 'B') {
        ++insertAB;
      }
    }

    if (s[size - 1] == 'A') {
      ++endA;
      if (flag) {
        ++fBeA;
      }
    }
  }
  frontB -= fBeA;
  endA -= fBeA;
  int pair = 0;

  if (fBeA == 0) {
    pair = std::min(frontB, endA);
  } else {
    if ((frontB + endA) == 0) {
      pair = fBeA - 1;
    } else {
      pair = fBeA + std::min(frontB, endA);
    }
  }

  int result = insertAB + pair;

  std::cout << result;

  return 0;
}

