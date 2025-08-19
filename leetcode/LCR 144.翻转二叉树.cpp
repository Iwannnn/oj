/*
 * @lc app=leetcode.cn id=LCR 144 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 144] 翻转二叉树
 *
 * https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/description/
 *
 * algorithms
 * Easy (79.30%)
 * Likes:    398
 * Dislikes: 0
 * Total Accepted:    401.8K
 * Total Submissions: 506.8K
 * Testcase Example:  '[5,7,9,8,3,2,4]'
 *
 * 给定一棵二叉树的根节点 root，请左右翻转这棵二叉树，并返回其根节点。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [5,7,9,8,3,2,4]
 * 输出：[5,9,7,4,2,3,8]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在 [0, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 注意：本题与主站 226
 * 题相同：https://leetcode-cn.com/problems/invert-binary-tree/
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
  TreeNode *flipTree(TreeNode *root) {
    if (!root) return nullptr;
    flipTree(root->left);
    flipTree(root->right);
    swap(root->left, root->right);
    return root;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5,7,9,8,3,2,4]\n
// @lcpr case=end

 */
