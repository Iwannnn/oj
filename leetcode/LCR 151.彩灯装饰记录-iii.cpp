/*
 * @lc app=leetcode.cn id=LCR 151 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 151] 彩灯装饰记录 III
 *
 * https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/description/
 *
 * algorithms
 * Medium (58.24%)
 * Likes:    317
 * Dislikes: 0
 * Total Accepted:    279.7K
 * Total Submissions: 480.1K
 * Testcase Example:  '[8,17,21,18,null,null,6]'
 *
 * 一棵圣诞树记作根节点为 root
 * 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照如下规则记录彩灯装饰结果：
 *
 *
 * 第一层按照从左到右的顺序记录
 * 除第一层外每一层的记录顺序均与上一层相反。即第一层为从左到右，第二层为从右到左。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [8,17,21,18,null,null,6]
 * 输出：[[8],[21,17],[18,6]]
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
  vector<vector<int>> decorateRecord(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> res;
    int f = 0;  // 0从左往右 1从右往左
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      vector<int> tmp;
      while (n--) {
        auto node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);

        tmp.push_back(node->val);
      }

      if (f == 0) {
        f = 1;
      } else {
        f = 0;
        reverse(tmp.begin(), tmp.end());
      }
      res.push_back(tmp);
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
