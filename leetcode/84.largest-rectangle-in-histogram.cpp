/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30204
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (47.57%)
 * Likes:    2952
 * Dislikes: 0
 * Total Accepted:    546.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为
 * 1 。
 *
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入： heights = [2,4]
 * 输出： 4
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= heights.length <=10^5
 * 0 <= heights[i] <= 10^4
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
  int largestRectangleArea(vector<int>& heights) {
    int res = 0, n = heights.size();
    vector<int> left(n), right(n);
    // 比h[i] 小的左右位置 找到h[i]都能用到的左右位置
    stack<int> st;
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        // i左边第一个比i小的
        st.pop();
      }
      left[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }
    st = stack<int>();
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        // i 右边第一个比i小的
        st.pop();
      }
      right[i] = st.empty() ? n : st.top();
      st.push(i);
    }

    for (int i = 0; i < n; ++i) {
      res = max(res, (right[i] - left[i] - 1) * heights[i]);
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */
