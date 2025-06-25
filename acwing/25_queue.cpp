#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N], head = 0, tail = -1;

int main() {
  int m;
  cin >> m;
  while (m--) {
    string op;
    int x;
    cin >> op;
    if (op == "push") {
      cin >> x;
      q[++tail] = x;
    } else if (op == "pop")
      ++head;
    else if (op == "empty")
      cout << ((head <= tail) ? "NO" : "YES") << endl;
    else
      cout << q[head] << endl;
  }
  return 0;
}