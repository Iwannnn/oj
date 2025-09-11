/*
 * @lc app=leetcode.cn id=LCR 175 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 175] 计算二叉树的深度
 *
 * https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/description/
 *
 * algorithms
 * Easy (79.23%)
 * Likes:    277
 * Dislikes: 0
 * Total Accepted:    348.5K
 * Total Submissions: 439.9K
 * Testcase Example:  '[1,2,2,3,null,null,5,4,null,null,4]'
 *
 * 某公司架构以二叉树形式记录，请返回该公司的层级数。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [1, 2, 2, 3, null, null, 5, 4, null, null, 4]
 * 输出: 4
 * 解释: 上面示例中的二叉树的最大深度是 4，沿着路径 1 -> 2 -> 3 -> 4 或 1 -> 2
 * -> 5 -> 4 到达叶节点的最长路径上有 4 个节点。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 节点总数 <= 10000
 *
 *
 * 注意：本题与主站 104
 * 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
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
  int calculateDepth(TreeNode *root) {
    if (!root) return 0;
    queue<TreeNode *> q;
    q.push(root);

    int res = 0;
    while (!q.empty()) {
      ++res;
      for (int i = q.size(); i >= 1; --i) {
        auto node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1, 2, 2, 3, null, null, 5, 4, null, null, 4]\n
// @lcpr case=end

 */
