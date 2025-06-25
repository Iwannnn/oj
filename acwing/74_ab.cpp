#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

struct Range {
  int l, r;
  bool operator<(const Range &w) const { return r < w.r; }
} range[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> range[i].l >> range[i].r;
  }

  sort(range, range + n);
  int res = 0, ed = -1e9 - 10;
  for (int i = 0; i < n; ++i) {
    if (range[i].l > ed) {
      ed = range[i].r;
      res++;
    }
  }
  cout << res << endl;
}
