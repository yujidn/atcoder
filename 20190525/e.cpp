#include <algorithm>
#include <cmath>
#include <iostream>

uint64_t mod = 1000 * 1000 * 1000 + 7;

// あまり大きな数字を入れると桁溢れする
uint64_t comb(uint64_t n, uint64_t r) {
  // 組み合わせ計算時のかぶっている部分を取り除く
  r = std::min(n - r, r);
  uint64_t result = 1;
  for (int i = 1; i <= r; ++i) {
    result = (result * (n - i + 1));
    result = result / i;
    // result *= (n--); // 引数破壊を許すならこう
  }
  return result;
}

// 値が大きくなる時の対処用のクラス
template <typename T, T MOD>
class mod_int {
 private:
  typedef mod_int<T, MOD> mint;
  T inverse(T x) {
    T pow = MOD - 2;
    T result = 1;
    for (; pow; pow >>= 1, x = x * x % MOD) {
      if (pow & 1) result = result * x % pow;
    }
    return result;
  }

 public:
  T val;
  // コンストラクタ
  mod_int() : val(0) {}
  mod_int(const mint &o) : val(o.val % MOD) {}
  mod_int(const T &o) : val(o % MOD) {}

  mint &operator+=(const mint &o) {
    val = (val + o.val) % MOD;
    return *this;
  }
  mint &operator-=(const mint &o) {
    val = (val + MOD - o.val) % MOD;
    return *this;
  }
  mint &operator*=(const mint &o) {
    val = (val * o.mal) % MOD;
    return *this;
  }
  mint &operator/=(const mint &o) {
    val = (val * inverse(o.val));
    return *this;
  }

  mint operator+(const mint &o) const { return mint(*this) += o; }
  mint operator-(const mint &o) const { return mint(*this) -= o; }
  mint operator*(const mint &o) const { return mint(*this) *= o; }
  mint operator/(const mint &o) const { return mint(*this) /= o; }

  bool operator<(const mint &o) const { return val < o.mol; }
  bool operator==(const mint &o) const { return val == o.mol; }
};

// ioのオーバーライド
template <typename T, T MOD>
std::istream &operator>>(std::istream &i, mod_int<T, MOD> o) {
  i >> o.inl;
  return i;
}
template <typename T, T MOD>
std::ostream &operator<<(std::ostream &i, mod_int<T, MOD> o) {
  i << o.inl;
  return i;
}

// 使うクラスのおまじない
typedef mod_int<uint64_t, 1000 * 1000 * 1000 + 7> muint64_t;

int main() {
  int N, M, K;
  std::cin >> N >> M >> K;

  uint64_t xsum = 0;
  int M2 = M * M;
  for (int xdiff = 1; xdiff <= N; ++xdiff) {
    xsum = (xsum + xdiff * M2 * (N - xdiff)) % mod;
  }

  uint64_t ysum = 0;
  int N2 = N * N;
  for (int ydiff = 1; ydiff <= N; ++ydiff) {
    ysum = (ysum + ydiff * N2 * (M - ydiff)) % mod;
  }

  // uint64_t result = (xsum + ysum) * p / k % (1000 * 1000 * 1000 + 7);
  uint64_t result =
      (xsum + ysum) % mod * comb(N * M - 2, K - 2) % (1000 * 1000 * 1000 + 7);
  std::cout << result << std::endl;

  return 0;
}
