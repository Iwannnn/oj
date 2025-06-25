#include <iostream>
#include <iterator>

using namespace std;

const int N = 20;

int n;
char res[N][N];
int col[N], diag[N], u_diag[N];

void dfs(int u) {  // u为行信息，以及使用的行数量
  if (u == n) {
    for (int i = 0; i < n; ++i) cout << res[i] << endl;
    cout << endl;
  }
  for (int i = 0; i < n; ++i) {  // i代表列 u代表行
    if (!col[i] && !diag[u + i] &&
        !u_diag[n - i + u]) {  //判断是否满足n皇后条件
      res[u][i] = 'Q';
      col[i] = diag[u + i] = u_diag[n - i + u] = 1;
      dfs(u + 1);
      col[i] = diag[u + i] = u_diag[n - i + u] = 0;
      res[u][i] = '.';
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) res[i][j] = '.';
  dfs(0);
  return 0;
}