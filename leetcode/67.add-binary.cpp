/*
 * @lc app=leetcode.cn id=67 lang=cpp
 * @lcpr version=30204
 *
 * [67] 二进制求和
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
  string addBinary(string a, string b) {
    int la = a.size() - 1, lb = b.size() - 1;
    int c = 0;
    string res = "";
    while (la >= 0 && lb >= 0) {
      int t = a[la] - '0' + b[lb] - '0' + c;
      c = t / 2;
      res.insert(res.begin(), t % 2 + '0');
      --la;
      --lb;
    }
    while (la >= 0) {
      int t = a[la] - '0' + c;
      c = t / 2;
      res.insert(res.begin(), t % 2 + '0');
      --la;
    }
    while (lb >= 0) {
      int t = b[lb] - '0' + c;
      c = t / 2;
      res.insert(res.begin(), t % 2 + '0');
      --lb;
    }
    if (c)
      res.insert(res.begin(), c + '0');
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "11"\n"1"\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n"1011"\n
// @lcpr case=end

 */
