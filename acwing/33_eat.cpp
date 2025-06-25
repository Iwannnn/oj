#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int p[N], d[N];

//并查集并不用作分类，而是用来记录已知信息的集合
int find(int x) {
  if (x != p[x]) {
    int t = find(p[x]);
    d[x] += d[p[x]];
    p[x] = t;
  }
  return p[x];
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
  }
  int res = 0;
  while (m--) {
    int op, x, y;
    cin >> op >> x >> y;
    if (x > n || y > n)
      ++res;
    else {
      int px = find(x), py = find(y);
      if (op == 1) {
        if (px == py && (d[x] - d[y]) % 3)
          ++res;
        else if (px != py) {
          p[px] = py;
          d[px] = d[y] - d[x];
        }
      } else {
        if (px == py && (d[x] - d[y] - 1) % 3)
          ++res;
        else if (px != py) {
          p[px] = py;
          d[px] = d[y] - d[x] + 1;
        }
      }
    }
  }
  cout << res;
}