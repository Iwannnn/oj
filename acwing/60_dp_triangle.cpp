#include <iostream>

using namespace std;

const int N = 510, INF = 1e9;

int n;
int t[N][N];
int f[N][N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j) cin >> t[i][j];

  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= i + 1; ++j) f[i][j] = -INF;  // 0 和 i+1对应两个边界

  f[1][1] = t[1][1];
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      f[i][j] = max(f[i - 1][j - 1] + t[i][j], f[i - 1][j] + t[i][j]);
    }
  }

  int res = -INF;
  for (int i = 1; i <= n; ++i) res = max(res, f[n][i]);
  cout << res << endl;
}