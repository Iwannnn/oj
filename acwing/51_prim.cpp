#include <cstring>
#include <iostream>

using namespace std;

const string NO = "impossible";
const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim() {  //全都视为离散的， dist存放 未被连接 到 已被连接的距离
  memset(dist, 0x3f, sizeof dist);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int t = -1;
    for (int j = 1; j <= n; ++j) {
      if (!st[j] && (t == -1 || dist[j] < dist[t])) {
        t = j;
      }
    }
    if (i && dist[t] == INF) return INF;
    if (i) res += dist[t];
    st[t] = true;
    for (int j = 1; j <= n; ++j) dist[j] = min(dist[j], g[t][j]);
  }
  return res;
}

int main() {
  cin >> n >> m;
  memset(g, 0x3f, sizeof g);
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a][b] = g[b][a] = min(g[a][b], c);
  }
  int res = prim();
  if (res == INF)
    cout << NO << endl;
  else
    cout << res << endl;
}