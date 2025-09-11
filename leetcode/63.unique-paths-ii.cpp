/*
 * @lc app=leetcode.cn id=63 lang=cpp
 * @lcpr version=30204
 *
 * [63] 不同路径 II
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
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int dp[110] = {0};
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    dp[1] = obstacleGrid[0][0] ? 0 : 1;
    for (int j = 2; j <= n; ++j)
      dp[j] = obstacleGrid[0][j - 1] ? 0 : dp[j - 1];

    for (int i = 2; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[j] = obstacleGrid[i - 1][j - 1] ? 0 : dp[j] + dp[j - 1];
      }
    }

    return dp[n];
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

 */
