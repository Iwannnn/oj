/*
 * @lc app=leetcode.cn id=LCR 177 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 177] 撞色搭配
 *
 * https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/description/
 *
 * algorithms
 * Medium (68.86%)
 * Likes:    892
 * Dislikes: 0
 * Total Accepted:    217.4K
 * Total Submissions: 315.6K
 * Testcase Example:  '[4,5,2,4,6,6]'
 *
 * 整数数组 sockets 记录了一个袜子礼盒的颜色分布情况，其中 sockets[i]
 * 表示该袜子的颜色编号。礼盒中除了一款撞色搭配的袜子，每种颜色的袜子均有两只。请设计一个程序，在时间复杂度
 * O(n)，空间复杂度O(1) 内找到这双撞色搭配袜子的两个颜色编号。
 *
 *
 *
 * 示例 1：
 *
 * 输入：sockets = [4, 5, 2, 4, 6, 6]
 * 输出：[2,5] 或 [5,2]
 *
 *
 * 示例 2：
 *
 * 输入：sockets = [1, 2, 4, 1, 4, 3, 12, 3]
 * 输出：[2,12] 或 [12,2]
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= sockets.length <= 10000
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
  vector<int> sockCollocation(vector<int>& sockets) {
    int a = 0, b = 0;
    int xor_ = 0;
    for (auto socket : sockets) xor_ ^= socket;

    int m = 1;
    while ((xor_ & m) == 0) {
      m <<= 1;
    }
    for (auto socket : sockets) {
      if (socket & m)
        a ^= socket;
      else
        b ^= socket;
    }

    return vector<int>{a, b};
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4, 5, 2, 4, 6, 6]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 4, 1, 4, 3, 12, 3]\n
// @lcpr case=end

 */
