#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

//////////////////////////////////////////////////////
// 組み合わせ計算
// あまり大きな数字を入れると桁溢れする
//////////////////////////////////////////////////////
template <typename T>
T comb(T n, T r) {
  // 組み合わせ計算時のかぶっている部分を取り除く
  r = std::min(n - r, r);
  T result = 1;
  T div = 1;
  for (T i = 1; i <= r; ++i) {
    result = (result * (n - i + 1));
    // result = result / i;
    div = div * i;
  }
  return result / div;
}

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

constexpr uint64_t MOD = 1000 * 1000 * 1000 + 7;

int main() {
  uint64_t N, K;
  std::cin >> N >> K;
  std::vector<int> An(N);
  for (auto &a : An) {
    std::cin >> a;
  }

  muint64_t count = 0;
  muint64_t hanten = 0;
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = i + 1; j < N; ++j) {
      if (An[i] > An[j]) ++count;
    }

    for (size_t j = 0; j < i; ++j) {
      if (An[i] > An[j]) ++hanten;
    }
  }

  muint64_t k = K;
  muint64_t temp = count * (k * (k + 1) / 2);
  muint64_t temp2 = hanten * ((k - 1) * k / 2);

  std::cout << temp + temp2 << std::endl;

  return 0;
}
