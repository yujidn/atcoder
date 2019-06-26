// 最大公約数
template <typename T>
T gcd(T a, T b) {
  if (b > a) {
    T tmp = a;
    a = b;
    b = tmp;
  }
  // 避け
  if (b <= 0) {
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
