/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30204
 *
 * [70] 爬楼梯
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
  int climbStairs(int n) {
    int f[46] = {0};
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; ++i)
      f[i] = f[i - 1] + f[i - 2];
    return f[n];
  }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
