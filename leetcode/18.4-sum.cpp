/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30204
 *
 * [18] 四数之和
 *
 * https://leetcode.cn/problems/4sum/description/
 *
 * algorithms
 * Medium (36.75%)
 * Likes:    2048
 * Dislikes: 0
 * Total Accepted:    690.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target
 * 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c],
 * nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 *
 *
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *
 * 你可以按 任意顺序 返回答案 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
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
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() <= 3) return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      long long int three_target = target - nums[i];
      for (int j = i + 1; j < nums.size() - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        long long int two_target = three_target - nums[j];
        long long int k = j + 1, l = nums.size() - 1;
        while (k < l) {
          if (nums[k] + nums[l] == two_target) {
            res.push_back({nums[i], nums[j], nums[k], nums[l]});
            while (k < l && nums[k + 1] == nums[k]) ++k;
            while (k < l && nums[l - 1] == nums[l]) --l;
            ++k;
            --l;
          } else if (nums[k] + nums[l] < two_target)
            ++k;
          else
            --l;
        }
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */
