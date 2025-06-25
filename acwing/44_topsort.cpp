#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

// e idx这条边的目标点 ne表示这个边的下一条边 h表示这个点的头指针
int e[N], ne[N], h[N], idx;
int n, m;
int d[N];
int q[N];

void add(int a, int b) {
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
}

void top_sort() {
  int hh = 0, tt = -1;

  // 入读为0
  for (int i = 1; i <= n; ++i) {
    if (!d[i]) q[++tt] = i;
  }

  while (hh <= tt) {
    int t = q[hh++];
    //遍历 该节点出发的边
    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      --d[j];
      if (!d[j]) q[++tt] = j;
    }
  }

  if (tt == n - 1) {
    for (int i = 0; i < n; ++i) {
      cout << q[i] << " ";
    }
  } else {
    cout << -1;
  }
}

int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    ++d[b];
  }
  top_sort();
}