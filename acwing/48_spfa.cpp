#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int e[N], ne[N], h[N], w[N], idx;
int dist[N];
bool st[N];  // 表示在队列中的点，已经在了就不再放入了

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;

  queue<int> q;
  q.push(1);
  st[1] = true;

  while (q.size()) {
    int t = q.front();
    q.pop();

    st[t] = false;

    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[t] + w[i]) {
        dist[j] = dist[t] + w[i];
        if (!st[j]) {
          q.push(j);
          st[j] = true;
        }
      }
    }
  }

  if (dist[n] == 0x3f3f3f3f)
    cout << "impossible" << endl;
  else
    cout << dist[n] << endl;
}

int main() {
  memset(h, -1, sizeof h);
  cin >> n >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }
  spfa();
}