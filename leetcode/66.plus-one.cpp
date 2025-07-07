/*
 * @lc app=leetcode.cn id=66 lang=cpp
 * @lcpr version=30204
 *
 * [66] 加一
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
  vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();
    int c = 1;
    for (int i = n - 1; i >= 0; --i) {
      if (c) {
        digits[i] += 1;
        c = digits[i] / 10;
        digits[i] %= 10;
      }
    }
    if (c)
      digits.insert(digits.begin(), 1);
    return digits;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [9]\n
// @lcpr case=end

 */
