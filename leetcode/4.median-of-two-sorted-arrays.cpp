/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30204
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (43.08%)
 * Likes:    7413
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1
 * 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
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
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    if (n > m) return findMedianSortedArrays(nums2, nums1);
    int LMax1, LMax2, RMin1, RMin2;
    int c1, c2;
    int lo = 0, hi = 2 * n;
    while (lo <= hi) {
      c1 = (lo + hi) / 2;
      c2 = m + n - c1;
      LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
      RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[(c1) / 2];
      LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
      RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[(c2) / 2];
      if (LMax1 > RMin2) {
        hi = c1 - 1;
      } else if (LMax2 > RMin1) {
        lo = c1 + 1;
      } else {
        break;
      }
    }
    double res = max(LMax1, LMax2) + min(RMin1, RMin2);
    return res / 2;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */
