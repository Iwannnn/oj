/*
 * @lc app=leetcode.cn id=LCR 152 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 152] 验证二叉搜索树的后序遍历序列
 *
 * https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/description/
 *
 * algorithms
 * Medium (57.03%)
 * Likes:    791
 * Dislikes: 0
 * Total Accepted:    245.7K
 * Total Submissions: 430.6K
 * Testcase Example:  '[4,9,6,5,8]'
 *
 * 请实现一个函数来判断整数数组 postorder 是否为二叉搜索树的后序遍历结果。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入: postorder = [4,9,6,5,8]
 * 输出: false
 * 解释：从上图可以看出这不是一颗二叉搜索树
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入: postorder = [4,6,5,9,8]
 * 输出: true
 * 解释：可构建的二叉搜索树如上图
 *
 *
 *
 *
 * 提示：
 *
 *
 * 数组长度 <= 1000
 * postorder 中无重复数字
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
  bool verifyTreeOrder(vector<int>& postorder) {
    stack<int> st;
    int root = INT_MAX;
    for (int i = postorder.size() - 1; i >= 0; --i) {
      if (postorder[i] > root) return false;
      while (!st.empty() && st.top() > postorder[i]) {
        root = postorder[i];
        st.pop();
      }

      st.push(postorder[i]);
    }
    return true;
  }
  // bool verifyTreeOrder(vector<int>& postorder) {
  //   return recur(postorder, 0, postorder.size() - 1);
  // }

  bool recur(vector<int>& postorder, int i, int j) {
    if (i >= j) return true;
    int p = i;
    while (postorder[p] < postorder[j]) ++p;
    int m = p;
    while (postorder[p] > postorder[j]) ++p;
    return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4,9,6,5,8]\n
// @lcpr case=end

// @lcpr case=start
// [4,6,5,9,8]\n
// @lcpr case=end

 */
