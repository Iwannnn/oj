/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30204
 *
 * [40] 组合总和 II
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
  vector<vector<int>> combinationSum2(vector<int> &p, int x) {
    vector<vector<int>> res;
    sort(p.begin(), p.end());
    f(res, p, {}, x, 0);
    sort(res.begin(), res.end());
    auto last = unique(res.begin(), res.end());
    res.erase(last, res.end());
    return res;
  }

  void f(vector<vector<int>> &res, vector<int> &p, vector<int> cur, int x,
         int s) {
    if (x == 0) {
      res.push_back(cur);
      return;
    }
    if (x < 0)
      return;
    for (int i = s; i < p.size(); ++i) {
      if (x - p[i] < 0)
        break;
      if (i > s && p[i] == p[i - 1])
        continue;
      cur.push_back(p[i]);
      f(res, p, cur, x - p[i], i + 1);
      cur.pop_back();
    }
  }
};
// @lc code=end

/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */
