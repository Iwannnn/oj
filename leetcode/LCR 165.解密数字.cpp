/*
 * @lc app=leetcode.cn id=LCR 165 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 165] 解密数字
 *
 * https://leetcode.cn/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/description/
 *
 * algorithms
 * Medium (51.09%)
 * Likes:    623
 * Dislikes: 0
 * Total Accepted:    271.9K
 * Total Submissions: 532.2K
 * Testcase Example:  '216612'
 *
 * 现有一串神秘的密文 ciphertext，经调查，密文的特点和规则如下：
 *
 *
 * 密文由非负整数组成
 * 数字 0-25 分别对应字母 a-z
 *
 *
 * 请根据上述规则将密文 ciphertext 解密为字母，并返回共有多少种解密结果。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：ciphertext = 216612
 * 输出：6
 * 解释：216612 解密后有 6 种不同的形式，分别是
 * "cbggbc"，"vggbc"，"vggm"，"cbggm"，"cqgbc" 和 "cqgm"
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= ciphertext < 2^31
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
  int crackNumber(int ciphertext) {
    string s = to_string(ciphertext);
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      string ss = s.substr(i - 2, 2);
      int si = stoi(ss);
      if (si >= 10 && si <= 25)
        dp[i] = dp[i - 1] + dp[i - 2];
      else
        dp[i] = dp[i - 1];
    }

    return dp[n];
  }
};
// @lc code=end

/*
// @lcpr case=start
// 216612\n
// @lcpr case=end

 */
