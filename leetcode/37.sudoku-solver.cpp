/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=30204
 *
 * [37] 解数独
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
  void solveSudoku(vector<vector<char>> &board) { f(board, 0, 0); }

  bool f(vector<vector<char>> &board, int i, int j) {
    if (i == 9)
      return true;
    if (j >= 9)
      return f(board, i + 1, 0);
    if (board[i][j] != '.')
      return f(board, i, j + 1);
    for (char c = '1'; c <= '9'; ++c) {
      if (!is_valid(board, i, j, c))
        continue;
      board[i][j] = c;
      if (f(board, i, j + 1))
        return true;
      board[i][j] = '.';
    }
    return false;
  }
  bool is_valid(vector<vector<char>> &board, int i, int j, char val) {
    for (int x = 0; x < 9; ++x)
      if (board[x][j] == val)
        return false;

    for (int y = 0; y < 9; ++y)
      if (board[i][y] == val)
        return false;

    int row = i - i % 3, col = j - j % 3;
    for (int x = row; x < row + 3; ++x)
      for (int y = col; y < col + 3; ++y)
        if (board[x][y] == val)
          return false;
    return true;
  }
};
// @lc code=end

/*
// @lcpr case=start
//
[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */
