/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30204
 *
 * [51] N 皇后
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> col(20, 0), diag(20, 0), u_diag(20, 0);
    vector<string> cur;
    string t = "";
    for (int i = 0; i < n; ++i)
      t.push_back('.');
    for (int i = 0; i < n; ++i) {
      cur.push_back(t);
    }
    dfs(res, cur, n, 0, col, diag, u_diag);
    return res;
  }

  void dfs(vector<vector<string>> &res, vector<string> &cur, int n, int u,
           vector<int> &col, vector<int> &diag, vector<int> &u_diag) {
    if (u == n) {
      res.push_back(cur);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (!col[i] && !diag[i + u] && !u_diag[n - i + u]) {
        col[i] = diag[i + u] = u_diag[n - i + u] = 1;
        cur[u][i] = 'Q';
        dfs(res, cur, n, u + 1, col, diag, u_diag);
        cur[u][i] = '.';
        col[i] = diag[i + u] = u_diag[n - i + u] = 0;
      }
    }
  }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
