#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main() {
  cin >> n >> (a + 1);
  cin >> m >> (b + 1);

  for (int i = 0; i <= n; ++i) f[i][0] = i;  //变为空串几步
  for (int i = 0; i <= m; ++i) f[0][i] = i;  // 空串变为几步

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      //先得到 如果要做删除和插入 操作数的较小值
      f[i][j] = min(f[i - 1][j] + 1,   // 删除a[i] a[i-1]->b[j]操作数+1
                    f[i][j - 1] + 1);  //  插入b[j] a[i]->b[j-1]操作数+1
      if (a[i] == b[j])                // 相同
        f[i][j] = min(f[i][j], f[i - 1][j - 1]);  //
      else  // 不同 比价 删除 插入 和 替换 a[i]替换为b[j]
        f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
    }
  }
  cout << f[n][m] << endl;
}