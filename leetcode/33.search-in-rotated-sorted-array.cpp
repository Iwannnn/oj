/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30204
 *
 * [33] 搜索旋转排序数组
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <ios>
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
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[mid] < nums[r]) {
        // 右半边有序
        if (nums[mid] < target &&
            nums[r] >= target) //如果在右边 mid < target < r
          l = mid + 1;
        else
          r = mid - 1;
      } else {
        // 左半边有序
        if (nums[mid] > target &&
            nums[l] <= target) // 如果在左边 l < target < mid
          r = mid - 1;
        else
          l = mid + 1;
      }
    }
    return -1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
