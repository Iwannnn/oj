#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N], d[N][N];

void bfs() {
  queue<PII> q;
  memset(d, -1, sizeof d);
  d[0][0] = 0;
  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
  q.push({0, 0});
  while (q.size()) {
    auto t = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int x = t.first + dx[i], y = t.second + dy[i];
      if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 &&
          d[x][y] == -1) {  //最短路径，一层一层下来的所以是最短的
        d[x][y] = d[t.first][t.second] + 1;
        q.push({x, y});
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> g[i][j];

  bfs();
  cout << d[n - 1][m - 1] << endl;
  return 0;
}