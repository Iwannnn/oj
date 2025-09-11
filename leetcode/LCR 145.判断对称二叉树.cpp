/*
 * @lc app=leetcode.cn id=LCR 145 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 145] 判断对称二叉树
 *
 * https://leetcode.cn/problems/dui-cheng-de-er-cha-shu-lcof/description/
 *
 * algorithms
 * Easy (57.65%)
 * Likes:    484
 * Dislikes: 0
 * Total Accepted:    324.8K
 * Total Submissions: 563.5K
 * Testcase Example:  '[6,7,7,8,9,9,8]'
 *
 * 请设计一个函数判断一棵二叉树是否 轴对称 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [6,7,7,8,9,9,8]
 * 输出：true
 * 解释：从图中可看出树是轴对称的。
 *
 * 示例 2：
 *
 *
 *
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 * 解释：从图中可看出最后一层的节点不对称。
 *
 *
 *
 * 提示：
 *
 * 0 <= 节点个数 <= 1000
 *
 * 注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/
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
  bool checkSymmetricTree(TreeNode *root) {
    if (!root) return true;
    return isSame(root->left, root->right);
  }

  bool isSame(TreeNode *a, TreeNode *b) {
    if (!a && !b) return true;

    if (!a || !b) return false;
    if (a->val != b->val) return false;

    return isSame(a->left, b->right) && isSame(a->right, b->left);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [6,7,7,8,9,9,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */
