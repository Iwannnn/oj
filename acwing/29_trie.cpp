#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int edge[N][26], cnt[N], idx;

void insert(string str) {
  int p = 0;
  for (int i = 0; i < str.size(); ++i) {
    int u = str[i] - 'a';
    if (!edge[p][u]) edge[p][u] = ++idx;
    p = edge[p][u];
  }
  cnt[p]++;
}

int query(string str) {
  int p = 0;
  for (int i = 0; i < str.size(); ++i) {
    int u = str[i] - 'a';
    if (!edge[p][u]) return 0;
    p = edge[p][u];
  }
  return cnt[p];
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    char op;
    string str;
    cin >> op >> str;
    if (op == 'I')
      insert(str);
    else
      cout << query(str) << endl;
  }
}