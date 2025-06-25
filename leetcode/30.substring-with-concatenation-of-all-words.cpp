/*
 * @lc app=leetcode.cn id=30 lang=cpp
 * @lcpr version=30204
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (38.15%)
 * Likes:    1216
 * Dislikes: 0
 * Total Accepted:    251.3K
 * Total Submissions: 659.1K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。
 *
 * s 中的 串联子串
 * 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。
 *
 *
 * 例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"，
 * "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef"
 * 不是串联子串，因为他不是任何 words 排列的连接。
 *
 *
 * 返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "barfoothefoobarman", words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：因为 words.length == 2 同时 words[i].length ==
 * 3，连接的子字符串的长度必须为 6。 子串 "barfoo" 开始位置是 0。它是 words 中以
 * ["bar","foo"] 顺序排列的连接。 子串 "foobar" 开始位置是 9。它是 words 中以
 * ["foo","bar"] 顺序排列的连接。 输出顺序无关紧要。返回 [9,0] 也是可以的。
 *
 *
 * 示例 2：
 *
 * 输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * 输出：[]
 * 解释：因为 words.length == 4 并且 words[i].length ==
 * 4，所以串联子串的长度必须为 16。 s 中没有子串长度为 16 并且等于 words
 * 的任何顺序排列的连接。 所以我们返回一个空数组。
 *
 *
 * 示例 3：
 *
 * 输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * 输出：[6,9,12]
 * 解释：因为 words.length == 3 并且 words[i].length ==
 * 3，所以串联子串的长度必须为 9。 子串 "foobarthe" 开始位置是 6。它是 words
 * 中以 ["foo","bar","the"] 顺序排列的连接。 子串 "barthefoo" 开始位置是 9。它是
 * words 中以 ["bar","the","foo"] 顺序排列的连接。 子串 "thefoobar" 开始位置是
 * 12。它是 words 中以 ["the","foo","bar"] 顺序排列的连接。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * words[i] 和 s 由小写英文字母组成
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
#include <map>
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
  //超时
  //   vector<int> findSubstring(string s, vector<string>& words) {
  //     vector<string> dic;
  //     vector<int> res;
  //     generate(words, dic, "");
  //     // for (auto it = dic.begin(); it != dic.end(); ++it) {
  //     //   cout << *it << " ";
  //     // }
  //     // cout << endl;
  //     if (s.size() < words.size()) return res;
  //     for (int i = 0; i < s.size(); ++i) {
  //       string sss = s.substr(i, words.size() * words[0].size());
  //       if (find(dic.begin(), dic.end(), sss) != dic.end()) res.push_back(i);
  //     }

  //     return res;
  //   }
  //   void generate(vector<string> words, vector<string>& ss, string tmp) {
  //     if (words.empty()) {
  //       ss.push_back(tmp);
  //     }
  //     for (int i = 0; i < words.size(); ++i) {
  //       auto t = words;
  //       t.erase(t.begin() + i);
  //       generate(t, ss, tmp + words[i]);
  //     }
  //   }
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    unordered_map<string, int> word_cnt;
    for (auto& w : words) ++word_cnt[w];
    int n = words.size(), l = words[0].length();
    int slen = s.size(), len = n * l;
    vector<unordered_map<std::string, int>> m(l);
    // // 维护l长度的m的unorodermap，再在这个m中删除和增加最前最后的word来判断
    for (int i = 0; i < l && i + len <= slen; ++i) {
      for (int j = i; j < i + len; j += l) {
        string ss = s.substr(j, l);
        m[i][ss]++;
      }
      if (m[i] == word_cnt) res.push_back(i);
    }
    for (int i = l; i + len <= slen; ++i) {  //长度而不是下标所以=
      int r = i % l;
      string del = s.substr(i - l, l);
      string add = s.substr(i + len - l, l);
      if (!--m[r][del]) m[r].erase(del);
      ++m[r][add];
      if (m[r] == word_cnt) res.push_back(i);
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "barfoothefoobarman"\n["foo","bar"]\n
// @lcpr case=end

// @lcpr case=start
// "wordgoodgoodgoodbestword"\n["word","good","best","word"]\n
// @lcpr case=end

// @lcpr case=start
// "barfoofoobarthefoobarman"\n["bar","foo","the"]\n
// @lcpr case=end

 */
