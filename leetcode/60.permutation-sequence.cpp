/*
 * @lc app=leetcode.cn id=60 lang=cpp
 * @lcpr version=30204
 *
 * [60] 排列序列
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
  string getPermutation(int n, int k) {
    string res;
    string nums = "123456789";
    vector<int> f(n, 1);
    for (int i = 2; i < n; ++i)
      f[i] = f[i - 1] * i;
    --k;
    for (int i = n; i >= 1; --i) {
      int idx = k / f[i - 1];
      k %= f[i - 1];
      res.push_back(nums[idx]);
      nums.erase(idx, 1);
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n3\n
// @lcpr case=end

// @lcpr case=start
// 4\n9\n
// @lcpr case=end

// @lcpr case=start
// 3\n1\n
// @lcpr case=end

 */
