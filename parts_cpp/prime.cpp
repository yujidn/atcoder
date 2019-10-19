#include <cmath>
#include <iostream>
#include <random>

// val以下の素数の大体の数を数える
// 厳密値とこの計算の乖離は2倍未満に収まる
template <uint64_t val>
constexpr uint64_t fermat_prime_theorem() {
  if (val == 2) {
    return 1;
  }
  if (val == 3) {
    return 2;
  }

  uint64_t e = 3;  // ネイピア数は2.7ちょいなので3にする(雑すぎでは
  uint64_t epow = 1;
  uint64_t count = 0;
  while (epow <= val) {
    epow *= e;
    ++count;
  }
  return val * 2 / count;
}

constexpr inline uint64_t modpow(uint64_t base, uint64_t power, uint64_t mod) {
  uint64_t result = 1;
  uint64_t pow = power;
  while (pow) {
    if (pow & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    pow >>= 1;
  }
  return result;
}

const uint64_t pre_random[20] = {
    1107651670, 1993744833, 580366313,  1190034836, 1140887924,
    1688213797, 1009305110, 71459860,   2102382239, 887339588,
    1187725395, 1553792358, 1007267610, 308411261,  419144064,
    1880051678, 1351054181, 1032098849, 596060910,  1970462069};

constexpr bool miller_rabin(uint64_t val) {
  auto d = val - 1;
  while ((d & 0x01) == 0) d >>= 1;

  for (int i = 0; i < 20; ++i) {
    auto a = pre_random[i] % (val - 4) + 2;
    auto t = d;
    auto y = modpow(a, t, val);
    if (y == 1 || y == val - 1) return false;

    while (t != val - 1) {
      y = (y * y) % val;
      t << 1;
      if (y == 1) return true;
      if (y == val - 1) return false;
    }
  }
  return true;
}

constexpr inline bool judge_prime(uint64_t val) {
  if (val == 2) return true;
  if ((val & 0x01) == 0) return false;
  // if (!miller_rabin(val)) return false;

  for (int j = 3; j * j <= val; j += 2) {
    if (val % j == 0) {
      return false;
    }
  }
  return true;
}

constexpr inline bool judge_prime(uint64_t val, uint64_t *prime,
                                  uint64_t prime_num) {
  if (val == 2) return true;
  if ((val & 0x01) == 0) return false;
  // if (val > 10000) {
  // if (!miller_rabin(val)) return false;
  // }

  for (int i = 0; i < prime_num && prime[i] * prime[i] <= val; ++i) {
    if (val % prime[i] == 0) {
      return false;
    }
  }
  return true;
}

// コンパイル時素数列
template <uint64_t target_num, uint64_t max_prime_num>
struct IPrime {
  uint64_t prime[max_prime_num];
  uint64_t prime_num;
  constexpr IPrime() : prime(), prime_num() {
    prime[0] = 2;
    int counter = 1;

    for (uint64_t val = 3; val < target_num; val += 2) {
      if (judge_prime(val, prime, counter)) {
        prime[counter] = val;
        ++counter;
      }
    }
    prime_num = counter;
  }
};

template <uint64_t target_num>
using Prime = IPrime<target_num, fermat_prime_theorem<target_num>()>;

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

int main() {
  uint64_t A, B;
  std::cin >> A >> B;
  auto tar = gcd(A, B);

  int p = 0;
  for (int i = 0; i < prime_num && prime[i] * prime[i] <= val; ++i) {
    int64_t num = 0;

    return 0;
  }

