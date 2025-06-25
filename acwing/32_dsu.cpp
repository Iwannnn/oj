#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int p[N], cnt[N];

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
    cnt[i] = 1;
  }
  while (m--) {
    string op;
    int a, b;
    cin >> op;
    if (op == "Q1") {
      cin >> a >> b;
      cout << (find(a) == find(b) ? "Yes" : "No") << endl;
    } else if (op == "Q2") {
      cin >> a;
      cout << cnt[find(a)] << endl;
    } else if (op == "C") {
      cin >> a >> b;
      a = find(a);
      b = find(b);
      if (a != b) {
        p[a] = b;
        cnt[b] += cnt[a];
      }
    }
  }
  return 0;
}