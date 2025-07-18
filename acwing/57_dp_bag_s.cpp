#include <iostream>

using namespace std;

const int N = 110;

int n, m;
int v[N], w[N], s[N];
int f[N][N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i] >> s[i];

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      f[i][j] = f[i - 1][j];
      for (int k = 1; k <= s[i]; ++k) {
        if (j >= k * v[i])
          f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
      }
    }
  }
  cout << f[n][m] << endl;
}