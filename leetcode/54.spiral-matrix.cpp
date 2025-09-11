/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30204
 *
 * [54] 螺旋矩阵
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
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int i = 0, j = 0;
    int left_boarder = -1, right_boarder = m, up_boarder = 0, down_boarder = n;
    int right = 1, down = 0, left = 0, up = 0;
    vector<int> res;

    while (res.size() != n * m) {
      res.push_back(matrix[i][j]);
      if (right == 1) {
        ++j;
        if (j == right_boarder) {
          ++i;
          --j;
          --right_boarder;
          down = 1;
          right = 0;
        }
      } else if (down == 1) {
        ++i;
        if (i == down_boarder) {
          --i;
          --j;
          --down_boarder;
          left = 1;
          down = 0;
        }
      } else if (left == 1) {
        --j;
        if (j == left_boarder) {
          ++j;
          --i;
          ++left_boarder;
          up = 1;
          left = 0;
        }
      } else if (up == 1) {
        --i;
        if (i == up_boarder) {
          ++i;
          ++j;
          ++up_boarder;
          right = 1;
          up = 0;
        }
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */
