/*
 * @lc app=leetcode.cn id=LCR 172 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 172] 统计目标成绩的出现次数
 *
 * https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/description/
 *
 * algorithms
 * Easy (52.67%)
 * Likes:    462
 * Dislikes: 0
 * Total Accepted:    420.6K
 * Total Submissions: 798.4K
 * Testcase Example:  '[2,2,3,4,4,4,5,6,6,8]\n4'
 *
 * 某班级考试成绩按非严格递增顺序记录于整数数组 scores，请返回目标成绩 target
 * 的出现次数。
 *
 *
 *
 * 示例 1：
 *
 * 输入: scores = [2, 2, 3, 4, 4, 4, 5, 6, 6, 8], target = 4
 * 输出: 3
 *
 * 示例 2：
 *
 * 输入: scores = [1, 2, 3, 5, 7, 9], target = 6
 * 输出: 0
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= scores.length <= 10^5
 * -10^9 <= scores[i] <= 10^9
 * scores 是一个非递减数组
 * -10^9 <= target <= 10^9
 *
 *
 *
 *
 * 注意：本题与主站 34
 * 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
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
  int countTarget(vector<int>& scores, int target) {
    if (!scores.size()) return 0;
    int l = find_l(scores, target), r = find_r(scores, target);
    if (l == -1) return 0;
    return r - l + 1;
  }
  int find_l(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (nums[mid] >= target)
        r = mid;
      else
        l = mid + 1;
    }
    return nums[r] == target ? r : -1;
  }
  int find_r(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (nums[mid] <= target)
        l = mid;
      else
        r = mid - 1;
    }
    return nums[r] == target ? r : -1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2, 2, 3, 4, 4, 4, 5, 6, 6, 8]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3, 5, 7, 9]\n6\n
// @lcpr case=end

 */
