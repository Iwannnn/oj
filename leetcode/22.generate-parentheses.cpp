/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30204
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (78.71%)
 * Likes:    3818
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.3M
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且
 * 有效的 括号组合。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 *
 *
 * 示例 2：
 *
 * 输入：n = 1
 * 输出：["()"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 8
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
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    stack<string> ss;
    string o = "";
    dfs(res, o, 0, n, ss);
    return res;
  }
  void dfs(vector<string>& res, string out, int level, int n,
           stack<string> ss) {
    if (level == n) {
      while (!ss.empty()) {
        out += ")";
        ss.pop();
      }
      res.push_back(out);
      return;
    }
    ss.push("(");
    dfs(res, out + "(", level + 1, n, ss);
    ss.pop();
    if (!ss.empty()) {
      ss.pop();
      dfs(res, out + ")", level, n, ss);
    }
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
