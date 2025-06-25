#include <cstddef>
#include <iostream>

using namespace std;
struct TreeLinkNode {
  int val;
  struct TreeLinkNode *left;
  struct TreeLinkNode *right;
  struct TreeLinkNode *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
 public:
  TreeLinkNode *GetNext(TreeLinkNode *pNode) {
    auto r = pNode->right;
    if (r) {
      while (r->left) {
        r = r->left;
      }
      return r;
    }

    auto ne = pNode->next;

    if (!ne) return NULL;

    if (ne->left == pNode) {
      return ne;
    }

    while (ne && ne->left != pNode) {
      pNode = ne;
      ne = ne->next;
    }
    if (ne)
      return ne;
    else
      return NULL;
  }
};
