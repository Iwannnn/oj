/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30204
 *
 * [59] 螺旋矩阵 II
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
  vector<vector<int>> generateMatrix(int n) {
    int cnt = 1;
    vector<vector<int>> res(n, vector<int>(n, 0));
    int i = 0, j = 0;
    int right_ = n - 1, down_ = n - 1, left_ = 0, up_ = 0;
    while (true) {
      for (int j = left_; j <= right_; ++j)
        res[up_][j] = cnt++;
      if (++up_ > down_)
        break;
      for (int i = up_; i <= down_; ++i)
        res[i][right_] = cnt++;
      if (--right_ < left_)
        break;
      for (int j = right_; j >= left_; --j)
        res[down_][j] = cnt++;
      if (--down_ < up_)
        break;
      for (int i = down_; i >= up_; --i)
        res[i][left_] = cnt++;
      if (++left_ > right_)
        break;
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
