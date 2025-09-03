/*
 * @lc app=leetcode.cn id=LCR 164 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 164] 破解闯关密码
 *
 * https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/description/
 *
 * algorithms
 * Medium (54.77%)
 * Likes:    699
 * Dislikes: 0
 * Total Accepted:    249.1K
 * Total Submissions: 454.8K
 * Testcase Example:  '[15,8,7]'
 *
 * 闯关游戏需要破解一组密码，闯关组给出的有关密码的线索是：
 *
 *
 * 一个拥有密码所有元素的非负整数数组 password
 * 密码是 password 中所有元素拼接后得到的最小的一个数
 *
 *
 * 请编写一个程序返回这个密码。
 *
 *
 *
 * 示例 1：
 *
 * 输入：password = [15, 8, 7]
 * 输出："1578"
 *
 * 示例 2：
 *
 * 输入：password = [0, 3, 30, 34, 5, 9]
 * 输出："03033459"
 *
 *
 *
 * 提示：
 *
 *
 * 0 < password.length <= 100
 *
 *
 * 说明:
 *
 *
 * 输出结果可能非常大，所以你需要返回一个字符串而不是整数
 * 拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
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
#include <stack>
#include <string>
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
  string crackPassword(vector<int> &password) {
    vector<string> ss;
    string res;

    for (auto p : password) ss.push_back(to_string(p));

    sort(ss.begin(), ss.end(),
         [](const string &s1, const string &s2) { return s1 + s2 < s2 + s1; });

    for (auto s : ss) res += s;

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [15, 8, 7]\n
// @lcpr case=end

// @lcpr case=start
// [0, 3, 30, 34, 5, 9]\n
// @lcpr case=end

 */
