#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

const int N = 3010;
struct dan {
  long long t, p, w;
};

int main() {
  int n;
  cin >> n;
  vector<dan> a;
  a.reserve(n + 1);
  for (int i = 0; i < n; ++i) {
    long long t, p, w;
    cin >> t >> p >> w;
    a.push_back({t, p, w});
  }

  a.push_back({0, 0, 0});

  sort(a.begin(), a.end(), [](const dan &a, const dan &b) {
    if (a.t != b.t)
      return a.t < b.t;
    return a.p < b.p;
  });

  vector<long long> dp(n + 1, -1);
  long long res = 0;
  for (int i = 0; i < n + 1; ++i) {
    if (a[i].t == 0 && a[i].p == 0)
      dp[i] = 0;
    for (int j = 0; j < i; ++j) {
      if (abs(a[i].p - a[j].p) <= a[i].t - a[j].t) {
        dp[i] = max(dp[i], dp[j] + a[i].w);
      }
      res = max(res, dp[i]);
    }
  }

  cout << res << endl;
}