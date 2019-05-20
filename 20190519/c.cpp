#include <iomanip>
#include <iostream>

int main() {
  int N, K;
  std::cin >> N >> K;

  double over_K = 0.0;

  double sum = 0.0;
  for (int i = 1; i <= N; ++i) {
    int v = i;
    double prov = 1.0;
    while (v < K) {
      prov *= 0.5;
      v *= 2;
    }
    sum += prov;
  }

  double result = sum / N;

  std::cout << std::setprecision(20) << result << std::endl;

  return 0;
}
