/*
 * @lc app=leetcode.cn id=LCR 163 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 163] 找到第 k 位数字
 *
 * https://leetcode.cn/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/description/
 *
 * algorithms
 * Medium (43.07%)
 * Likes:    370
 * Dislikes: 0
 * Total Accepted:    115.8K
 * Total Submissions: 268.9K
 * Testcase Example:  '5'
 *
 * 某班级学号记录系统发生错乱，原整数学号序列 [1,2,3,4,...] 分隔符丢失后变为
 * 1234... 的字符序列。请实现一个函数返回该字符序列中的第 k 位数字。
 *
 *
 *
 * 示例 1：
 *
 * 输入：k = 5
 * 输出：5
 *
 *
 * 示例 2：
 *
 * 输入：k = 12
 * 输出：1
 * 解释：第 12 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 1 ，它是
 * 11 的一部分。
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= k < 2^31
 *
 *
 * 注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/
 *
 *
 *
 */

// @lc code=start
#include <string>
class Solution {
 public:
  int findKthNumber(int k) {
    long long digit = 1;
    long long start = 1;
    long long count = 9;

    while (k > count) {
      k -= count;
      digit += 1;
      start *= 10;
      count = digit * start * 9;
    }

    long long num = start + (k - 1) / digit;
    int idx = (int)((k - 1) % digit);
    return std::to_string(num)[idx] - '0';
  }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 12\n
// @lcpr case=end

 */
