#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int64_t> an(n);

  for (auto& a : an) {
    std::cin >> a;
  }

  std::vector<int64_t> seq;

  for (auto iter = an.rbegin(); iter != an.rend(); ++iter) {
    auto found = std::upper_bound(seq.begin(), seq.end(), *iter);
    if (found == seq.end()) {
      seq.push_back(*iter);
    } else {
      *found = *iter;
    }
  }

  std::cout << seq.size() << std::endl;
  return 0;
}
