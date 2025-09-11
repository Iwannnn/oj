#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
using ll = long long;
vector<ll> a(N);
vector<vector<int>> g(N);
vector<int> par(N, 0);
vector<vector<int>> ch(N);
vector<ll> we(N, 0);

void update_w(int n) {
  for (int u = 1; u <= n; ++u) {
    ll ww = a[u];
    for (auto v : ch[u]) max(ww, a[u] ^= a[v]);
    we[u] = ww;
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  queue<int> q;
  q.push(1);
  par[1] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (v != par[u]) {
        par[v] = u;
        ch[u].push_back(v);
      }
    }
  }

  update_w(n);

  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      ll d = a[x] ^ y;
      if (d == 0) continue;
      a[x] = y;
      we[x] ^= d;
    } else if (op == 2) {
      int x, y;
      cin >> x >> y;
      ll res = LLONG_MIN;
      for (int u = x; u <= y; ++u) {
        res = max(res, we[u]);
      }
      cout << res << endl;
    } else if (op == 3) {
      int x;
      cin >> x;
      ll res = LLONG_MIN;
      queue<int> q;
      q.push(x);
      while (!q.empty()) {
        int u = q.front();
        res = max(res, we[u]);
        q.pop();
        for (auto v : ch[u]) q.push(v);
      }
      cout << res << endl;
    }
  }
}
