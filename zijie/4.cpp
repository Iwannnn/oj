#include <bits/stdc++.h>

using namespace std;

const int MOD = 10e9 + 7;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    while (q--) {
      int x;
      cin >> x;
      long long res = 1;
      for (int i = 0; i < n; ++i) {
        long long div = a[i] / x + 1;
        res = (res * (div % MOD)) % MOD;
      }
      cout << res;
      if (q == 0)
        cout << endl;
      else
        cout << " ";
    }
  }
}