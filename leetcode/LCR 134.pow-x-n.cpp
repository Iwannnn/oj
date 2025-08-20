/*
 * @lc app=leetcode.cn id=LCR 134 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 134] Pow(x, n)
 *
 * https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/description/
 *
 * algorithms
 * Medium (35.22%)
 * Likes:    444
 * Dislikes: 0
 * Total Accepted:    257.8K
 * Total Submissions: 731.5K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n）。
 *
 *
 *
 * 示例 1：
 *
 * 输入：x = 2.00000, n = 10
 * 输出：1024.00000
 *
 *
 * 示例 2：
 *
 * 输入：x = 2.10000, n = 3
 * 输出：9.26100
 *
 * 示例 3：
 *
 * 输入：x = 2.00000, n = -2
 * 输出：0.25000
 * 解释：2^-2 = 1/2^2 = 1/4 = 0.25
 *
 *
 *
 * 提示：
 *
 *
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * -10^4 <= x^n <= 10^4
 *
 *
 *
 *
 * 注意：本题与主站 50 题相同：https://leetcode-cn.com/problems/powx-n/
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
  double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    if (x == 1) return 1;
    if (x == -1) return n % 2 == 0 ? 1 : -1;

    if (n < 0 && n > -2147483648) {
      n = -n;
      x = 1 / x;
    }

    double res = myPow(x, n / 2);
    if (n % 2 == 0)
      return res * res;
    else
      return res * res * x;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 2.00000\n10\n
// @lcpr case=end

// @lcpr case=start
// 2.10000\n3\n
// @lcpr case=end

// @lcpr case=start
// 2.00000\n-2\n
// @lcpr case=end

 */
