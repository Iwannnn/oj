#include <iostream>
using namespace std;

const int N = 100010;

int e[N], ne[N], pe[N], idx;

void add(int k, int x) {
  e[idx] = x;
  ne[idx] = ne[k];
  ne[k] = idx;
  pe[idx] = k;
  pe[ne[idx]] = idx;
  ++idx;
}

void del(int k) {
  ne[pe[k]] = ne[k];
  pe[ne[k]] = pe[k];
}

int main() {
  int m;
  cin >> m;
  ne[0] = 1;
  pe[1] = 0;
  idx = 2;
  while (m--) {
    string op;
    int k, x;
    cin >> op;
    if (op == "L") {
      cin >> x;
      add(0, x);
    } else if (op == "R") {
      cin >> x;
      add(pe[1], x);
    } else if (op == "D") {
      cin >> k;
      del(k + 1);
    } else if (op == "IL") {
      cin >> k >> x;
      add(pe[k + 1], x);
    } else {
      cin >> k >> x;
      add(k + 1, x);
    }
  }
  for (int i = ne[0]; i != 1; i = ne[i]) cout << e[i] << " ";
  cout << endl;
}