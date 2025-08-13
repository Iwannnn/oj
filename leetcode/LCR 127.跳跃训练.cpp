/*
 * @lc app=leetcode.cn id=LCR 127 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 127] 跳跃训练
 *
 * https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/description/
 *
 * algorithms
 * Easy (45.12%)
 * Likes:    426
 * Dislikes: 0
 * Total Accepted:    415K
 * Total Submissions: 920.3K
 * Testcase Example:  '2'
 *
 * 今天的有氧运动训练内容是在一个长条形的平台上跳跃。平台有 num
 * 个小格子，每次可以选择跳 一个格子 或者
 * 两个格子。请返回在训练过程中，学员们共有多少种不同的跳跃方式。
 *
 * 结果可能过大，因此结果需要取模
 * 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出：2
 *
 *
 * 示例 2：
 *
 * 输入：n = 5
 * 输出：8
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= n <= 100
 *
 *
 * 注意：本题与主站 70 题相同：https://leetcode-cn.com/problems/climbing-stairs/
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
  int trainWays(int num) {
    vector<int> dp(110, 0);
    int mod = 1e9 + 7;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= num; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
      dp[i] %= mod;
    }
    return dp[num];
  }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */
