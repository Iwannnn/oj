#include <string.h>

#include <iostream>

using namespace std;

const int N = 20, M = 1010;

int n, m;
char str[M][N];
int f[M][M];

int dist(char a[], char b[]) {
  int la = strlen(a + 1), lb = strlen(b + 1);
  for (int i = 0; i <= la; ++i) f[i][0] = i;
  for (int i = 0; i <= lb; ++i) f[0][i] = i;

  for (int i = 1; i <= la; ++i) {
    for (int j = 1; j <= lb; ++j) {
      f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
      if (a[i] == b[j])
        f[i][j] = min(f[i][j], f[i - 1][j - 1]);
      else
        f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
    }
  }
  return f[la][lb];
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> (str[i] + 1);
  while (m--) {
    char s[N];
    int l;
    cin >> (s + 1) >> l;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (dist(str[i], s) <= l) ++res;
    }
    cout << res << endl;
  }
}