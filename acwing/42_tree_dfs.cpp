#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = N * 2;

// 图的邻接表
int n;
int h[N], e[M], ne[M], idx;  // idx为边编号
int res = N;
bool st[N];

void add(int a, int b) {  // 在节点a和b中连条单向边，方向a->b
  e[idx] = b;             // idx 这条边的终点是b
  ne[idx] = h[a];         // 该边同起点的下一条边编号
  h[a] = idx++;           // 节点a的第一条边的编号
}

int dfs(int u) {
  st[u] = true;
  int son_max = 0, sum = 0;
  // size 最大子树
  // sum 子树节点总数
  for (int i = h[u]; i != -1; i = ne[i]) {
    int j = e[i];
    if (st[j]) continue;  //是否被剪短过
    int s = dfs(j);
    son_max = max(son_max, s);
    sum += s;
  }
  //找重心，分割子树，搜索所有的最大子树和剩余子树比较
  son_max = max(son_max, n - sum - 1);
  // 自身的最大子树， 和整体的除了自己最大子树的另一部分
  res = min(res, son_max);
  return sum + 1;
}

int main() {
  cin >> n;
  memset(h, -1, sizeof h);
  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    add(b, a);
  }
  dfs(1);
  cout << res << endl;
}