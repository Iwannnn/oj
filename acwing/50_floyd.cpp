#include <iostream>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, k;
int d[N][N];

void floyd() {
  for (int mid = 1; mid <= n; ++mid)  //确保中间节点已经被处理为最短了
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        d[i][j] = min(d[i][j], d[i][mid] + d[mid][j]);
}

int main() {
  cin >> n >> m >> k;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (i == j)
        d[i][j] = 0;
      else
        d[i][j] = INF;

  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    d[x][y] = min(d[x][y], z);
  }
  floyd();
  while (k--) {
    int x, y;
    cin >> x >> y;
    if (d[x][y] > INF / 2)
      cout << "impossible" << endl;
    else
      cout << d[x][y] << endl;
  }
}