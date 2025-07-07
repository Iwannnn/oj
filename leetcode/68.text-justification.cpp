/*
 * @lc app=leetcode.cn id=68 lang=cpp
 * @lcpr version=30204
 *
 * [68] 文本左右对齐
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
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> res;
    int n = words.size();
    int end = 0;

    while (end < n) {
      int start = end;
      int tt = 0;

      while (end < n && tt + words[end].length() + (end - start) <= maxWidth) {
        tt += words[end].length();
        end++;
      }

      if (end == n || end - start == 1) {
        string line = words[start];
        for (int j = start + 1; j < end; ++j) {
          line += " " + words[j];
        }
        line += string(maxWidth - line.length(), ' ');
        res.push_back(line);
      } else {
        int space = (maxWidth - tt) / (end - start - 1);
        int extra = (maxWidth - tt) % (end - start - 1);
        string line = words[start];
        for (int j = start + 1; j < end; ++j) {
          string s(space + ((j - start <= extra) ? 1 : 0), ' ');
          line += s + words[j];
        }
        res.push_back(line);
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// ["This", "is", "an", "example", "of", "text", "justification."]\n16\n
// @lcpr case=end

// @lcpr case=start
// ["What","must","be","acknowledgment","shall","be"]\n16\n
// @lcpr case=end

// @lcpr case=start
//
["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we"\n20\n
// @lcpr case=end

 */
