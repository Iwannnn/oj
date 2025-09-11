#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
int skill[N], kill[N];
int valid[N];

int main() {
  int P;
  cin >> P;
  while (P--) {
    int t, c, n, m;
    cin >> t >> c >> n >> m;
    for (int i = 0; i < n; ++i) cin >> skill[i];
    for (int i = 0; i < m; ++i) cin >> kill[i];
    int res = 0, j = 0;
    int valid_cnt = 0;
    int last = -10000;

    // sort(kill, kill + m);

    for (int i = 0; i < n; ++i) {
      if (skill[i] > last + c) {
        valid[valid_cnt++] = skill[i];
        last = skill[i];
      }
    }

    for (int i = 0; i < valid_cnt; ++i) {
      int l = valid[i], r = valid[i] + t;
      int cnt = 0;
      for (int j = 0; j < m; ++j)
        if (kill[j] >= l && kill[j] < r) ++cnt;
      res = max(res, cnt);
    }
    cout << res << endl;
  }
  return 0;
}