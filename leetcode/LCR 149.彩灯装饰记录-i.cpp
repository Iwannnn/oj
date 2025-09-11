/*
 * @lc app=leetcode.cn id=LCR 149 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 149] 彩灯装饰记录 I
 *
 * https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/description/
 *
 * algorithms
 * Medium (63.00%)
 * Likes:    317
 * Dislikes: 0
 * Total Accepted:    306.3K
 * Total Submissions: 486.3K
 * Testcase Example:  '[8,17,21,18,null,null,6]'
 *
 * 一棵圣诞树记作根节点为 root
 * 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照从 左 到 右
 * 的顺序返回每一层彩灯编号。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [8,17,21,18,null,null,6]
 * 输出：[8,17,21,18,6]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 节点总数 <= 1000
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
  vector<int> decorateRecord(TreeNode *root) {
    if (!root) return {};

    vector<int> res;
    res.reserve(1010);

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      res.push_back(node->val);
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [8,17,21,18,null,null,6]\n
// @lcpr case=end

 */
