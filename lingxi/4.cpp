#include <bits/stdc++.h>

#include <queue>
#include <vector>
using namespace std;

struct edge {
  int to;
  int h;
  int t;
};

int main() {
  const int INF_H = 1e9 + 10;
  const int INF_T = 1e5 + 10;

  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;

    vector<vector<edge>> g(n + 1);
    for (int i = 0; i < m; ++i) {
      int x, y, h, t;
      cin >> x >> y >> h >> t;
      int hh = h == -1 ? INF_H : h;
      g[x].push_back({y, hh, t});
      g[y].push_back({x, hh, t});
    }

    int s, t, h0;
    cin >> s >> t >> h0;

    vector<int> cap(n + 1, -1);
    priority_queue<pair<int, int>> pq;
    cap[s] = h0;
    pq.push({cap[s], s});
    while (!pq.empty()) {
      int c = pq.top().first;
      int u = pq.top().second;
    }
  }
}