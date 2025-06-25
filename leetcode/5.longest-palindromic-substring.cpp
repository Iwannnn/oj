/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30204
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (39.13%)
 * Likes:    7542
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 4.9M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的 回文 子串。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
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
  string longestPalindrome(string s) {
    int l = s.size(), max_i = 0, max_l = 1;  // max_l 为1 j<i 为0 j<=i
    if (l == 0 || l == 1) return s;
    vector<vector<int>> dp(l, vector<int>(l));
    for (int i = 0; i < l; ++i) {
      dp[i][i] = 1;
      for (int j = 0; j < i; ++j) {
        dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
        if (dp[j][i] && max_l < i - j + 1) {
          max_l = i - j + 1;
          max_i = j;
        }
      }
    }
    return s.substr(max_i, max_l);
  }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
