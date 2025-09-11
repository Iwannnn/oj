/*
 * @lc app=leetcode.cn id=LCR 120 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 120] 寻找文件副本
 *
 * https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/description/
 *
 * algorithms
 * Easy (66.94%)
 * Likes:    1251
 * Dislikes: 0
 * Total Accepted:    810.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2, 5, 3, 0, 5, 0]'
 *
 * 设备中存有 n 个文件，文件 id 记于数组 documents。若文件 id
 * 相同，则定义为该文件存在副本。请返回任一存在副本的文件 id。
 *
 *
 *
 * 示例 1：
 *
 * 输入：documents = [2, 5, 3, 0, 5, 0]
 * 输出：0 或 5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 ≤ documents[i] ≤ n-1
 * 2 <= n <= 100000
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
  int findRepeatDocument(vector<int>& documents) {
    unordered_set<int> s;
    for (auto document : documents) {
      if (s.count(document)) return document;
      s.insert(document);
    }
    return -1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2, 5, 3, 0, 5, 0]\n
// @lcpr case=end

 */
