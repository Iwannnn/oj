/*
 * @lc app=leetcode.cn id=LCR 159 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 159] 库存管理 III
 *
 * https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/description/
 *
 * algorithms
 * Easy (57.74%)
 * Likes:    602
 * Dislikes: 0
 * Total Accepted:    480.4K
 * Total Submissions: 832K
 * Testcase Example:  '[2,5,7,4]\n1'
 *
 * 仓库管理员以数组 stock 形式记录商品库存表，其中 stock[i]
 * 表示对应商品库存余量。请返回库存余量最少的 cnt 个商品余量，返回 顺序不限。
 *
 *
 *
 * 示例 1：
 *
 * 输入：stock = [2,5,7,4], cnt = 1
 * 输出：[2]
 *
 *
 * 示例 2：
 *
 * 输入：stock = [0,2,3,6], cnt = 2
 * 输出：[0,2] 或 [2,0]
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= cnt <= stock.length <= 10000
 * 0 <= stock[i] <= 10000
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
  vector<int> inventoryManagement(vector<int>& stock, int cnt) {
    if (cnt == 0) return {};
    priority_queue<int> q(stock.begin(), stock.begin() + cnt);

    for (int i = cnt; i < stock.size(); ++i) {
      if (stock[i] < q.top()) {
        q.pop();
        q.push(stock[i]);
      }
    }
    vector<int> res;
    while (!q.empty()) {
      auto t = q.top();
      res.push_back(t);
      q.pop();
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,5,7,4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0,2,3,6]\n2\n
// @lcpr case=end

 */
