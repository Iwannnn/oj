#include <cstring>
#include <iostream>

using namespace std;

const int N = 12, M = 1 << N;

int n, m;
int f[N][M];  // 第i列 状态为j j使用二进制表示 覆盖为1未覆盖为0
bool st[M];

int main() {
  while (cin >> n >> m, n || m) {
    for (int i = 0; i < 1 << n; ++i) {
      // 出现的连续的0都必须是偶数个
      // st[i] false 代表不能按照这个二进制格式摆放
      int cnt = 0;
      st[i] = true;
      for (int j = 0; j < n; ++j) {
        if (i >> j & 1) {              //当前位是1
          if (cnt & 1) st[i] = false;  //奇数个
          cnt = 0;                     // 重置
        } else {
          ++cnt;
        }
      }
      if (cnt & 1) st[i] = false;
    }

    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j < i << n; ++j) {    // 当前列状态
        for (int k = 0; j < 1 << n; ++k) {  // 上一列状态
          if ((j & k) == 0 && st[j | k]) {
            // j&k==0两列间没有出现两列都是1的行
            // j|k 合并这一整列的格子
            f[i][j] += f[i - 1][k];
          }
        }
      }
    }
    cout << f[m][0] << endl;
  }
}