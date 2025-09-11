#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int main() {
  int m;
  cin >> m;
  int stk[N], tt = 0;
  while (m--) {
    string op;
    int x;
    cin >> op;
    if (op == "push") {
      cin >> x;
      stk[++tt] = x;
    } else if (op == "pop") {
      --tt;
    } else if (op == "empty") {
      cout << (tt ? "NO" : "YES") << endl;
    } else {
      cout << stk[tt] << endl;
    }
  }
}