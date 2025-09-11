/*
 * @lc app=leetcode.cn id=LCR 132 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 132] 砍竹子 II
 *
 * https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/description/
 *
 * algorithms
 * Medium (31.27%)
 * Likes:    271
 * Dislikes: 0
 * Total Accepted:    163.1K
 * Total Submissions: 521.5K
 * Testcase Example:  '12'
 *
 * 现需要将一根长为正整数 bamboo_len 的竹子砍为若干段，每段长度均为
 * 正整数。请返回每段竹子长度的 最大乘积 是多少。
 *
 * 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 *
 *
 *
 * 示例 1：
 *
 * 输入：bamboo_len = 12
 * 输出：81
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= bamboo_len <= 1000
 *
 *
 * 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/
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
  int cuttingBamboo(int n) {
    if (n < 4) return n - 1;
    long res = 1;
    if (n % 3 == 1) {
      res = 4;
      n -= 4;
    }
    if (n % 3 == 2) {
      res = 2;
      n -= 2;
    }
    while (n) {
      res = res * 3 % (1000000007);
      n -= 3;
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 12\n
// @lcpr case=end

 */
