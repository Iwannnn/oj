/*
 * @lc app=leetcode.cn id=LCR 166 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 166] 珠宝的最高价值
 *
 * https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/description/
 *
 * algorithms
 * Medium (69.36%)
 * Likes:    555
 * Dislikes: 0
 * Total Accepted:    305.3K
 * Total Submissions: 440.1K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 现有一个记作二维矩阵 frame 的珠宝架，其中 frame[i][j]
 * 为该位置珠宝的价值。拿取珠宝的规则为：
 *
 *
 * 只能从架子的左上角开始拿珠宝
 * 每次可以移动到右侧或下侧的相邻位置
 * 到达珠宝架子的右下角时，停止拿取
 *
 *
 * 注意：珠宝的价值都是大于 0 的。除非这个架子上没有任何珠宝，比如 frame =
 * [[0]]。
 *
 *
 *
 * 示例 1：
 *
 * 输入：frame = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出：12
 * 解释：路径 1→3→5→2→1 可以拿到最高价值的珠宝
 *
 *
 *
 * 提示：
 *
 *
 * 0 < frame.length <= 200
 * 0 < frame[0].length <= 200
 *
 *
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
  int jewelleryValue(vector<vector<int>>& frame) {
    if (frame.size() == 0 || frame[0].size() == 0) return 0;
    int n = frame.size(), m = frame[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = frame[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    return dp[n][m];
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

 */
