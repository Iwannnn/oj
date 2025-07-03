/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30204
 *
 * [56] 合并区间
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
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size();) {
      int t = intervals[i][1];
      int j = i + 1;
      while (j < intervals.size() && intervals[j][0] <= t) {
        t = max(t, intervals[j][1]);
        j++;
      }
      res.push_back({intervals[i][0], t});
      i = j;
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */
