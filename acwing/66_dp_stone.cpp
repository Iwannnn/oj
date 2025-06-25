#include <iostream>

using namespace std;

const int N = 310;

int n;
int a[N];
int s[N];     //前缀和
int f[N][N];  // 区间dp f[i][j] i..j的最小值

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }

  for (int len = 2; len <= n; ++len) {
    for (int i = 1; i + len - 1 <= n; ++i) {
      int l = i, r = i + len - 1;
      f[l][r] = 1e9;
      for (int k = i; k < r; ++k) {
        // f[l][k] 合并左边  f[k+1][r] 合并右边 把两部分合成 s[r] - r[l-1]
        f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
      }
    }
  }
  cout << f[1][n] << endl;
}
