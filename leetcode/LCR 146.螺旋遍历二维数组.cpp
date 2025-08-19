/*
 * @lc app=leetcode.cn id=LCR 146 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 146] 螺旋遍历二维数组
 *
 * https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/description/
 *
 * algorithms
 * Easy (41.86%)
 * Likes:    614
 * Dislikes: 0
 * Total Accepted:    302.6K
 * Total Submissions: 724K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个二维数组 array，请返回「螺旋遍历」该数组的结果。
 *
 * 螺旋遍历：从左上角开始，按照 向右、向下、向左、向上 的顺序 依次
 * 提取元素，然后再进入内部一层重复相同的步骤，直到提取完所有元素。
 *
 *
 *
 * 示例 1：
 *
 * 输入：array = [[1,2,3],[8,9,4],[7,6,5]]
 * 输出：[1,2,3,4,5,6,7,8,9]
 *
 *
 * 示例 2：
 *
 * 输入：array  = [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]
 * 输出：[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
 *
 *
 *
 *
 * 限制：
 *
 *
 * 0 <= array.length <= 100
 * 0 <= array[i].length <= 100
 *
 *
 * 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/
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
#include <iterator>
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
// @lc code=start
class Solution {
 public:
  vector<int> spiralArray(vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return {};
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
// [[1,2,3],[8,9,4],[7,6,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]\n
// @lcpr case=end

 */
