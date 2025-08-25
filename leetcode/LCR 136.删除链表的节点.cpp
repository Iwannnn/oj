/*
 * @lc app=leetcode.cn id=LCR 136 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 136] 删除链表的节点
 *
 * https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/description/
 *
 * algorithms
 * Easy (59.13%)
 * Likes:    366
 * Dislikes: 0
 * Total Accepted:    413.6K
 * Total Submissions: 699.9K
 * Testcase Example:  '[4,5,1,9]\n5'
 *
 * 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
 *
 * 返回删除后的链表的头节点。
 *
 * 示例 1：
 *
 * 输入：head = [4,5,1,9], val = 5
 * 输出：[4,1,9]
 * 解释：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为
 * 4 -> 1 -> 9.
 *
 *
 * 示例 2：
 *
 * 输入：head = [4,5,1,9], val = 1
 * 输出：[4,5,9]
 * 解释：给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为
 * 4 -> 5 -> 9.
 *
 *
 *
 *
 * 说明：
 *
 *
 * 题目保证链表中节点的值互不相同
 * 若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点
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
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
 public:
  ListNode* deleteNode(ListNode* head, int val) {
    ListNode* dummy = new ListNode(-1, head);
    ListNode *prev = dummy, *cur = head;
    while (cur) {
      if (cur->val == val) {
        prev->next = nullptr;
        cur = cur->next;
        continue;
      }
      prev->next = cur;
      prev = cur;
      cur = cur->next;
    }
    return dummy->next;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,1,9]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,5,1,9]\n1\n
// @lcpr case=end

 */
