#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int e[M], ne[M], h[N], idx;
int color[N];  // 0未染色 1 2 表示两种颜色
int n, m;

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool dfs(int u, int c) {  // 如果给u上色c能否满足二分图
  color[u] = c;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int j = e[i];
    if (!color[j]) {
      if (!dfs(j, 3 - c)) return false;
    } else if (color[j] == c)
      return false;
  }
  return true;
}

int main() {
  memset(h, -1, sizeof h);
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    add(b, a);
  }
  bool res = true;

  for (int i = 1; i <= n; ++i) {
    if (!color[i]) {
      if (!dfs(i, 1)) {
        res = false;
        break;
      }
    }
  }
  cout << (res ? "Yes" : "No") << endl;
}