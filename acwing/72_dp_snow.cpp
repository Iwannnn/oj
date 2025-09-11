#include <cstring>
#include <iostream>

using namespace std;

const int N = 310;

int r, c;
int w[N][N];
int f[N][N];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int x, int y) {
  if (f[x][y] != -1) return f[x][y];
  f[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int a = x + dx[i], b = y + dy[i];
    if (w[x][y] > w[a][b] && a >= 1 && a <= r && b >= 1 && b <= c) {
      f[x][y] = max(f[x][y], dp(a, b) + 1);
    }
  }
  return f[x][y];
}

int main() {
  cin >> r >> c;
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      cin >> w[i][j];
    }
  }

  memset(f, -1, sizeof f);
  int res = 0;

  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      res = max(res, dp(i, j));
    }
  }

  cout << res << endl;
}
