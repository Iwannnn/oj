/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=30204
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode.cn/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (61.51%)
 * Likes:    1526
 * Dislikes: 0
 * Total Accepted:    525.3K
 * Total Submissions: 852.7K
 * Testcase Example:  '"25525511135"'
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导
 * 0），整数之间用 '.' 分隔。
 *
 *
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是
 * "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
 *
 *
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP
 * 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s
 * 中的任何数字。你可以按 任何 顺序返回答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 *
 *
 * 示例 2：
 *
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 *
 *
 * 示例 3：
 *
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 20
 * s 仅由数字组成
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
#include <string>
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
  vector<string> restoreIpAddresses(string s) {
    if (s.size() > 12) return {};
    vector<string> res;
    restore(s, 4, "", res);
    return res;
  }
  void restore(string s, int n, string out, vector<string>& res) {
    if (n == 0 && s.empty()) res.push_back(out);
    for (int i = 1; i <= 3; ++i) {  //位数
      if (s.size() >= i && isValid(s.substr(0, i))) {
        if (n == 1) {  //最后的
          restore(s.substr(i), n - 1, out + s.substr(0, i), res);
        } else {
          restore(s.substr(i), n - 1, out + s.substr(0, i) + ".", res);
        }
      }
    }
  }
  bool isValid(string s) {
    if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0'))
      return false;
    int num = stoi(s);
    return num <= 255 && num >= 0;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */
