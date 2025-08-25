/*
 * @lc app=leetcode.cn id=LCR 141 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 141] 训练计划 III
 *
 * https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/description/
 *
 * algorithms
 * Easy (74.18%)
 * Likes:    641
 * Dislikes: 0
 * Total Accepted:    619.6K
 * Total Submissions: 835.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一个头节点为 head
 * 的单链表用于记录一系列核心肌群训练编号，请将该系列训练编号 倒序
 * 记录于链表并返回。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 *
 *
 *
 *
 * 示例 2：
 *
 * 输入：head = [1,2]
 * 输出：[2,1]
 *
 *
 *
 *
 * 示例 3：
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 <= Node.val <= 5000
 *
 *
 *
 *
 * 注意：本题与主站 206
 * 题相同：https://leetcode-cn.com/problems/reverse-linked-list/
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
  ListNode* trainningPlan(ListNode* head) {
    ListNode* dummy = new ListNode();
    ListNode* p = head;
    while (p) {
      ListNode* tmp = p->next;
      p->next = dummy->next;
      dummy->next = p;
      p = tmp;
    }
    return dummy->next;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
