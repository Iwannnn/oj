/*
 * @lc app=leetcode.cn id=LCR 140 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 140] 训练计划 II
 *
 * https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/description/
 *
 * algorithms
 * Easy (79.35%)
 * Likes:    536
 * Dislikes: 0
 * Total Accepted:    530.4K
 * Total Submissions: 668.7K
 * Testcase Example:  '[2,4,7,8]\n1'
 *
 * 给定一个头节点为 head
 * 的链表用于记录一系列核心肌群训练项目编号，请查找并返回倒数第 cnt
 * 个训练项目编号。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [2,4,7,8], cnt = 1
 * 输出：8
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= head.length <= 100
 * 0 <= head[i] <= 100
 * 1 <= cnt <= head.length
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
  ListNode* trainingPlan(ListNode* head, int cnt) {
    if (!head || cnt < 0) return nullptr;

    ListNode* fast = head;
    for (int i = 0; i < cnt; ++i) {
      if (!fast) return nullptr;
      fast = fast->next;
    }

    ListNode* slow = head;
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,4,7,8]\n1\n
// @lcpr case=end

 */
