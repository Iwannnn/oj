/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30204
 *
 * [46] 全排列
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
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    s(nums, res, {});
    return res;
  }

  void s(vector<int> &nums, vector<vector<int>> &res, vector<int> tmp) {
    if (tmp.size() == nums.size()) {
      res.push_back(tmp);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (find(tmp.begin(), tmp.end(), nums[i]) == tmp.end()) {
        tmp.push_back(nums[i]);
        s(nums, res, tmp);
        tmp.pop_back();
      }
    }
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
