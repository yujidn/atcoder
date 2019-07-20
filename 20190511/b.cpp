#include <iostream>

int main() {
  int R, G, B, N;
  std::cin >> R;
  std::cin >> G;
  std::cin >> B;
  std::cin >> N;

  int result = 0;

  for (int r = 0, r_limit = N / R; r <= r_limit; ++r) {
    int r_buy = r * R;
    for (int g = 0, g_limit = (N - r_buy) / G; g <= g_limit; ++g) {
      int g_buy = g * G;
      if (((N - r_buy - g_buy) % B) == 0) {
        ++result;
      }
    }
  }
  std::cout << result;
  return 0;
}
