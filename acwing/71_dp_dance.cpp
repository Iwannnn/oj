#include <cstring>
#include <iostream>

using namespace std;

const int N = 6010;

int n;
int h[N], e[N], ne[N], idx;
int happy[N];
int f[N][2];  // 0表示当前节点不参加 1表示当前节点参加
bool has_fa[N];

void add(int a, int b) {
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx;
  idx++;
}

void dfs(int u) {
  f[u][1] = happy[u];
  for (int i = h[u]; i != -1; i = ne[i]) {
    int j = e[i];
    dfs(j);

    f[u][1] = max(f[u][1], f[u][1] + f[j][0]);
    f[u][0] = max(f[u][0], f[u][0] + max(f[j][1], f[j][0]));
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> happy[i];

  memset(h, -1, sizeof h);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    add(b, a);
    has_fa[a] = true;
  }

  int root = 1;
  while (has_fa[root]) ++root;

  dfs(root);

  cout << max(f[root][0], f[root][1]) << endl;
}