#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> in(3);
  std::cin >> in[0] >> in[1] >> in[2];

  std::sort(in.begin(), in.end());

  std::cout << in[0] + in[1] << std::endl;

  return 0;
}

