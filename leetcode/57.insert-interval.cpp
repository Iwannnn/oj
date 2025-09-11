/*
 * @lc app=leetcode.cn id=57 lang=cpp
 * @lcpr version=30204
 *
 * [57] 插入区间
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
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {

    vector<vector<int>> res;
    int cur = 0;
    for (int i = 0; i < intervals.size(); ++i) {
      if (intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        ++cur;
      } else if (intervals[i][0] > newInterval[1]) {
        res.push_back(intervals[i]);
      } else {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
      }
    }
    res.insert(res.begin() + cur, newInterval);
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[6,9]]\n[2,5]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,5],[6,7],[8,10],[12,16]]\n[4,8]\n
// @lcpr case=end

 */
