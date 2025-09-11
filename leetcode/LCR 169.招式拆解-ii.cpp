/*
 * @lc app=leetcode.cn id=LCR 169 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 169] 招式拆解 II
 *
 * https://leetcode.cn/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/description/
 *
 * algorithms
 * Easy (61.87%)
 * Likes:    367
 * Dislikes: 0
 * Total Accepted:    347.8K
 * Total Submissions: 562.2K
 * Testcase Example:  '"abbccdeff"'
 *
 * 某套连招动作记作仅由小写字母组成的序列 arr，其中 arr[i] 第 i
 * 个招式的名字。请返回第一个只出现一次的招式名称，如不存在请返回空格。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = "abbccdeff"
 * 输出：'a'
 *
 *
 * 示例 2：
 *
 * 输入：arr = "ccdd"
 * 输出：' '
 *
 *
 *
 *
 * 限制：
 *
 * 0 <= arr.length <= 50000
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
  char dismantlingAction(string arr) {
    unordered_map<char, bool> ma;
    // 记录每个c是否是出现
    for (auto c : arr) ma[c] = ma.find(c) == ma.end();
    for (auto c : arr)
      if (ma[c]) return c;
    return ' ';
  }
};
// @lc code=end

/*
// @lcpr case=start
// "abbccdeff"\n
// @lcpr case=end

// @lcpr case=start
// "ccdd"\n
// @lcpr case=end

 */
