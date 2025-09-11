#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param preOrder int整型vector
   * @param vinOrder int整型vector
   * @return TreeNode类
   */
  TreeNode* reConstructBinaryTree(vector<int>& preOrder,
                                  vector<int>& vinOrder) {
    // write code here
    if (!preOrder.size()) return nullptr;
    TreeNode* root = new TreeNode(preOrder[0]);
    vector<int> l_pre, l_vin;
    vector<int> r_pre, r_vin;
    int x = preOrder[0];

    int idx = -1;
    int f = 0;
    for (int i = 0; i < vinOrder.size(); ++i) {
      if (vinOrder[i] == x) {
        idx = i;
        f = 1;
        continue;
      }
      if (f == 0) {
        l_vin.push_back(vinOrder[i]);
      } else {
        r_vin.push_back(vinOrder[i]);
      }
    }
    for (int i = 1; i < preOrder.size(); ++i) {
      if (l_pre.size() < l_vin.size()) {
        l_pre.push_back(preOrder[i]);
      } else {
        r_pre.push_back(preOrder[i]);
      }
    }

    root->left = reConstructBinaryTree(l_pre, l_vin);
    root->right = reConstructBinaryTree(r_pre, r_vin);

    return root;
  }
};