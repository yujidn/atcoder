#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  size_t n;
  std::cin >> n;
  std::vector<std::pair<int, int>> task;
  for (size_t i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    task.push_back(std::make_pair(b, a));
  }

  std::sort(task.begin(), task.end());
  int now = INT32_MAX;
  for (auto itr = task.rbegin(), end = task.rend(); itr != end; ++itr) {
    if (itr->first < now) {
      now = itr->first;
    }

    now -= itr->second;
  }

  std::string result = "Yes";
  if (now < 0) {
    result = "No";
  }

  std::cout << result << std::endl;
  return 0;
}

