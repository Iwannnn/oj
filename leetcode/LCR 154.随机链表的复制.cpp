/*
 * @lc app=leetcode.cn id=LCR 154 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 154] 复杂链表的复制
 *
 * https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/description/
 *
 * algorithms
 * Medium (71.48%)
 * Likes:    803
 * Dislikes: 0
 * Total Accepted:    315.6K
 * Total Submissions: 441.6K
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]'
 *
 * 请实现 copyRandomList
 * 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next
 * 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：head = [[1,1],[2,1]]
 * 输出：[[1,1],[2,1]]
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：head = [[3,null],[3,0],[3,null]]
 * 输出：[[3,null],[3,0],[3,null]]
 *
 *
 * 示例 4：
 *
 * 输入：head = []
 * 输出：[]
 * 解释：给定的链表为空（空指针），因此返回 null。
 *
 *
 *
 *
 * 提示：
 *
 *
 * -10000 <= Node.val <= 10000
 * Node.random 为空（null）或指向链表中的节点。
 * 节点数目不超过 1000 。
 *
 *
 *
 *
 * 注意：本题与主站 138
 * 题相同：https://leetcode-cn.com/problems/copy-list-with-random-pointer/
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
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};
// @lc code=start
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;
    Node* cur = head;
    unordered_map<Node*, Node*> map;

    while (cur) {
      map[cur] = new Node(cur->val);
      cur = cur->next;
    }

    cur = head;
    while (cur) {
      map[cur]->next = map[cur->next];
      map[cur]->random = map[cur->random];
      cur = cur->next;
    }

    return map[head];
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
