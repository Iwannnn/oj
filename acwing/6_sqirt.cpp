#include <iostream>

using namespace std;
int main() {
  double l = -10000, r = 10000;
  double n;
  cin >> n;
  while (r - l > 1e-8) {
    double mid = (r + l) / 2;
    if (mid * mid * mid >= n) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%lf\n", l);
  return 0;
}