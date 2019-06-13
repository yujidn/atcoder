#include <algorithm>
#include <cmath>
#include <iostream>

//////////////////////////////////////////////////////
// 値が大きくなる時の対処用のクラス
// MODの値は適宜調整すること
//////////////////////////////////////////////////////
template <typename T, T MOD>
class mod_int {
 private:
  typedef mod_int<T, MOD> mint;
  constexpr T inverse(T x) {
    T pow = MOD - 2;
    T result = 1;
    while (pow) {
      if (pow & 1) result = result * x % MOD;
      pow >>= 1;
      x = x * x % MOD;
    }
    return result;
  }

 public:
  T val;
  // コンストラクタ
  constexpr mod_int() : val(0) {}
  constexpr mod_int(const mint &o) : val(o.val % MOD) {}
  constexpr mod_int(const T &o) : val(o % MOD) {}

  constexpr mint &operator+=(const mint &o) {
    val = (val + o.val) % MOD;
    return *this;
  }
  constexpr mint &operator-=(const mint &o) {
    val = (val + MOD - o.val) % MOD;
    return *this;
  }
  constexpr mint &operator*=(const mint &o) {
    val = (val * o.val) % MOD;
    return *this;
  }
  constexpr mint &operator/=(const mint &o) {
    val = (val * inverse(o.val)) % MOD;
    return *this;
  }

  constexpr mint &operator++() {
    val = (++val) % MOD;
    return *this;
  }

  constexpr mint &operator--() {
    val = (--val) % MOD;
    return *this;
  }

  constexpr mint operator+(const mint &o) const { return mint(*this) += o; }
  constexpr mint operator-(const mint &o) const { return mint(*this) -= o; }
  constexpr mint operator*(const mint &o) const { return mint(*this) *= o; }
  constexpr mint operator/(const mint &o) const { return mint(*this) /= o; }

  constexpr void operator=(const mint &o) { this->val = o.val; }
  constexpr void operator=(const int i) { this->val = i; }
  constexpr void operator=(const T i) { this->val = i; }

  constexpr bool operator<(const mint &o) const { return val < o.val; }
  constexpr bool operator<=(const mint &o) const { return val <= o.val; }
  constexpr bool operator==(const mint &o) const { return val == o.val; }
};
// ioのオーバーライド
template <typename T, T MOD>
std::istream &operator>>(std::istream &i, mod_int<T, MOD> &o) {
  i >> o.val;
  return i;
}
template <typename T, T MOD>
std::ostream &operator<<(std::ostream &i, const mod_int<T, MOD> &o) {
  i << o.val;
  return i;
}
// 使うクラスのおまじない
typedef mod_int<uint64_t, 1000 * 1000 * 1000 + 7> muint64_t;

template <uint N>
struct Step {
 public:
  muint64_t step[N];
  constexpr Step() : step() {
    step[0] = 1;
    step[1] = 2;
    for (int i = 2; i < N - 1; ++i) {
      step[i] = step[i - 2] + step[i - 1];
    }
  }
};

int main(void) {
  constexpr auto step = Step<10000>();

  int N, M;
  std::cin >> N >> M;
  int before = 0;
  muint64_t sum = 1;
  for (int i = 0; i <= M; ++i) {
    int temp;
    if (i != M) {
      std::cin >> temp;
    } else {
      temp = N + 1;
    }
    if (temp == before) {
      sum = 0;
      break;
    }
    auto s = temp - before - 2;
    if (s >= 0) {
      sum *= step.step[s];
    } else {
      sum *= muint64_t(1);
    }
    before = temp + 1;
  }
  std::cout << sum << std::endl;
  return 0;
}

