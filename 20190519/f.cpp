#include <cmath>
#include <iostream>
#include <vector>

int main() {
  int M, K;
  std::cin >> M >> K;

  int max = 1 << M;
  std::vector<int> result(max * 2);

  if (max <= K) {
    std::cout << -1 << std::endl;
    return 0;
  }

  if (M == 0) {
    if (K == 1) {
      std::cout << -1 << std::endl;
      return 0;
    } else {
      result[0] = 0;
      result[1] = 0;
    }
  } else if (M == 1) {
    if (K == 1) {
      std::cout << -1 << std::endl;
      return 0;
    } else {
      result[0] = 0;
      result[1] = 0;
      result[2] = 1;
      result[3] = 1;
    }
  } else {
    // 最初と真ん中らへんにKを配置する
    result[0] = result[max] = K;

    int val = 0;
    for (int i = 1; i < max; ++i) {
      if (val == K) {
        ++val;
      }
      result[i] = result[result.size() - i] = val;
      ++val;
    }
  }

  for (auto r : result) {
    std::cout << r << " ";
  }
  std::cout << std::endl;
}
