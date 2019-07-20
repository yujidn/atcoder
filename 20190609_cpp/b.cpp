#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int64_t> sum(N);
  int64_t ss = 0;
  for (int i = 0; i < N; ++i) {
    int temp;
    std::cin >> temp;
    ss = temp + ss;
    sum[i] = ss;
  }

  int64_t absmin = 1 << 31 - 1;
  auto last = sum[N - 1];
  for (int i = 0; i < N - 1; ++i) {
    int64_t l = sum[i];
    int64_t r = last - sum[i];
    auto abs = std::abs(l - r);
    if (abs < absmin) absmin = abs;
  }

  std::cout << absmin << std::endl;
}
