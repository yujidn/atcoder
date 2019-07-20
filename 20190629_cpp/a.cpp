#include <iostream>

int main() {
  std::string s;
  std::cin >> s;
  int lec[256] = {0};

  for (int i = 0; i < s.length(); ++i) {
    ++lec[s.c_str()[i]];
  }

  for (int i = 0; i < 256; ++i) {
    if ((lec[i] != 0) && lec[i] != 2) {
      std::cout << "No" << std::endl;
      return 0;
    }
  }

  std::cout << "Yes" << std::endl;
  return 0;
}
