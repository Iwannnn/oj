#include <iostream>

using namespace std;

const int N = 1010, M = 1e9 + 7;

int n;
int f[N][N];  // f[i][j] 前i个数凑出j的方案数量
int ff[N];

int main() {
  cin >> n;
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      // 不使用i 至少使用1个i 所以只要前i个组成(j-i)的值
      f[i][j] = f[i - 1][j];
      if (j >= i) f[i][j] = (f[i - 1][j] + f[i][j - i]) % M;
    }
  }
  cout << f[n][n] << endl;

  ff[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      ff[j] = (ff[j] + ff[j - i]) % M;
    }
  }
  cout << ff[n] << endl;
}