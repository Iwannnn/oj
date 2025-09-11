/*
 * @lc app=leetcode.cn id=LCR 130 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 130] 衣橱整理
 *
 * https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/description/
 *
 * algorithms
 * Medium (53.57%)
 * Likes:    686
 * Dislikes: 0
 * Total Accepted:    342.3K
 * Total Submissions: 638.9K
 * Testcase Example:  '4\n7\n5'
 *
 * 家居整理师将待整理衣橱划分为 m x n 的二维矩阵 grid，其中 grid[i][j]
 * 代表一个需要整理的格子。整理师自 grid[0][0] 开始 逐行逐列 地整理每个格子。
 *
 * 整理规则为：在整理过程中，可以选择 向右移动一格 或 向下移动一格，但不能移动到衣柜之外。同时，不需要整理
 * digit(i) + digit(j) > cnt 的格子，其中 digit(x) 表示数字 x 的各数位之和。
 *
 * 请返回整理师 总共需要整理多少个格子。
 *
 *
 *
 * 示例 1：
 *
 * 输入：m = 4, n = 7, cnt = 5
 * 输出：18
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n, m <= 100
 * 0 <= cnt <= 20
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
// @lc code=start
class Solution {
 public:
  int wardrobeFinishing(int m, int n, int cnt) {
    int res = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    s(0, 0, m, n, cnt, res, visited);
    return res;
  }

  void s(int x, int y, int m, int n, int cnt, int &res,
         vector<vector<bool>> &visited) {
    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) return;

    if (digit(x) + digit(y) > cnt) return;
    visited[x][y] = true;
    ++res;

    s(x + 1, y, m, n, cnt, res, visited);
    s(x, y + 1, m, n, cnt, res, visited);
  }

  int digit(int x) {
    int res = 0;
    while (x) {
      res += (x % 10);
      x /= 10;
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n7\n5\n
// @lcpr case=end

 */
