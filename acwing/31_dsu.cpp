#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int p[N];

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) p[i] = i;
  while (m--) {
    char op;
    int a, b;
    cin >> op >> a >> b;
    if (op == 'M')
      p[find(b)] = find(a);
    else
      cout << (find(a) == find(b) ? "YES" : "NO") << endl;
  }
}