#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;
  int prev = (S[0] - 48) * 10 + (S[1] - 48);
  int next = (S[2] - 48) * 10 + (S[3] - 48);

  bool prev_flag = false;
  bool next_flag = false;

  if ((0 < prev) && (prev < 13)) {
    prev_flag = true;
  }
  if ((0 < next) && (next < 13)) {
    next_flag = true;
  }

  std::string result;

  if (prev_flag & next_flag) {
    result = "AMBIGUOUS";
  } else if (prev_flag) {
    result = "MMYY";
  } else if (next_flag) {
    result = "YYMM";
  } else {
    result = "NA";
  }

  std::cout << result << std::endl;
}

