#include <iostream>
int main(void) {
  std::string s;
  std::cin >> s;

  int64_t count = 0;
  int64_t chokuA = 0;

  if (s.length() <= 2) {
    std::cout << 0 << std::endl;
    return 0;
  }

  for (int i = 0, end = s.length() - 1; i < end; ++i) {
    if (s[i] == 'A') {
      ++chokuA;
    } else if ((s[i + 0] == 'B') && (s[i + 1] == 'C')) {
      count += chokuA;
      ++i;
    } else {
      chokuA = 0;
    }
  }

  std::cout << count << std::endl;
  return 0;
}
