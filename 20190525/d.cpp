#include <algorithm>
#include <iostream>
#include <vector>

class ope {
 public:
  int B, C;
  ope(){};
  ope(int _B, int _C) : B(_B), C(_C){};

  bool operator<(const ope &other) const { return C < other.C; }
};

int main() {
  int N, M;
  std::cin >> N >> M;

  std::vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  std::sort(A.begin(), A.end());

  std::vector<ope> BC(M);
  for (int i = 0; i < M; ++i) {
    int B, C;
    std::cin >> B >> C;
    BC[i] = ope(B, C);
  }
  std::sort(BC.begin(), BC.end());

  int index = 0;
  for (int i = BC.size() - 1; i >= 0; --i) {
    auto &bc = BC[i];
    while (A[index] < bc.C) {
      A[index++] = bc.C;
      --bc.B;
      if (bc.B == 0) {
        break;
      }
    }
  }

  int64_t sum = 0;

  for (int i = 0; i < N; ++i) {
    sum += A[i];
  }

  int64_t result = sum;
  std::cout << result << std::endl;

  return 0;
}
