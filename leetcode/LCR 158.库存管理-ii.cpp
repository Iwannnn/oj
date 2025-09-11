/*
 * @lc app=leetcode.cn id=LCR 158 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 158] 库存管理 II
 *
 * https://leetcode.cn/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/description/
 *
 * algorithms
 * Easy (69.79%)
 * Likes:    419
 * Dislikes: 0
 * Total Accepted:    328.5K
 * Total Submissions: 470.9K
 * Testcase Example:  '[6,1,3,1,1,1]'
 *
 * 仓库管理员以数组 stock 形式记录商品库存表。stock[i] 表示商品
 * id，可能存在重复。请返回库存表中数量大于 stock.length / 2 的商品 id。
 *
 *
 *
 * 示例 1：
 *
 * 输入：stock = [6, 1, 3, 1, 1, 1]
 * 输出：1
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= stock.length <= 50000
 * 给定数组为非空数组，且存在结果数字
 *
 *
 *
 *
 * 注意：本题与主站 169
 * 题相同：https://leetcode-cn.com/problems/majority-element/
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
  int inventoryManagement(vector<int>& stock) {
    sort(stock.begin(), stock.end());
    return stock[stock.size() / 2];
  }
};
// @lc code=end

/*
// @lcpr case=start
// [6, 1, 3, 1, 1, 1]\n
// @lcpr case=end

 */
