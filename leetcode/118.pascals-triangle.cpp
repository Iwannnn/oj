/*
 * @lc app=leetcode.cn id=118 lang=cpp
 * @lcpr version=30204
 *
 * [118] 杨辉三角
 *
 * https://leetcode.cn/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (77.65%)
 * Likes:    1279
 * Dislikes: 0
 * Total Accepted:    709.1K
 * Total Submissions: 910.4K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *
 *
 * 示例 2:
 *
 * 输入: numRows = 1
 * 输出: [[1]]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= numRows <= 30
 *
 *
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
#include <queue>
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
  vector<vector<int>> generate(int numRows) {
    if (!numRows) return {};
    vector<vector<int>> dp(numRows, vector<int>{});
    dp[0].push_back({1});
    for (int i = 2; i <= numRows; ++i) {
      for (int j = 0; j < i; ++j) {
        if (j == 0 || j == i - 1) {
          dp[i - 1].push_back(1);
          continue;
        }
        dp[i - 1].push_back(dp[i - 2][j - 1] + dp[i - 2][j]);
      }
    }
    return dp;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
