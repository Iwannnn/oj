/*
 * @lc app=leetcode.cn id=LCR 138 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 138] 有效数字
 *
 * https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/description/
 *
 * algorithms
 * Medium (24.83%)
 * Likes:    568
 * Dislikes: 0
 * Total Accepted:    162.1K
 * Total Submissions: 652.9K
 * Testcase Example:  '"0"'
 *
 * 有效数字（按顺序）可以分成以下几个部分：
 *
 *
 * 若干空格
 * 一个 小数 或者 整数
 * （可选）一个 'e' 或 'E' ，后面跟着一个 整数
 * 若干空格
 *
 *
 * 小数（按顺序）可以分成以下几个部分：
 *
 *
 * （可选）一个符号字符（'+' 或 '-'）
 * 下述格式之一：
 *
 * 至少一位数字，后面跟着一个点 '.'
 * 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
 * 一个点 '.' ，后面跟着至少一位数字
 *
 *
 *
 *
 * 整数（按顺序）可以分成以下几个部分：
 *
 *
 * （可选）一个符号字符（'+' 或 '-'）
 * 至少一位数字
 *
 *
 * 部分有效数字列举如下：["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10",
 * "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
 *
 * 部分无效数字列举如下：["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3",
 * "95a54e53"]
 *
 * 给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "0"
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：s = "e"
 * 输出：false
 *
 *
 * 示例 3：
 *
 * 输入：s = "."
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 20
 * s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，空格 ' '
 * 或者点 '.' 。
 *
 *
 *
 *
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
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
  bool validNumber(string s) {
    int n = s.length(), l = 0, r = n - 1;
    while (l < n && s[l] == ' ') ++l;
    while (r > 0 && s[r] == ' ') --r;
    if (l > r) return false;
    s = s.substr(l, r - l + 1);

    for (char &c : s) {
      if (c == 'e') c = 'E';
    }

    n = s.length();
    int idx = 0;
    while (idx < n && s[idx] != 'E') idx++;
    if (idx == n) return check(s, true);

    return check(s.substr(0, idx), true) && check(s.substr(idx + 1), false);
  }

  bool check(string s, bool isDecimal) {
    if (s == "." || s == "") return false;
    int n = s.length();
    for (int i = 0, cnt = 0; i < n; ++i) {
      char c = s[i];
      if (c == '+' || c == '-') {
        if (i != 0 || i == n - 1) return false;
      } else if (c == '.') {
        if (!isDecimal) return false;
        if (cnt != 0) return false;
        bool a = i - 1 >= 0 && isdigit(s[i - 1]);
        bool b = i + 1 < n && isdigit(s[i + 1]);
        if (!(a || b)) return false;
        ++cnt;
      } else if (!isdigit(c))
        return false;
    }
    return true;
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
