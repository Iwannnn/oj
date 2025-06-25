/*
 * @lc app=leetcode.cn id=10 lang=cpp
 * @lcpr version=30204
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode.cn/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (30.82%)
 * Likes:    4021
 * Dislikes: 0
 * Total Accepted:    450.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持
 * '.' 和 '*' 的正则表达式匹配。
 *
 *
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 *
 *
 * 所谓匹配，是要涵盖 整个 字符串 s 的，而不是部分字符串。
 *
 *
 * 示例 1：
 *
 * 输入：s = "aa", p = "a"
 * 输出：false
 * 解释："a" 无法匹配 "aa" 整个字符串。
 *
 *
 * 示例 2:
 *
 * 输入：s = "aa", p = "a*"
 * 输出：true
 * 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是
 * 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 *
 *
 * 示例 3：
 *
 * 输入：s = "ab", p = ".*"
 * 输出：true
 * 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 20
 * 1 <= p.length <= 20
 * s 只包含从 a-z 的小写字母。
 * p 只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 保证每次出现字符 * 时，前面都匹配到有效的字符
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
  bool isMatch(string s, string p) {
    int m = s.size() + 1, n = p.size() + 1;
    vector<vector<bool>> dp(
        m, vector<bool>(
               n, false));  // dp[i][j] s的前i个字符 能否被p的前j个字符匹配
    dp[0][0] = true;
    for (int j = 2; j < n; j += 2)
      dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';  //空字符串的匹配需要被*抵消掉
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (p[j - 1] == '*') {  // j-1代表字符串中正在匹配的字符的位置
          if (dp[i][j - 2])  //产生空进行匹配
            dp[i][j] = true;
          else if (dp[i - 1][j] && s[i - 1] == p[j - 2])  //* 产生1个匹配
            dp[i][j] = true;
          else if (dp[i - 1][j] && p[j - 2] == '.')  // .*
            dp[i][j] = true;
        } else {
          if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1])
            dp[i][j] = true;
          else if (dp[i - 1][j - 1] && p[j - 1] == '.')
            dp[i][j] = true;
        }
      }
    }
    return dp[m - 1][n - 1];
  }
  // bool isMatch_(string s, string p) {
  //   if (p.empty()) return s.empty();
  //   if (p.size() > 1 && p[1] == '*')
  //     return isMatch_(s, p.substr(2)) ||
  //            (!s.empty() && (s[0] == p[0] || p[0] == '.') &&
  //             isMatch_(s.substr(1), p));
  //   else
  //     return (!s.empty() && (s[0] == p[0] || p[0] == '.') &&
  //             isMatch_(s.substr(1), p.substr(1)));
  // }
};
// @lc code=end

/*
// @lcpr case=start
// "aa"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"a*"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n".*"\n
// @lcpr case=end

 */
