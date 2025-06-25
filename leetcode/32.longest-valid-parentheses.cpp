/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30204
 *
 * [32] 最长有效括号
 *
 * https://leetcode.cn/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (39.52%)
 * Likes:    2693
 * Dislikes: 0
 * Total Accepted:    561K
 * Total Submissions: 1.4M
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和
 * ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 *
 *
 * 示例 2：
 *
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 *
 *
 * 示例 3：
 *
 * 输入：s = ""
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 3 * 10^4
 * s[i] 为 '(' 或 ')'
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
  int longestValidParentheses(string s) {
    int res = 0, start = 0;
    stack<int> st;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        st.push(i);
      else if (s[i] == ')') {
        if (st.empty()) {
          start = i + 1;
        } else {
          st.pop();
          //使用top的原因，匹配到之前没匹配完的位置涵盖中间的信息
          res = st.empty() ? max(res, i - start + 1) : max(res, i - st.top());
        }
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */
