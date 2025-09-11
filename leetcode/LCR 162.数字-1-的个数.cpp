/*
 * @lc app=leetcode.cn id=LCR 162 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 162] 数字 1 的个数
 *
 * https://leetcode.cn/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/description/
 *
 * algorithms
 * Hard (50.37%)
 * Likes:    473
 * Dislikes: 0
 * Total Accepted:    97.8K
 * Total Submissions: 194.2K
 * Testcase Example:  '0'
 *
 * 给定一个整数 num，计算所有小于等于 num 的非负整数中数字 1 出现的个数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：num = 0
 * 输出：0
 *
 *
 * 示例 2：
 *
 * 输入：num = 13
 * 输出：6
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= num < 10^9
 *
 *
 * 注意：本题与主站 233
 * 题相同：https://leetcode-cn.com/problems/number-of-digit-one/
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
  int digitOneInNumber(int num) {
    long long factor = 1;
    int res = 0;
    while (num / factor > 0) {
      long long high = num / (factor * 10);
      long long cur = (num / factor) % 10;
      long long low = num % factor;

      //比num小
      if (cur == 0)  // 只有高位能出现1了 本位不会出现1
        res += (high * factor);
      else if (cur == 1)  // 本位出现一次1 但不能满足这次全部factor 为0-low
        res += (high * factor + (low + 1));
      else
        res += (high * factor + factor);  // 全部的factor

      factor *= 10;
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */
