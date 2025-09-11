/*
 * @lc app=leetcode.cn id=LCR 139 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 139] 训练计划 I
 *
 * https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/description/
 *
 * algorithms
 * Easy (65.09%)
 * Likes:    339
 * Dislikes: 0
 * Total Accepted:    418.6K
 * Total Submissions: 643.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 教练使用整数数组 actions
 * 记录一系列核心肌群训练项目编号。为增强训练趣味性，需要将所有奇数编号训练项目调整至偶数编号训练项目之前。请将调整后的训练项目编号以
 * 数组 形式返回。
 *
 *
 *
 * 示例 1：
 *
 * 输入：actions = [1,2,3,4,5]
 * 输出：[1,3,5,2,4]
 * 解释：为正确答案之一
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= actions.length <= 50000
 * 0 <= actions[i] <= 10000
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
  vector<int> trainingPlan(vector<int>& actions) {
    vector<int> res;
    for (auto a : actions)
      if (a % 2 == 1) res.push_back(a);
    for (auto a : actions)
      if (a % 2 == 0) res.push_back(a);
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */
