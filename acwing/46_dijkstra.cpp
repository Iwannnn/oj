#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e6 + 10;

typedef pair<int, int> PII;

int n, m;
int e[N], w[N], ne[N], h[N], idx;
int dist[N];
int st[N];

void add(int a, int b, int c) {
  e[idx] = b;
  w[idx] = c;
  ne[idx] = h[a];
  h[a] = idx++;
}

// 迪杰斯特拉算法的思路 贪心 找到一个当前可以到达的最短的路径的点
// 再根据这个点更新 数据量小双重循环 数据量大优先队列

int dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  // 此处第一个存放distance构成小顶堆能够，从而实现最短，在某一轮队列存在两个同样的点，选择更近的
  priority_queue<PII, vector<PII>, greater<PII>> heap;
  heap.push({0, 1});  //第一个为带着个位置的距离， 第二个为哪个位置
  while (heap.size()) {
    auto t = heap.top();
    heap.pop();
    int distance = t.first, ver = t.second;
    if (st[ver]) continue;
    st[ver] = true;
    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[ver] + w[i]) {
        dist[j] = dist[ver] + w[i];
        heap.push({dist[j], j});
      }
    }
  }
  if (dist[n] == 0x3f3f3f3f)
    return -1;
  else
    return dist[n];
}

int main() {
  memset(h, -1, sizeof h);

  cin >> n >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }
  cout << dijkstra() << endl;
}