/*
 * @lc app=leetcode.cn id=LCR 155 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 155] 将二叉搜索树转化为排序的双向链表
 *
 * https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/description/
 *
 * algorithms
 * Medium (65.38%)
 * Likes:    761
 * Dislikes: 0
 * Total Accepted:    241.6K
 * Total Submissions: 369.3K
 * Testcase Example:  '[4,2,5,1,3]'
 *
 * 将一个 二叉搜索树 就地转化为一个 已排序的双向循环链表 。
 *
 * 对于双向循环列表，你可以将左右孩子指针作为双向循环链表的前驱和后继指针，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。
 *
 * 特别地，我们希望可以 就地
 * 完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中最小元素的指针。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [4,2,5,1,3]
 *
 *
 * 输出：[1,2,3,4,5]
 *
 * 解释：下图显示了转化后的二叉搜索树，实线表示后继关系，虚线表示前驱关系。
 *
 *
 *
 * 示例 2：
 *
 * 输入：root = [2,1,3]
 * 输出：[1,2,3]
 *
 *
 * 示例 3：
 *
 * 输入：root = []
 * 输出：[]
 * 解释：输入是空树，所以输出也是空链表。
 *
 *
 * 示例 4：
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * -1000 <= Node.val <= 1000
 * Node.left.val < Node.val < Node.right.val
 * Node.val 的所有值都是独一无二的
 * 0 <= Number of Nodes <= 2000
 *
 *
 * 注意：本题与主站 426
 * 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
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
class Node {
 public:
  int val;
  Node* left;
  Node* right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node* _left, Node* _right) {
    val = _val;
    left = _left;
    right = _right;
  }
};
// @lc code=start

class Solution {
 public:
  Node *prev, *head;
  Node* treeToDoublyList(Node* root) {
    if (!root) return nullptr;
    dfs(root);
    head->left = prev;
    prev->right = head;
    return head;
  }

  void dfs(Node* cur) {
    if (!cur) return;

    dfs(cur->left);
    if (!prev)
      head = cur;
    else
      prev->right = cur;
    cur->left = prev;
    prev = cur;
    dfs(cur->right);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,5,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
