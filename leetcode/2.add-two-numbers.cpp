/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30204
 *
 * [2] 两数相加
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (44.96%)
 * Likes:    11089
 * Dislikes: 0
 * Total Accepted:    2.3M
 * Total Submissions: 5.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空
 * 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 *
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 *
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 *
 *
 * 示例 1：
 *
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 *
 *
 * 示例 2：
 *
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 *
 *
 * 示例 3：
 *
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 <= Node.val <= 9
 * 题目数据保证列表表示的数字不含前导零
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *tmp1 = l1, *tmp2 = l2, *tmp3, *res;
    // tmp1 = reverse(l1);
    // tmp2 = reverse(l2);
    int c = 0;
    if (tmp1) {
      c += tmp1->val;
      tmp1 = tmp1->next;
    }
    if (tmp2) {
      c += tmp2->val;
      tmp2 = tmp2->next;
    }
    ListNode* p = new ListNode(c % 10);
    c /= 10;
    res = p;
    tmp3 = res;
    while (tmp1 or tmp2 or c) {
      if (tmp1) {
        c += tmp1->val;
        tmp1 = tmp1->next;
      }
      if (tmp2) {
        c += tmp2->val;
        tmp2 = tmp2->next;
      }
      ListNode* p = new ListNode(c % 10);
      tmp3->next = p;
      tmp3 = tmp3->next;
      c /= 10;
    }
    return res;
    // return reverse(res);
  }
  //   ListNode* reverse(ListNode* start) {
  //     ListNode *pre, *cur, *next, *res;

  //     pre = NULL;
  //     cur = start;
  //     while (cur) {
  //       next = cur->next;
  //       cur->next = pre;
  //       pre = cur;
  //       cur = next;
  //     }
  //     return pre;
  // }
};
// @lc code=end

/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */
