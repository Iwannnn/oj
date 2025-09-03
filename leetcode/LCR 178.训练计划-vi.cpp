/*
 * @lc app=leetcode.cn id=LCR 178 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 178] 训练计划 VI
 *
 * https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/description/
 *
 * algorithms
 * Medium (80.59%)
 * Likes:    481
 * Dislikes: 0
 * Total Accepted:    182.4K
 * Total Submissions: 226.4K
 * Testcase Example:  '[5,7,5,5]'
 *
 * 教学过程中，教练示范一次，学员跟做三次。该过程被混乱剪辑后，记录于数组
 * actions，其中 actions[i] 表示做出该动作的人员编号。请返回教练的编号。
 *
 *
 *
 * 示例 1：
 *
 * 输入：actions = [5, 7, 5, 5]
 * 输出：7
 *
 *
 * 示例 2：
 *
 * 输入：actions = [12, 1, 6, 12, 6, 12, 6]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= actions.length <= 10000
 * 1 <= actions[i] < 2^31
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
  int trainingPlan(vector<int>& actions) {
    // int ones = 0, twos = 0;
    // for (int x : actions) {
    //   ones = (ones ^ x) & ~twos;
    //   twos = (twos ^ x) & ~ones;
    // }
    // return ones;  // 只出现一次的编号
    int res = 0;
    for (int b = 0; b < 32; ++b) {
      long long cnt = 0;
      for (auto x : actions) cnt += (x >> b) & 1;
      if (cnt % 3) res |= (1 << b);
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5, 7, 5, 5]\n
// @lcpr case=end

// @lcpr case=start
// [12, 1, 6, 12, 6, 12, 6]\n
// @lcpr case=end

 */
