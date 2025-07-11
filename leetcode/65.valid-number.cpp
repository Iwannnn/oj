/*
 * @lc app=leetcode.cn id=65 lang=cpp
 * @lcpr version=30204
 *
 * [65] 有效数字
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
  bool isNumber(string s) {
    vector<unordered_map<char, int>> states = {
        {{' ', 0}, {'s', 1}, {'d', 2}, {'.', 4}}, // 0. start with 'blank'
        {{'d', 2}, {'.', 4}},                     // 1. 'sign' before 'e'
        {{'d', 2}, {'.', 3}, {'e', 5}, {' ', 8}}, // 2. 'digit' before 'dot'
        {{'d', 3}, {'e', 5}, {' ', 8}},           // 3. 'digit' after 'dot'
        {{'d', 3}}, // 4. 'digit' after 'dot' (‘blank’ before 'dot')
        {{'s', 6}, {'d', 7}}, // 5. 'e'
        {{'d', 7}},           // 6. 'sign' after 'e'
        {{'d', 7}, {' ', 8}}, // 7. 'digit' after 'e'
        {{' ', 8}}            // 8. end with 'blank'
    };
    int p = 0; // start with state 0
    for (char c : s) {
      char t;
      if (c >= '0' && c <= '9')
        t = 'd'; // digit
      else if (c == '+' || c == '-')
        t = 's'; // sign
      else if (c == 'e' || c == 'E')
        t = 'e'; // e or E
      else if (c == '.' || c == ' ')
        t = c; // dot, blank
      else
        t = '?'; // unknown

      if (states[p].count(t) == 0)
        return false;
      p = states[p][t];
    }
    return p == 2 || p == 3 || p == 7 || p == 8;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "0"\n
// @lcpr case=end

// @lcpr case=start
// "e"\n
// @lcpr case=end

// @lcpr case=start
// "."\n
// @lcpr case=end

 */
