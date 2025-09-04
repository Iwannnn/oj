/*
 * @lc app=leetcode.cn id=LCR 173 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 173] 点名
 *
 * https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/description/
 *
 * algorithms
 * Easy (44.79%)
 * Likes:    442
 * Dislikes: 0
 * Total Accepted:    385.7K
 * Total Submissions: 861K
 * Testcase Example:  '[0,1,2,3,5]'
 *
 * 某班级 n 位同学的学号为 0 ~ n-1。点名结果记录于升序数组
 * records。假定仅有一位同学缺席，请返回他的学号。
 *
 *
 *
 * 示例 1：
 *
 * 输入：records = [0,1,2,3,5]
 * 输出：4
 *
 *
 * 示例 2：
 *
 * 输入：records = [0, 1, 2, 3, 4, 5, 6, 8]
 * 输出：7
 *
 *
 *
 * 提示：
 *
 * 1 <= records.length <= 10000
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
  int takeAttendance(vector<int>& records) {
    int i = 0, j = records.size() - 1;
    while (i < j) {
      int mid = (i + j) >> 1;
      if (records[mid] == mid)
        i = mid + 1;
      else
        j = mid;
    }
    return records[i] == i ? i + 1 : i;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,2,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [0, 1, 2, 3, 4, 5, 6, 8]\n
// @lcpr case=end

 */
