/*
 * @lc app=leetcode.cn id=87 lang=cpp
 * @lcpr version=30204
 *
 * [87] 扰乱字符串
 *
 * https://leetcode.cn/problems/scramble-string/description/
 *
 * algorithms
 * Hard (47.16%)
 * Likes:    602
 * Dislikes: 0
 * Total Accepted:    70K
 * Total Submissions: 148.4K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * 使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
 *
 * 如果字符串的长度为 1 ，算法停止
 * 如果字符串的长度 > 1 ，执行下述步骤：
 *
 * 在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s
 * ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。 随机
 * 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s
 * 可能是 s = x + y 或者 s = y + x 。 在 x 和 y 这两个子字符串上继续从步骤 1
 * 开始递归执行此算法。
 *
 *
 *
 *
 * 给你两个 长度相等 的字符串 s1
 * 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false
 * 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s1 = "great", s2 = "rgeat"
 * 输出：true
 * 解释：s1 上可能发生的一种情形是：
 * "great" --> "gr/eat" // 在一个随机下标处分割得到两个子字符串
 * "gr/eat" --> "gr/eat" // 随机决定：「保持这两个子字符串的顺序不变」
 * "gr/eat" --> "g/r / e/at" //
 * 在子字符串上递归执行此算法。两个子字符串分别在随机下标处进行一轮分割 "g/r /
 * e/at" --> "r/g / e/at" //
 * 随机决定：第一组「交换两个子字符串」，第二组「保持这两个子字符串的顺序不变」
 * "r/g / e/at" --> "r/g / e/ a/t" // 继续递归执行此算法，将 "at" 分割得到 "a/t"
 * "r/g / e/ a/t" --> "r/g / e/ a/t" //
 * 随机决定：「保持这两个子字符串的顺序不变」 算法终止，结果字符串和 s2
 * 相同，都是 "rgeat" 这是一种能够扰乱 s1 得到 s2 的情形，可以认为 s2 是 s1
 * 的扰乱字符串，返回 true
 *
 *
 * 示例 2：
 *
 * 输入：s1 = "abcde", s2 = "caebd"
 * 输出：false
 *
 *
 * 示例 3：
 *
 * 输入：s1 = "a", s2 = "a"
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * s1.length == s2.length
 * 1 <= s1.length <= 30
 * s1 和 s2 由小写英文字母组成
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
  // unordered_map<string, bool> memo;

  // bool isScramble(string s1, string s2) {
  //   string k = s1 + "_" + s2;
  //   if (memo[k]) return memo[k];

  //   if (s1 == s2) return memo[k] = true;
  //   if (s1.length() != s2.length()) return memo[k] = false;

  //   string t1 = s1, t2 = s2;
  //   sort(t1.begin(), t1.end());
  //   sort(t2.begin(), t2.end());
  //   if (t1 != t2) return memo[k] = false;

  //   int n = s1.length();

  //   for (int i = 1; i < n; ++i) {
  //     if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
  //         isScramble(s1.substr(i), s2.substr(i))) {
  //       return memo[k] = true;
  //     }
  //     if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
  //         isScramble(s1.substr(i), s2.substr(0, n - i))) {
  //       return memo[k] = true;
  //     }
  //   }
  //   return memo[k] = false;
  // }
  bool isScramble(string s1, string s2) {
    int n = s1.length();
    if (n != s2.length()) return false;
    if (s1 == s2) return true;

    // dp[len][i][j] 表示 s1 从 i 开始、s2 从 j 开始
    // 长度为 len 的子串是否是扰乱字符串
    vector<vector<vector<bool>>> dp(
        n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[1][i][j] = s1[i] == s2[j];
      }
    }

    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        for (int j = 0; j <= n - len; ++j) {
          for (int k = 1; k < len; ++k) {
            if (dp[k][i][j] && dp[len - k][i + k][j + k]) {
              dp[len][i][j] = true;
              break;
            }
            if (dp[k][i][j + len - k] && dp[len - k][i + k][j]) {
              dp[len][i][j] = true;
              break;
            }
          }
        }
      }
    }
    return dp[n][0][0];
  }
};

// @lc code=end

/*
// @lcpr case=start
// "great"\n"rgeat"\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n"caebd"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

 */
