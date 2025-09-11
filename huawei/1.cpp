#include <bits/types/struct_sched_param.h>

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct bar {
  int x, y;
  int id;
};

struct bar_d {
  int distance;
  struct bar bar;
  bool operator<(const bar_d &o) const { return this->distance < o.distance; }
};

int dis(int x0, int y0, int x1, int y1) { return abs(x0 - x1) + abs(y0 - y1); }

int main() {
  int k, n;
  int idx = 1, k_i = 0;
  int x, y;
  vector<bar_d> d;
  cin >> k >> n;

  int car_x, car_y;
  cin >> car_x >> car_y;
  while (n--) {
    cin >> x >> y;
    bar b;
    b.id = idx++;
    b.x = x;
    b.y = y;
    bar_d bd;
    bd.bar = b;
    bd.distance = dis(car_x, car_y, x, y);
    d.push_back(bd);
  }
  if (k == 0 || k > n) {
    cout << "null" << endl;
    return 0;
  }
  sort(d.begin(), d.end());
  for (auto a : d) {
    cout << a.bar.id << " " << a.bar.x << " " << a.bar.y << " " << a.distance
         << endl;
    ++k_i;
    if (k_i == k) return 0;
  }
  return 0;
}
