/*
 * @lc app=leetcode.cn id=95 lang=cpp
 * @lcpr version=30204
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode.cn/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (74.56%)
 * Likes:    1627
 * Dislikes: 0
 * Total Accepted:    210.2K
 * Total Submissions: 281.8K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n
 * 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 3
 * 输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 *
 *
 * 示例 2：
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 8
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
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0) return {};
    return build(1, n);
  }

  vector<TreeNode *> build(int start, int end) {
    vector<TreeNode *> res;
    if (start > end) {
      res.push_back(nullptr);
      return res;
    }

    for (int i = start; i <= end; ++i) {
      auto left_trees = build(start, i - 1);
      auto right_trees = build(i + 1, end);
      for (auto left_tree : left_trees) {
        for (auto right_tree : right_trees) {
          TreeNode *root = new TreeNode(i);
          root->left = left_tree;
          root->right = right_tree;
          res.push_back((root));
        }
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
