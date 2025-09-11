#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

struct Range {
  int l, r;

  bool operator<(const Range &w) const { return l < w.l; }
} range[N];

int main() {
  int st, ed;
  cin >> st >> ed;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> range[i].l >> range[i].r;

  sort(range, range + n);

  int res = 0;
  bool success = false;
  for (int i = 0; i < n; ++i) {
    int j = i, r = -2e9;

    while (j < n && range[j].l <= st) {  // 找到最靠近st的区间
      r = max(r, range[j].r);
      ++j;
    }
    if (r < st) {
      res = -1;
      break;
    }
    ++res;
    if (r >= ed) {
      success = true;
      break;
    }
    st = r;
    i = j - 1;
  }
  if (!success) res = -1;
  cout << res << endl;
}