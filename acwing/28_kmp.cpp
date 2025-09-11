#include <iostream>

using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
int ne[N];
char p[N], s[M];
int main() {
  cin >> n >> (p + 1) >> m >> (s + 1);
  //失去匹配后的跳转下标 ， j为最长匹配长度
  for (int i = 2, j = 0; i <= n; ++i) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) ++j;
    ne[i] = j;
  }

  for (int i = 1, j = 0; i <= m; ++i) {
    while (j && s[i] != p[j + 1]) j = ne[j];  //不匹配的话该从那里重新匹配
    if (s[i] == p[j + 1]) ++j;                //匹配成功
    if (j == n) {
      cout << i - n << " ";
      j = ne[j];
    }
  }
  return 0;
}