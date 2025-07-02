/*
 * @lc app=leetcode.cn id=50 lang=cpp
 * @lcpr version=30204
 *
 * [50] Pow(x, n)
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
#include <map>
#include <queue>
#include <set>
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
    if (n == 0)
      return 1;
    if (n == 1)
      return x;
    if (x == 1)
      return 1;
    if (x == -1)
      return n % 2 == 0 ? 1 : -1;

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
