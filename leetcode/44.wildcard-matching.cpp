/*
 * @lc app=leetcode.cn id=44 lang=cpp
 * @lcpr version=30204
 *
 * [44] 通配符匹配
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
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false)); // dp[m][n];
    dp[0][0] = true;

    for (int i = 1; i <= n; ++i) {
      if (p[i - 1] == '*')
        dp[0][i] = dp[0][i - 1];
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (s[i - 1] == p[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        if (p[j - 1] == '*')
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // 用*匹配i或者*为空
        if (p[j - 1] == '?')
          dp[i][j] = dp[i - 1][j - 1];
      }
    }

    return dp[m][n];
  }
};
// @lc code=end

/*
// @lcpr case=start
// "aa"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"*"\n
// @lcpr case=end

// @lcpr case=start
// "cb"\n"?a"\n
// @lcpr case=end

 */
