#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int max_s = 10;
int res[max_s * max_s + 1];
double ax, ay, bx, by, cx, cy;

bool point_in_traingle(double px, double py) {
  auto cross = [](double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
  };
  double ab = cross(bx - ax, by - ay, px - ax, py - ay);
  double bc = cross(cx - bx, cy - by, px - bx, py - by);
  double ca = cross(ax - cx, ay - cy, px - cx, py - cy);
  return (ab >= 0 && bc >= 0 && ca >= 0) || (ab <= 0 && bc <= 0 && ca <= 0);
}

int main() {
  int n, m, s;
  cin >> n >> m >> s;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  double step = 1.0 / s;
  int minx = min({ax, bx, cx});
  int maxx = max({ax, bx, cx});
  int miny = min({ay, by, cy});
  int maxy = max({ay, by, cy});

  int start_i = max(0, minx);
  int end_i = min(n - 1, maxx);
  int start_j = max(0, miny);
  int end_j = min(m - 1, maxy);
  for (int i = start_i; i <= end_i; ++i) {
    for (int j = start_j; j <= end_j; ++j) {
      int coverd = 0;
      for (int p = 0; p < s; ++p) {
        for (int q = 0; q < s; ++q) {
          double x = i + (p + 0.5) * step;
          double y = j + (q + 0.5) * step;
          if (point_in_traingle(x, y)) coverd++;
        }
      }
      res[coverd]++;
    }
  }
  int total_p = n * m;
  int visit_p = 0;
  for (int i = 0; i <= s * s; ++i) visit_p += res[i];
  res[0] += (total_p - visit_p);
  for (int i = 0; i <= s * s; ++i) cout << res[i] << " ";
}