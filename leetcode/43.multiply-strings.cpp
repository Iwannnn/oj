/*
 * @lc app=leetcode.cn id=43 lang=cpp
 * @lcpr version=30204
 *
 * [43] 字符串相乘
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
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";
    vector<int> res(num1.size() + num2.size(), 0);
    string ress = "";
    for (int i = num1.size() - 1; i >= 0; --i) {
      for (int j = num2.size() - 1; j >= 0; --j) {
        int a = num1[i] - '0', b = num2[j] - '0';
        int m = a * b;
        int c = i + j, d = i + j + 1;
        int sum = m + res[d];
        res[d] = sum % 10;
        res[c] += sum / 10;
      }
    }
    for (auto n : res) {
      if (ress.empty() && n == 0)
        continue;
      ress += (n + '0');
    }

    return ress;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "2"\n"3"\n
// @lcpr case=end

// @lcpr case=start
// "123"\n"456"\n
// @lcpr case=end

 */
