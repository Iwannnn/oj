/*
 * @lc app=leetcode.cn id=LCR 174 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 174] 寻找二叉搜索树中的目标节点
 *
 * https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/description/
 *
 * algorithms
 * Easy (76.48%)
 * Likes:    424
 * Dislikes: 0
 * Total Accepted:    335.9K
 * Total Submissions: 439.2K
 * Testcase Example:  '[7,3,9,1,5]\n2'
 *
 * 某公司组织架构以二叉搜索树形式记录，节点值为处于该职位的员工编号。请返回第
 * cnt 大的员工编号。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [7, 3, 9, 1, 5], cnt = 2
 * ⁠      7
 * ⁠     / \
 * ⁠    3   9
 * ⁠   / \
 * ⁠  1   5
 * 输出：7
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入: root = [10, 5, 15, 2, 7, null, 20, 1, null, 6, 8], cnt = 4
 * ⁠      10
 * ⁠     / \
 * ⁠    5   15
 * ⁠   / \    \
 * ⁠  2   7    20
 * ⁠ /   / \
 * ⁠1   6   8
 * 输出: 8
 *
 *
 *
 * 提示：
 *
 *
 * 1 ≤ cnt ≤ 二叉搜索树元素个数
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
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
 public:
  int findTargetNode(TreeNode *root, int cnt) {
    int res;
    dfs(root, cnt, res);
    return res;
  }

  void dfs(TreeNode *node, int &cnt, int &res) {
    if (node == nullptr) return;
    dfs(node->right, cnt, res);
    cnt--;
    if (cnt == 0) {
      res = node->val;
      return;
    }
    dfs(node->left, cnt, res);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [7, 3, 9, 1, 5]\n27/ \3   9/ \1   5\n
// @lcpr case=end

// @lcpr case=start
// [10, 5, 15, 2, 7, null, 20, 1, null, 6, 8]\n410/ \5   15/ \    \2   7    20/
/ \ 1   6   8\n
// @lcpr case=end

 */
