#include <iostream>
#include <string>

int main() {
  int N, K;
  std::string S;
  std::cin >> N >> K;
  std::cin >> S;

  S[K - 1] += 32;

  std::cout << S << std::endl;
}

