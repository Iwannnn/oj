#include <bits/stdc++.h>
#include <cstring>
#include <vector>

using namespace std;

const int N = 2e5 + 10;
int n, k;
int a[N];

bool check(int x) {
  int u = 0;
  for (int i = 0; i < n;) {
    if (a[i] == 0) {
      ++i;
      continue;
    }
    ++u;
    if (u > k)
      return false;
    else
      i += x;
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(a, 0, sizeof a);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    //使用k次完成 最小的x
    int l = 0, r = n, res = n;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        res = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    cout << res << endl;
  }
}