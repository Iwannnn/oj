#include <iostream>

using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N];
int f[N][N];  // 前i个物品 背包容积为j下 价值最大
int dp[N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i] >> w[i];
  }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     if (j >= v[i]) f[i][j] = f[i - 1][j - v[i]] + w[i];
  //     f[i][j] = max(f[i - 1][j], f[i][j]);
  //   }
  // }
  // cout << f[n][m] << endl;

  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= v[i]; --j) {
      dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    }
  }
  cout << dp[m] << endl;
}