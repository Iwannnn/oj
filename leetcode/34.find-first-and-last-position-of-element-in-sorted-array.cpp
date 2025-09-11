/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30204
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
  int find_l(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (nums[mid] >= target) //从右往左逼近
        r = mid;
      else
        l = mid + 1;
    }
    return nums[r] == target ? r : -1;
  }

  int find_r(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (nums[mid] <= target) // 从左往右逼近
        l = mid;
      else
        r = mid - 1;
    }
    return nums[r] == target ? r : -1;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    if (!nums.size())
      return {-1, -1};
    int l = find_l(nums, target), r = find_r(nums, target);
    return {l, r};
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
