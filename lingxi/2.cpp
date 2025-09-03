#include <bits/stdc++.h>

#include <csetjmp>
#include <cstring>
using namespace std;

const int N = 1010;

int a[N];
int pre[N];
int dp[N][N];

int sum(int l, int r) {
  if (l > r) return 0;
  return pre[r] - pre[l - 1];
}

int solve(int l, int r) {
  if (l >= r) return 0;

  int &res = dp[l][r];
  if (res != -1) return res;

  res = 0;
  for (int k = l; k <= r; ++k) {
    if (sum(l, k - 1) == sum(k + 1, r)) {
      res = max(res, 1 + solve(l, k - 1) + solve(k + 1, r));
    }
  }

  return res;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  pre[0] = 0;
  for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];

  memset(dp, -1, sizeof(dp));
  cout << solve(1, n) << "\n";

  return 0;
}