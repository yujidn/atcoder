#include <iostream>

// 最大公約数
template <typename T>
T gcd(T a, T b) {
  if (b > a) {
    T tmp = a;
    a = b;
    b = tmp;
  }
  // 避け
  if (a <= 0) {
    return -1;
  }

  T r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}
template <typename T = float>
T gcd(T a, T b);
template <typename T = double>
T gcd(T a, T b);

// 最小公倍数
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
template <typename T = float>
T lcm(T a, T b);
template <typename T = double>
T lcm(T a, T b);

int main() {
  uint64_t a, b, c, d;
  std::cin >> a >> b >> c >> d;

  uint64_t cs = ((a % c) == 0) ? (a / c) : (a / c + 1);
  uint64_t ce = b / c;

  uint64_t ds = ((a % d) == 0) ? (a / d) : (a / d + 1);
  uint64_t de = b / d;

  uint64_t l = lcm(c, d);
  uint64_t ls = ((a % l) == 0) ? (a / l) : (a / l + 1);
  uint64_t le = b / l;

  std::cout << b - a + 1 - ((ce - cs + 1) + (de - ds + 1) - (le - ls + 1))
            << std::endl;
  return 0;
}

