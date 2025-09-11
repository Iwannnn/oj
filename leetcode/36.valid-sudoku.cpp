/*
 * @lc app=leetcode.cn id=36 lang=cpp
 * @lcpr version=30204
 *
 * [36] 有效的数独
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
  bool isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; ++i) {
      map<char, int> a;
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          if (a[board[i][j]])
            return false;
          ++a[board[i][j]];
        }
      }
    }

    for (int i = 0; i < 9; ++i) {
      map<char, int> a;
      for (int j = 0; j < 9; ++j) {
        if (board[j][i] != '.') {
          if (a[board[j][i]])
            return false;
          ++a[board[j][i]];
        }
      }
    }

    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        map<char, int> c;
        for (int a = i; a < i + 3; ++a) {
          for (int b = j; b < j + 3; ++b) {
            if (board[a][b] != '.') {
              if (c[board[a][b]])
                return false;
              ++c[board[a][b]];
            }
          }
        }
      }
    }
    return true;
  }
};
// @lc code=end

/*
// @lcpr case=start
//
[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

// @lcpr case=start
//
[["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */
