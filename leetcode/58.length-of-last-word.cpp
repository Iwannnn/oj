/*
 * @lc app=leetcode.cn id=58 lang=cpp
 * @lcpr version=30204
 *
 * [58] 最后一个单词的长度
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
  int lengthOfLastWord(string s) {
    int st = 0;
    int res = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] != ' ') {
        ++res;
        st = 1;
      }
      if (st == 1 && s[i] == ' ') {
        return res;
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "Hello World"\n
// @lcpr case=end

// @lcpr case=start
// "   fly me   to   the moon  "\n
// @lcpr case=end

// @lcpr case=start
// "luffy is still joyboy"\n
// @lcpr case=end

 */
