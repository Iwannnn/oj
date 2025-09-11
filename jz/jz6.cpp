#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  struct ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  vector<int> printListFromTailToHead(ListNode* head) {
    deque<int> res;
    ListNode* p = head;
    while (p) {
      res.push_front(p->val);
      p = p->next;
    }
    return vector<int>(res.begin(), res.end());
  }
};
