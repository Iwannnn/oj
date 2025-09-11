#include <bits/stdc++.h>

#include <ostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> cnt(n + 1, 0);
  for (auto val : a)
    if (val <= n) cnt[val]++;

  int k = 0;
  while (k <= n && cnt[k] > 0) ++k;

  vector<ll> b;
  b.reserve(n);
  for (int i = 0; i < k; ++i) {
    b.push_back(i);
    cnt[i]--;
  }

  for (int i = 0; i < n; ++i) {
    int val = a[i];
    if (val < k) {
      if (cnt[val] > 0) {
        b.push_back(val);
        cnt[val]--;
      }
    } else {
      b.push_back(val);
    }
  }

  ll res = 1LL * k * (k + 1) / 2 + 1LL * (n - k) * k;
  cout << res << endl;

  for (int i = 0; i < n; ++i) {
    cout << b[i];
    if (i < n - 1) cout << " ";
  }
  cout << endl;
}