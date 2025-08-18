/*
 * @lc app=leetcode.cn id=LCR 131 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 131] 砍竹子 I
 *
 * https://leetcode.cn/problems/jian-sheng-zi-lcof/description/
 *
 * algorithms
 * Medium (57.36%)
 * Likes:    633
 * Dislikes: 0
 * Total Accepted:    311.5K
 * Total Submissions: 543.1K
 * Testcase Example:  '12'
 *
 * 现需要将一根长为正整数 bamboo_len
 * 的竹子砍为若干段，每段长度均为正整数。请返回每段竹子长度的最大乘积是多少。
 *
 *
 *
 * 示例 1：
 *
 * 输入: bamboo_len = 12
 * 输出: 81
 *
 * 提示：
 *
 *
 * 2 <= bamboo_len <= 58
 *
 *
 * 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/
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
    if (n == 2) return 1;
    if (n == 3) return 2;

    int res = 1;
    while (n > 4) {
      res *= 3;
      n -= 3;
    }
    return res * n;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 12\n
// @lcpr case=end

 */
