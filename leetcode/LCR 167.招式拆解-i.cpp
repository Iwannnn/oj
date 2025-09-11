/*
 * @lc app=leetcode.cn id=LCR 167 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 167] 招式拆解 I
 *
 * https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/description/
 *
 * algorithms
 * Medium (46.03%)
 * Likes:    630
 * Dislikes: 0
 * Total Accepted:    327.9K
 * Total Submissions: 712.3K
 * Testcase Example:  '"dbascDdad"'
 *
 * 某套连招动作记作序列 arr，其中 arr[i] 为第 i 个招式的名字。请返回 arr
 * 中最多可以出连续不重复的多少个招式。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = "dbascDdad"
 * 输出：6
 * 解释：因为连续且最长的招式序列是 "dbascD" 或 "bascDd"，所以其长度为 6。
 *
 *
 * 示例 2：
 *
 * 输入：arr = "KKK"
 * 输出：1
 * 解释：因为无重复字符的最长子串是 "K"，所以其长度为 1。
 *
 *
 * 示例 3：
 *
 * 输入：arr = "pwwkew"
 * 输出：3
 * 解释：因为连续且最长的招式序列是 "wke"，所以其长度为 3。 
 * 请注意区分 子串 与 子序列 的概念：你的答案必须是 连续招式 的长度，也就是
 * 子串。而 "pwke" 是一个非连续的 子序列，不是 子串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= arr.length <= 40000
 * arr 由英文字母、数字、符号和空格组成。
 *
 *
 *
 *
 * 注意：本题与主站 3
 * 题相同：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
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
  int dismantlingAction(string arr) {
    if (arr.size() < 2) return arr.size();
    unordered_map<char, int> ma;
    int i = -1, res = 0, len = arr.size();

    for (int j = 0; j < len; ++j) {
      if (ma.find(arr[j]) != ma.end()) {
        i = max(i, ma.find(arr[j])->second);
      }
      ma[arr[j]] = j;
      res = max(res, j - i);
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "dbascDdad"\n
// @lcpr case=end

// @lcpr case=start
// "KKK"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
