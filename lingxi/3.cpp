#include <bits/stdc++.h>

#include <vector>
using namespace std;

const int N = 100010;

int a[N];

int s(int l, int r) {
  if (l > r) return 0;
  int res = 0;
  int e_0 = l - 1;
  int e_1 = -1;
  int p = 0;

  for (int i = l; i <= r; ++i) {
    p ^= (a[i] & 1);
    if (p == 0) {
      res = max(res, i - e_0);
    } else {
      if (e_1 == -1)
        e_1 = i;
      else
        res = max(res, i - e_1);
    }
  }
  return res;
}

int main() {
  int n;
  int k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int res = 0;
  int seg_l = 1;
  for (int i = 2; i <= n; ++i) {
    if (abs(a[i] - a[i - 1]) > k) {
      res = max(res, s(seg_l, i - 1));
      seg_l = i;
    }
  }

  res = max(res, s(seg_l, n));
  cout << res << '\n';

  return 0;
}