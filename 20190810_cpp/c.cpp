#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

constexpr int prime[] = {2,  3,  5,  7,  11, 13,  17,  19, 23, 29,
                         31, 37, 41, 43, 47, 53,  59,  61, 67, 71,
                         73, 79, 83, 89, 97, 101, 103, 107};
constexpr size_t alphabet = 26;
constexpr size_t str_len = 10;

int64_t hash(std::string &str) {
  char count[alphabet] = {0};

  int64_t result = 1;

  for (size_t i = 0; i < str_len; ++i) {
    result *= prime[str[i] - 'a'];
  }

  return result;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;

  std::unordered_map<int64_t, int64_t> map;
  int64_t count = 0;

  for (size_t i = 0; i < n; ++i) {
    std::string str;
    std::cin >> str;
    int key = hash(str);
    if (map.count(key) == 0) {
      map[key] = 0;
    } else {
      count += (++map[key]);
    }
  }

  std::cout << count << "\n";

  return 0;
}

