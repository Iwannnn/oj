/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=30204
 *
 * [49] 字母异位词分组
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
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<int>> m;
    vector<vector<string>> res;

    for (int i = 0; i < strs.size(); ++i) {
      string t = strs[i];
      sort(t.begin(), t.end());
      m[t].push_back(i);
    }

    for (auto mm : m) {
      vector<string> tmp;
      for (auto i : mm.second) {
        tmp.push_back(strs[i]);
      }
      res.push_back(tmp);
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */
