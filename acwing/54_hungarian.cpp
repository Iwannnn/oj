#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, M = 1e5 + 10;

int e[M], ne[M], h[N], idx;
int n1, n2, m;
int match[N];
int st[N];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool find(int x) {
  for (int i = h[x]; i != -1; i = ne[i]) {
    int j = e[i];
    if (!st[j]) {
      st[j] = true;
      if (match[j] == 0 || find(match[j])) {  //可以找到下家
        match[j] = x;
        return true;
      }
    }
  }
  return false;
}

int main() {
  memset(h, -1, sizeof h);
  cin >> n1 >> n2 >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    add(a, b);
  }
  int res = 0;
  for (int i = 1; i <= n1; ++i) {
    memset(st, false, sizeof st);
    if (find(i)) ++res;
  }
  cout << res << endl;
}
