#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::map<std::string, std::map<int, int>> SP;

  for (int i = 0; i < N; ++i) {
    std::string s;
    int p;
    std::cin >> s >> p;
    auto find = SP.find(s);
    if (find != SP.end()) {
      find->second.insert(std::make_pair(p, i + 1));
    } else {
      std::map<int, int> pm;
      pm.insert(std::make_pair(p, i + 1));
      SP.insert(std::make_pair(s, pm));
    }
  }

  for (auto &sp : SP) {
    for (auto iter = sp.second.rbegin(); iter != sp.second.rend(); ++iter) {
      std::cout << iter->second << std::endl;
    }
  }

  return 0;
}
