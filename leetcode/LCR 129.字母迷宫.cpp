/*
 * @lc app=leetcode.cn id=LCR 129 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 129] 字母迷宫
 *
 * https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/description/
 *
 * algorithms
 * Medium (45.74%)
 * Likes:    846
 * Dislikes: 0
 * Total Accepted:    361.8K
 * Total Submissions: 791K
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 字母迷宫游戏初始界面记作 m x n 二维字符串数组 grid，请判断玩家是否能在 grid
 * 中找到目标单词 target。 注意：寻找单词时 必须
 * 按照字母顺序，通过水平或垂直方向相邻的单元格内的字母构成，同时，同一个单元格内的字母 不允许被重复使用 。
 *
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：grid = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], target
 * = "ABCCED" 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：grid = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], target
 * = "SEE" 输出：true
 *
 *
 * 示例 3：
 *
 * 输入：grid = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], target
 * = "ABCB" 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n = grid[i].length
 * 1 <= m, n <= 6
 * 1 <= target.length <= 15
 * grid 和 target 仅由大小写英文字母组成
 *
 *
 *
 *
 * 注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/
 *
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
  bool wordPuzzle(vector<vector<char>>& grid, string target) {
    if (grid.empty() || grid[0].empty()) return false;

    int m = grid.size(), n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (s(grid, target, i, j, 0, visited)) return true;
      }
    }
    return false;
  }

  bool s(vector<vector<char>>& grid, string target, int x, int y, int idx,
         vector<vector<bool>>& visited) {
    if (idx == target.size()) return true;

    int m = grid.size(), n = grid[0].size();

    if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y] ||
        grid[x][y] != target[idx])
      return false;

    visited[x][y] = true;
    bool res = s(grid, target, x + 1, y, idx + 1, visited) ||
               s(grid, target, x, y + 1, idx + 1, visited) ||
               s(grid, target, x - 1, y, idx + 1, visited) ||
               s(grid, target, x, y - 1, idx + 1, visited);
    visited[x][y] = false;

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */
