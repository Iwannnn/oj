/*
 * @lc app=leetcode.cn id=LCR 123 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 123] 图书整理 I
 *
 * https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/description/
 *
 * algorithms
 * Easy (73.90%)
 * Likes:    489
 * Dislikes: 0
 * Total Accepted:    694.3K
 * Total Submissions: 939.5K
 * Testcase Example:  '[3,6,4,1]'
 *
 *
 * 书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。为更方便整理书架，店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放回到书架上。请倒序返回这个书单链表。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [3,6,4,1]
 *
 * 输出：[1,4,6,3]
 *
 *
 *
 *
 * 提示：
 *
 * 0 <= 链表长度 <= 10000
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
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start

class Solution {
 public:
  vector<int> reverseBookList(ListNode *head) {
    vector<int> res;
    ListNode *cur = head;
    ListNode *prev = nullptr;
    while (cur) {
      ListNode *tmp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = tmp;
    }
    cur = prev;
    while (cur) {
      res.push_back(cur->val);
      cur = cur->next;
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,6,4,1]\n
// @lcpr case=end

 */
