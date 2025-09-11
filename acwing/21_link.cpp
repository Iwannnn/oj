#include <iostream>
using namespace std;

const int N = 100010;

// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 存储当前已经用到了哪个点
int e[N], ne[N], idx = 1;

void add(int k, int x) {
  e[idx] = x;
  ne[idx] = ne[k];
  ne[k] = idx++;
}

void remove(int k) { ne[k] = ne[ne[k]]; }

int main() {
  int M;
  cin >> M;
  while (M--) {
    char op;
    int x, k;
    cin >> op;
    if (op == 'H') {
      cin >> x;
      add(0, x);
    }
    if (op == 'D') {
      cin >> k;
      remove(k);
    }
    if (op == 'I') {
      cin >> k >> x;
      add(k, x);
    }
  }
  for (int i = ne[0]; i; i = ne[i]) cout << e[i] << " ";
  cout << endl;
}