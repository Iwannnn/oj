#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, M = 10010;

struct Edge {
  int a, b, c;
} edges[M];

int n, m, k;
int dist[N];
int last[N];

void bellman_fold() {
  memset(dist, 0x3f, sizeof dist);

  dist[1] = 0;

  for (int i = 0; i < k; ++i) {
    // 更新最终结果
    memcpy(last, dist, sizeof dist);

    for (int j = 0; j < m; ++j) {  //如果遍历所有的边
      auto e = edges[j];
      dist[e.b] = min(dist[e.b], last[e.a] + e.c);
    }
  }
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[i] = {a, b, c};
  }

  bellman_fold();

  if (dist[n] > 0x3f3f3f3f / 2)
    cout << "impossible" << endl;
  else
    cout << dist[n] << endl;
  return 0;
}