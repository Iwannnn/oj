#include <cstddef>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int e[N], ne[N], h[N], idx;
int d[N];
int n, m;

void add(int a, int b) {
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
}

int bfs() {
  memset(d, -1, sizeof d);

  queue<int> q;
  q.push(1);

  d[1] = 0;

  while (q.size()) {
    int t = q.front();
    q.pop();

    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if (d[j] == -1) {
        d[j] = d[t] + 1;
        q.push(j);
      }
    }
  }
  return d[n];
}

int main() {
  memset(h, -1, sizeof h);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    add(a, b);
  }
  cout << bfs() << endl;
}
