/*
 * @lc app=leetcode.cn id=LCR 137 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 137] 模糊搜索验证
 *
 * https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof/description/
 *
 * algorithms
 * Hard (38.11%)
 * Likes:    575
 * Dislikes: 0
 * Total Accepted:    131.2K
 * Total Submissions: 344.4K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 请设计一个程序来支持用户在文本编辑器中的模糊搜索功能。用户输入内容中可能使用到如下两种通配符：
 *
 *
 * '.' 匹配任意单个字符。
 * '*' 匹配零个或多个前面的那一个元素。
 *
 *
 *
 *
 * 请返回用户输入内容 input 所有字符是否可以匹配原文字符串 article。
 *
 *
 *
 * 示例 1：
 *
 * 输入：article = "aa", input = "a"
 * 输出：false
 * 解释："a" 无法匹配 "aa" 整个字符串。
 *
 *
 * 示例 2：
 *
 * 输入：article = "aa", input = "a*"
 * 输出：true
 * 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是
 * 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 *
 *
 * 示例 3：
 *
 * 输入：article = "ab", input = ".*"
 * 输出：true
 * 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= article.length <= 20
 * 1 <= input.length <= 20
 * article 只包含从 a-z 的小写字母。
 * input 只包含从 a-z 的小写字母，以及字符 . 和 * 。
 * 保证每次出现字符 * 时，前面都匹配到有效的字符
 *
 *
 *
 *
 * 注意：本题与主站 10
 * 题相同：https://leetcode-cn.com/problems/regular-expression-matching/
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
  bool articleMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    // a*b* 可以匹配空串
    for (int j = 2; j <= n; j += 2)
      if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] = dp[i][j - 2] ||
                     (dp[i - 1][j] && (s[i - 1] == p[j - 2] ||
                                       p[j - 2] == '.'));  // 重复前一个字符
        } else {
          dp[i][j] =
              dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }
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
// "aa"\n"a*"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n".*"\n
// @lcpr case=end

 */
