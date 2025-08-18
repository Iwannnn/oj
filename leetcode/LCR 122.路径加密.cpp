/*
 * @lc app=leetcode.cn id=LCR 122 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 122] 路径加密
 *
 * https://leetcode.cn/problems/ti-huan-kong-ge-lcof/description/
 *
 * algorithms
 * Easy (74.91%)
 * Likes:    586
 * Dislikes: 0
 * Total Accepted:    757.4K
 * Total Submissions: 1M
 * Testcase Example:  '"a.aef.qerf.bb"'
 *
 * 假定一段路径记作字符串 path，其中以 "."
 * 作为分隔符。现需将路径加密，加密方法为将 path 中的分隔符替换为空格 "
 * "，请返回加密后的字符串。
 *
 *
 *
 * 示例 1：
 *
 * 输入：path = "a.aef.qerf.bb"
 *
 * 输出："a aef qerf bb"
 *
 *
 *
 *
 *
 * 限制：
 *
 * 0 <= path.length <= 10000
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
  string pathEncryption(string path) {
    string res;
    for (auto c : path) {
      if (c == '.')
        res += ' ';
      else
        res += c;
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "a.aef.qerf.bb"\n
// @lcpr case=end

 */
