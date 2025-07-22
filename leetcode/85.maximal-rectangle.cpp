/*
 * @lc app=leetcode.cn id=85 lang=cpp
 * @lcpr version=30204
 *
 * [85] 最大矩形
 *
 * https://leetcode.cn/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (55.83%)
 * Likes:    1745
 * Dislikes: 0
 * Total Accepted:    220.1K
 * Total Submissions: 393.8K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1
 * 的最大矩形，并返回其面积。
 *
 *
 *
 * 示例 1：
 *
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：6
 * 解释：最大矩形如上图所示。
 *
 *
 * 示例 2：
 *
 * 输入：matrix = [["0"]]
 * 输出：0
 *
 *
 * 示例 3：
 *
 * 输入：matrix = [["1"]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * rows == matrix.length
 * cols == matrix[0].length
 * 1 <= row, cols <= 200
 * matrix[i][j] 为 '0' 或 '1'
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
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int n = matrix.size(), m = matrix[0].size();
    vector<int> heights(m, 0);
    int res = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] == '1')
          heights[j] += 1;
        else
          heights[j] = 0;
      }
      res = max(res, largestRectangleArea(heights));
    }
    return res;
  }
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
//
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1"]]\n
// @lcpr case=end

 */
