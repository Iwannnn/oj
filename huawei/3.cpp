#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp_from(int) int main() {
  int n;
  cin >> n;
  int grid[n][n], dp[n][n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }
  }
  // int res = 99999;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     if (grid[i][j] == 0) continue;
  //     int dx[4] = {-1, 1, 0, 0};
  //     int dy[4] = {0, 0, 1, -1};
  //     for (int k = 0; k < 4; ++k) {
  //       int ni = i + dx[k], nj = j + dy[k];
  //       if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] != 0)
  //         continue;
  //       if (dpA[i][j] < 9999999 && dpB[i][j] < 9999999) {
  //         res = min(res, max(dpA[i][j], dpB[ni][nj]));
  //       }
  //     }
  //   }
  // }
  // cout << res;
  return 0;
}