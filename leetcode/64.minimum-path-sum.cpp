/*
 * @lc app=leetcode.cn id=64 lang=cpp
 * @lcpr version=30204
 *
 * [64] 最小路径和
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
  int minPathSum(vector<vector<int>> &grid) {
    int dp[210] = {0};
    int m = grid.size(), n = grid[0].size();

    dp[1] = grid[0][0];
    for (int j = 2; j <= n; ++j)
      dp[j] = grid[0][j - 1] + dp[j - 1];

    for (int i = 2; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[j] = grid[i - 1][j - 1] + (j == 1 ? dp[j] : min(dp[j], dp[j - 1]));
      }
    }
    return dp[n];
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */
