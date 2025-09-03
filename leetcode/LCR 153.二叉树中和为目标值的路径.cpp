/*
 * @lc app=leetcode.cn id=LCR 153 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 153] 二叉树中和为目标值的路径
 *
 * https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/description/
 *
 * algorithms
 * Medium (59.26%)
 * Likes:    469
 * Dislikes: 0
 * Total Accepted:    290.1K
 * Total Submissions: 489.5K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有
 * 从根节点到叶子节点 路径总和等于给定目标和的路径。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：[[5,4,11,2],[5,8,4,5]]
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：root = [1,2], targetSum = 0
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点总数在范围 [0, 5000] 内
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
 *
 *
 * 注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/
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
  vector<vector<int>> pathTarget(TreeNode *root, int target) {
    if (!root) return {};
    vector<vector<int>> res;
    vector<int> path;
    dfs(res, path, root, target);

    return res;
  }

  void dfs(vector<vector<int>> &res, vector<int> &path, TreeNode *node,
           int remain) {
    if (!node) return;
    path.push_back(node->val);
    remain -= node->val;

    if (!node->left && !node->right && remain == 0) res.push_back(path);

    dfs(res, path, node->left, remain);
    dfs(res, path, node->right, remain);
    path.pop_back();
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */
