#include <algorithm>
#include <iostream>

using namespace std;
const int N = 1e5 + 10, M = 31e5 + 10;

int a[N], edge[M][2], idx;

void insert(int x) {
  int p = 0;
  for (int i = 30; i >= 0; --i) {
    int b = x >> i & 1;
    if (!edge[p][b]) edge[p][b] = ++idx;
    p = edge[p][b];  //此处之前误用为了idx
  }
}
int judge(int x) {
  int p = 0, res = 0;
  for (int i = 30; i >= 0; --i) {
    int b = x >> i & 1;  // b是跟着x动的
    if (edge[p][!b]) {  //如果!b存在 那么异或的就大 贪心 后面的和也打不过高位
      res += 1 << i;
      p = edge[p][!b];
    } else {
      p = edge[p][b];
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    insert(a[i]);
  }
  int res = 0;
  for (int i = 0; i < n; ++i) res = max(res, judge(a[i]));
  cout << res << endl;
  return 0;
}