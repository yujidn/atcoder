#include <iostream>

int abs(int i) {
  if (i < 0) {
    return -i;
  }
  return i;
}

int main() {
  int n, l;
  std::cin >> n >> l;

  int sum = n * l + n * (n - 1) / 2;

  int diff = std::abs(sum);
  int result = 0;

  for (size_t i = 0; i < n; ++i) {
    int d = abs(l + i);
    if (diff > d) {
      result = sum - (l + i);
      diff = d;
    }
  }
  std::cout << result << std::endl;
}
