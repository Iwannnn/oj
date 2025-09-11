#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;

int n, m;
int p[N];

struct edge {
  int a, b, w;
  bool operator<(const edge& W) { return w < W.w; }
} edges[M];

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int kruskal() {
  sort(edges, edges + m);
  int res = 0, cnt = 0;
  for (int i = 1; i <= n; ++i) p[i] = i;
  for (int i = 0; i < m; ++i) {
    int a = edges[i].a, b = edges[i].b, w = edges[i].w;
    a = find(a), b = find(b);
    if (a != b) {
      p[a] = b;
      res += w;
      ++cnt;
    }
  }
  if (cnt < n - 1)
    return INF;
  else
    return res;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[i] = {a, b, c};
  }
  int t = kruskal();
  if (t == INF)
    cout << "impossible" << endl;
  else
    cout << t << endl;
  return 0;
}