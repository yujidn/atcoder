#include <iostream>

int main() {
  int N, A, B, C, D;
  std::cin >> N >> A >> B >> C >> D;

  --A;
  --B;
  --C;
  --D;

  std::string S;
  std::cin >> S;

  int oikosi;
  int owari;
  if (C > D) {
    // 岩チェック
    for (int i = A; i < C; ++i) {
      if ((S[i] == '#') && (S[i + 1] == '#')) {
        std::cout << "No" << std::endl;
        return 0;
      }
    }
    // 追い越しチェック
    for (int i = B; i <= D; ++i) {
      if (S.substr(i - 1, 3) == "...") {
        std::cout << "Yes" << std::endl;
        return 0;
      }
    }
    // 無理なら無理
    std::cout << "No" << std::endl;
    return 0;
  } else {
    // 岩チェック
    for (int i = A; i < D; ++i) {
      if ((S[i] == '#') && (S[i + 1] == '#')) {
        std::cout << "No" << std::endl;
        return 0;
      }
    }
    // 問題なし
    std::cout << "Yes" << std::endl;
    return 0;
  }

  return 0;
}
