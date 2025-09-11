/*
 * @lc app=leetcode.cn id=LCR 143 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 143] 子结构判断
 *
 * https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/description/
 *
 * algorithms
 * Medium (46.35%)
 * Likes:    831
 * Dislikes: 0
 * Total Accepted:    342.4K
 * Total Submissions: 738.7K
 * Testcase Example:  '[1,2,3,4]\n[3]'
 *
 * 给定两棵二叉树 tree1 和 tree2，判断 tree2 是否以 tree1
 * 的某个节点为根的子树具有 相同的结构和节点值 。 注意，空树 不会是以 tree1
 * 的某个节点为根的子树具有 相同的结构和节点值 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 *
 *
 *
 * 输入：tree1 = [1,7,5], tree2 = [6,1]
 * 输出：false
 * 解释：tree2 与 tree1 的一个子树没有相同的结构和节点值。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：tree1 = [3,6,7,1,8], tree2 = [6,1]
 * 输出：true
 * 解释：tree2 与 tree1 的一个子树拥有相同的结构和节点值。即 6 - > 1。
 *
 *
 *
 * 提示：
 *
 * 0 <= 节点个数 <= 10000
 *
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstddef>
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
  bool isSubStructure(TreeNode *a, TreeNode *b) {
    if (b == nullptr || a == nullptr) return false;
    return isSame(a, b) || isSubStructure(a->left, b) ||
           isSubStructure(a->right, b);
  }

  bool isSame(TreeNode *a, TreeNode *b) {
    if (!b) return true;
    if (!a && b) return false;
    if (a->val != b->val) return false;
    return isSame(a->left, b->left) && isSame(a->right, b->right);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,7,5]\n[6,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,6,7,1,8]\n[6,1]\n
// @lcpr case=end

 */
