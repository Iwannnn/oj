#include <cstring>
#include <iostream>

using namespace std;

const int N = 20, M = 1 << N;

int n;
int w[N][N];
int f[M][N];  // f[i][j] i代表访问过的城市 j代表最后一个城市 f代表开销

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> w[i][j];

  memset(f, 0x3f, sizeof f);
  f[1][0] = 0;

  for (int i = 0; i < 1 << n; ++i) {   // 遍历城市访问状态
    for (int j = 0; j < n; ++j) {      // 遍历到达城市
      if (i >> j & 1) {                // 在状态中
        for (int k = 0; k < n; ++k) {  // 遍历出发去到达的城市的城市
          if (i >> k & 1) {            // 在状态中
            f[i][j] = min(f[i][j],
                          f[i - (1 << j)][k] +
                              w[k][j]);  // 1-（1<<j) 保证访问的城市不是重复经过
                                         // 而是这次的路线的经过
          }
        }
      }
    }
  }

  cout << f[(1 << n) - 1][n - 1];
}