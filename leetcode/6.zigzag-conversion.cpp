/*
 * @lc app=leetcode.cn id=6 lang=cpp
 * @lcpr version=30204
 *
 * [6] Z 字形变换
 *
 * https://leetcode.cn/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (53.59%)
 * Likes:    2453
 * Dislikes: 0
 * Total Accepted:    764.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z
 * 字形排列。
 *
 * 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
 *
 * 请你实现这个将字符串进行指定行数变换的函数：
 *
 * string convert(string s, int numRows);
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "PAYPALISHIRING", numRows = 3
 * 输出："PAHNAPLSIIGYIR"
 *
 * 示例 2：
 *
 * 输入：s = "PAYPALISHIRING", numRows = 4
 * 输出："PINALSIGYAHRPI"
 * 解释：
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 *
 * 示例 3：
 *
 * 输入：s = "A", numRows = 1
 * 输出："A"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 由英文字母（小写和大写）、',' 和 '.' 组成
 * 1 <= numRows <= 1000
 *
 *
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
  // string convert(string s, int numRows) {
  //   if (numRows <= 1) return s;
  //   string res = "";
  //   vector<string> ss(numRows, "");
  //   int row = 0, flag = 1;  // flag为1row++ 为0row--
  //   for (int i = 0; i < s.size(); ++i) {
  //     ss[row] += s[i];
  //     if (flag) {
  //       row++;
  //       if (row == numRows - 1) flag = 0;
  //     } else {
  //       row--;
  //       if (row == 0) flag = 1;
  //     }
  //   }
  //   for (int i = 0; i < numRows; ++i) {
  //     cout << ss[i] << endl;
  //     res += ss[i];
  //   }
  //   return res;
  // }
  string convert(string s, int numRows) {
    if (numRows <= 1) return s;
    string res;
    int ss = 2 * numRows - 2;
    int n = s.size();
    for (int i = 0; i < numRows; ++i) {
      for (int j = i; j < n; j += ss) {
        res += s[j];
        int next = j + ss - 2 * i;
        if (i != 0 && i != numRows - 1 && next < n) res += s[next];
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "PAYPALISHIRING"\n3\n
// @lcpr case=end

// @lcpr case=start
// "PAYPALISHIRING"\n4\n
// @lcpr case=end

// @lcpr case=start
// "A"\n1\n
// @lcpr case=end

 */
