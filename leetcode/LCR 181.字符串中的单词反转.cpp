/*
 * @lc app=leetcode.cn id=LCR 181 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 181] 字符串中的单词反转
 *
 * https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/description/
 *
 * algorithms
 * Easy (45.04%)
 * Likes:    345
 * Dislikes: 0
 * Total Accepted:    289.6K
 * Total Submissions: 642.3K
 * Testcase Example:  '"the sky is blue"'
 *
 * 你在与一位习惯从右往左阅读的朋友发消息，他发出的文字顺序都与正常相反但单词内容正确，为了和他顺利交流你决定写一个转换程序，把他所发的消息
 * message 转换为正常语序。
 *
 * 注意：输入字符串 message
 * 中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 *
 *
 *
 * 示例 1：
 *
 * 输入: message = "the sky is blue"
 * 输出: "blue is sky the"
 *
 *
 * 示例 2：
 *
 * 输入: message = "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 *
 *
 * 示例 3：
 *
 * 输入: message = "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= message.length <= 10^4
 * message 中包含英文大小写字母、空格和数字
 *
 *
 * 注意：
 *
 *
 * 本题与主站 151
 * 题相同：https://leetcode-cn.com/problems/reverse-words-in-a-string/
 *
 *
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
#include <sstream>
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
  // string reverseMessage(string message) {
  //   if (message == "") return "";
  //   vector<string> res;
  //   string res_s = "";
  //   int i = 0, n = message.size();
  //   while (i < n) {
  //     if (message[i] == ' ') {
  //       ++i;
  //       continue;
  //     }
  //     string tmp = "";
  //     while (message[i] != ' ' && i < n) {
  //       tmp += message[i];
  //       ++i;
  //     }
  //     cout << tmp << endl;
  //     ++i;
  //     if (tmp != "") res.push_back(tmp);
  //   }

  //   if (res.empty()) return "";
  //   for (int i = res.size() - 1; i > 0; --i) res_s += res[i] + ' ';
  //   res_s += res[0];

  //   return res_s;
  // }

  string reverseMessage(string message) {
    istringstream iss(message);
    vector<string> words;
    string tmp;
    while (iss >> tmp) words.push_back(tmp);

    if (words.empty()) return "";

    ostringstream oss;
    for (size_t i = words.size(); i-- > 0;) {
      oss << words[i];
      if (i != 0) oss << ' ';
    }

    return oss.str();
  }
};
// @lc code=end

/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world!  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */
