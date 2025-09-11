/*
 * @lc app=leetcode.cn id=LCR 124 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 124] 推理二叉树
 *
 * https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/description/
 *
 * algorithms
 * Medium (70.04%)
 * Likes:    1150
 * Dislikes: 0
 * Total Accepted:    360.2K
 * Total Submissions: 514.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 某二叉树的先序遍历结果记录于整数数组 preorder，它的中序遍历结果记录于整数数组
 * inorder。请根据 preorder 和 inorder 的提示构造出这棵二叉树并返回其根节点。
 *
 *
 *
 * 注意：preorder 和 inorder 中均不含重复数字。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 *
 * 输出: [3,9,20,null,null,15,7]
 *
 *
 *
 *
 * 示例 2:
 *
 * 输入: preorder = [-1], inorder = [-1]
 *
 * 输出: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
 *
 *
 *
 *
 * 注意：本题与主站 105
 * 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
#include <memory>
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
  TreeNode *deduceTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      inorder_index_[inorder[i]] = i;
    }
    return build(preorder, 0, preorder.size() - 1, inorder, 0,
                 inorder.size() - 1);
  }

 private:
  unordered_map<int, int> inorder_index_;

  TreeNode *build(const vector<int> &preorder, int preL, int preR,
                  const vector<int> &inorder, int inL, int inR) {
    if (preL > preR || inL > inR) return nullptr;

    // 前序的第一个是根节点
    int rootVal = preorder[preL];
    TreeNode *root = new TreeNode(rootVal);

    // 在中序遍历中找到根节点位置
    int inRootIndex = inorder_index_[rootVal];
    int leftSize = inRootIndex - inL;  // 左子树节点数

    // 递归构造左子树
    root->left = build(preorder, preL + 1, preL + leftSize, inorder, inL,
                       inRootIndex - 1);
    // 递归构造右子树
    root->right = build(preorder, preL + leftSize + 1, preR, inorder,
                        inRootIndex + 1, inR);
    return root;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
