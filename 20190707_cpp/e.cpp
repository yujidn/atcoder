#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

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

muint64_t dfs(const int K, const std::vector<std::vector<int>> &graph,
              const int now, const int parent = -1) {
  muint64_t k = K - 2;
  if (parent == -1) {
    k = K - 1;
  }
  const auto &gg = graph[now];
  if (K < gg.size()) {
    return muint64_t(0);
  }

  muint64_t sum = 1;
  for (auto g : gg) {
    if (g == parent) continue;

    sum *= k;
    --k;
    sum *= dfs(K, graph, g, now);
  }
  return sum;
}

muint64_t dfs(const int K, const std::vector<std::vector<int>> &graph) {
  std::queue<std::pair<int, std::vector<int>>> queue;
  std::vector<int> first;
  first.push_back(0);
  queue.push(std::make_pair(-1, first));

  muint64_t sum = 1;
  const muint64_t _k = K - 2;

  while (queue.size() > 0) {
    const auto &que = queue.front();
    auto parent = que.first;
    auto &sune_list = que.second;

    for (auto now : sune_list) {
      muint64_t k = _k;
      if (parent == -1) {
        k = K - 1;
      }
      const auto &gg = graph[now];
      if (K < gg.size()) {
        return muint64_t(0);
      }

      std::vector<int> next;
      for (auto g : gg) {
        if (g == parent) continue;

        sum *= k;
        --k;
        next.push_back(g);
      }
      queue.push(std::make_pair(now, next));
    }
    queue.pop();
  }
  return sum;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> graph(n);

  for (size_t i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a;
    --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  // std::cout << muint64_t(k) * dfs(k, graph, 0) << std::endl;
  std::cout << muint64_t(k) * dfs(k, graph) << std::endl;

  return 0;
}

