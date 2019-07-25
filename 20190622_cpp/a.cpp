#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  for (size_t i = 1; i < s.length(); ++i) {
    if (s.c_str()[i - 0] == s.c_str()[i - 1]) {
      std::cout << "Bad" << std::endl;
      return 0;
    }
  }
  std::cout << "Good" << std::endl;
  return 0;
}

