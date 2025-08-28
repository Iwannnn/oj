/*
 * @lc app=leetcode.cn id=LCR 156 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 156] 序列化与反序列化二叉树
 *
 * https://leetcode.cn/problems/xu-lie-hua-er-cha-shu-lcof/description/
 *
 * algorithms
 * Hard (57.40%)
 * Likes:    445
 * Dislikes: 0
 * Total Accepted:    149.3K
 * Total Submissions: 260K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 *
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 *
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
 * 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 *
 * 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
 * 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [1,2,3,null,null,4,5]
 * 输出：[1,2,3,null,null,4,5]
 *
 *
 * 示例 2：
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 * 示例 4：
 *
 * 输入：root = [1,2]
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中结点数在范围 [0, 10^4] 内
 * -1000 <= Node.val <= 1000
 *
 *
 * 注意：本题与主站 297
 * 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
 *
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
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// @lcpr-template-end

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) return "[]";
    queue<TreeNode*> q;
    q.push(root);
    string res = "[";
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (node) {
        res += to_string(node->val);
        q.push(node->left);
        q.push(node->right);
      } else {
        res += "null";
      }
      if (!q.empty()) res += ",";
    }
    res += "]";
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data == "[]") return nullptr;
    vector<string> vals;
    vals.reserve(256);
    string s = data.substr(1, data.size() - 2);
    size_t start = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] == ',' || i == s.size()) {
        vals.push_back(s.substr(start, i - start));
        start = i + 1;
      }
    }

    TreeNode* root = new TreeNode(stoi(vals[0]));
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < vals.size()) {
      TreeNode* node = q.front();
      q.pop();

      if (i < vals.size() && vals[i] != "null") {
        node->left = new TreeNode(stoi(vals[i]));
        q.push(node->left);
      }
      ++i;
      if (i < vals.size() && vals[i] != "null") {
        node->right = new TreeNode(stoi(vals[i]));
        q.push(node->right);
      }
      ++i;
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,null,null,4,5]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
