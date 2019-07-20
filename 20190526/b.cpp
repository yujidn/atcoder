#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::map<std::pair<std::string, int>, int> SP;

  for (int i = 0; i < N; ++i) {
    std::string s;
    int p;
    std::cin >> s >> p;
    SP.insert(std::make_pair(std::make_pair(s, -p), i + 1));
  }

  for (auto &s : SP) {
    std::cout << s.second << std::endl;
  }
  return 0;
}
