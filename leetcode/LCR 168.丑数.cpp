/*
 * @lc app=leetcode.cn id=LCR 168 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 168] 丑数
 *
 * https://leetcode.cn/problems/chou-shu-lcof/description/
 *
 * algorithms
 * Medium (64.08%)
 * Likes:    514
 * Dislikes: 0
 * Total Accepted:    183.3K
 * Total Submissions: 286.2K
 * Testcase Example:  '10'
 *
 * 给你一个整数 n ，请你找出并返回第 n 个 丑数 。
 *
 * 说明：丑数是只包含质因数 2、3 和/或 5 的正整数；1 是丑数。
 *
 *
 *
 * 示例 1：
 *
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 *
 * 提示： 
 *
 *
 * 1 <= n <= 1690
 *
 *
 *
 *
 * 注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/
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
  int nthUglyNumber(int n) {
    int res[n];
    int p2 = 0, p3 = 0, p5 = 0;
    res[0] = 1;
    for (int i = 1; i < n; ++i) {
      int ne2 = res[p2] * 2;
      int ne3 = res[p3] * 3;
      int ne5 = res[p5] * 5;
      res[i] = min(ne2, min(ne3, ne5));
      if (res[i] == ne2) ++p2;
      if (res[i] == ne3) ++p3;
      if (res[i] == ne5) ++p5;
    }
    return res[n - 1];
  }
};
// @lc code=end

/*
// @lcpr case=start
// 10\n
// @lcpr case=end

 */
