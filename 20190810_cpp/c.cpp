#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

constexpr int prime[] = {2,  3,  5,  7,  11, 13,  17,  19, 23, 29,
                         31, 37, 41, 43, 47, 53,  59,  61, 67, 71,
                         73, 79, 83, 89, 97, 101, 103, 107};

constexpr size_t alphabet = 26;
constexpr size_t str_len = 10;

inline int64_t hash(std::string &str) {
  int64_t result = 1;

  for (size_t i = 0; i < str_len; ++i) {
    result *= prime[str[i] - 'a'];
  }

  return result;
}

inline int64_t hash(char *str, int start, int end) {
  int64_t result = 1;

  for (size_t i = start; i < end; ++i) {
    result *= prime[str[i] - 'a'];
  }

  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int64_t> sn(n);

  char input[100000 * 11 + 5];

  // 文字列の一括入力
  fread(input, sizeof(char), sizeof(char) * 11 * n, stdin);

  for (int i = 0; i < n; ++i) {
    // 一文字目に改行(Nの後の改行のこと)が存在するので+1する
    sn[i] = hash(input, i * 11 + 1, i * 11 + 10 + 1);
  }

  std::sort(sn.begin(), sn.end());

  int64_t count = 0;
  int64_t local_count = 0;
  for (int i = 1; i < n; ++i) {
    if (sn[i - 1] == sn[i]) {
      count += (++local_count);
    } else {
      local_count = 0;
    }
  }

  printf("%ld\n", count);

  return 0;
}

