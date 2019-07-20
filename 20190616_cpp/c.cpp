#include <float.h>
#include <cmath>
#include <iostream>

template <typename T1, typename T2>
bool dnear(T1 a, T2 b) {
  auto abs = std::abs(a - b);
  if (abs < DBL_EPSILON) {
    return true;
  } else {
    return false;
  }
}

int main(void) {
  int iW, iH, ix, iy;
  double W, H, x, y;

  std::cin >> iW >> iH >> ix >> iy;
  W = iW;
  H = iH;
  x = ix;
  y = iy;

  if (dnear(W / 2, x) || dnear(H / 2, y) || (ix == 0) || (iy == 0)) {
    double xarea = std::min(x, W - x) * H;
    double yarea = std::min(y, H - y) * W;

    if (xarea < yarea) {
      std::cout << yarea << " " << 0 << std::endl;
    } else if (yarea < xarea) {
      std::cout << xarea << " " << 0 << std::endl;
    } else {
      std::cout << xarea << " " << 1 << std::endl;
    }
  } else {
    auto tx = std::min(x, W - x);
    auto ty = std::min(y, H - y);
    auto sqrt = std::sqrt(tx * tx + ty * ty);

    auto area = (tx * sqrt / ty + ty * sqrt / tx) * sqrt / 2;
    area = W * H - area;
    printf("%.9f 0\n", area);
  }
  return 0;
}

