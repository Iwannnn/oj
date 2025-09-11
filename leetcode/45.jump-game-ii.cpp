/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30204
 *
 * [45] 跳跃游戏 II
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
  int jump(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 9999999);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= nums[i] && i + j < n; ++j) {
        dp[i + j] = min(dp[i + j], dp[i] + 1);
      }
    }
    return dp[n - 1];
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */
