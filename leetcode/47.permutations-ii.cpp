/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30204
 *
 * [47] 全排列 II
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
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    s(res, nums, {});
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
  }

  void s(vector<vector<int>> &res, vector<int> &nums, vector<int> cur) {
    if (nums.size() == 0) {
      res.push_back(cur);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      int t = nums[i];
      cur.push_back(nums[i]);
      nums.erase(nums.begin() + i);
      s(res, nums, cur);
      nums.insert(nums.begin() + i, t);
      cur.pop_back();
    }
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
