/*
 * @lc app=leetcode.cn id=52 lang=cpp
 * @lcpr version=30204
 *
 * [52] N 皇后 II
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
  int totalNQueens(int n) {
    int res = 0;
    vector<int> col(20, 0), diag(20, 0), u_diag(20, 0);
    dfs(res, n, 0, col, diag, u_diag);
    return res;
  }

  void dfs(int &res, int n, int u, vector<int> &col, vector<int> &diag,
           vector<int> &u_diag) {
    if (n == u) {
      ++res;
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (!col[i] && !diag[i + u] && !u_diag[n - i + u]) {
        col[i] = diag[i + u] = u_diag[n - i + u] = 1;
        dfs(res, n, u + 1, col, diag, u_diag);
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
