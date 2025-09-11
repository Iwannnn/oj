/*
 * @lc app=leetcode.cn id=LCR 161 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 161] 连续天数的最高销售额
 *
 * https://leetcode.cn/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/description/
 *
 * algorithms
 * Easy (59.97%)
 * Likes:    755
 * Dislikes: 0
 * Total Accepted:    440K
 * Total Submissions: 733.6K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 某公司每日销售额记于整数数组 sales，请返回所有 连续
 * 一或多天销售额总和的最大值。
 *
 * 要求实现时间复杂度为 O(n) 的算法。
 *
 *
 *
 * 示例 1：
 *
 * 输入：sales = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：[4,-1,2,1] 此连续四天的销售总额最高，为 6。
 *
 * 示例 2：
 *
 * 输入：sales = [5,4,-1,7,8]
 * 输出：23
 * 解释：[5,4,-1,7,8] 此连续五天的销售总额最高，为 23。 
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 10^5
 * -100 <= arr[i] <= 100
 *
 *
 * 注意：本题与主站 53
 * 题相同：https://leetcode-cn.com/problems/maximum-subarray/
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
  int maxSales(vector<int>& sales) {
    int res = sales[0], tmp = sales[0];
    for (int i = 1; i < sales.size(); ++i) {
      tmp = max(sales[i], tmp + sales[i]);
      res = max(res, tmp);
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */
