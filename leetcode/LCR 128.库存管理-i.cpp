/*
 * @lc app=leetcode.cn id=LCR 128 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 128] 库存管理 I
 *
 * https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/description/
 *
 * algorithms
 * Easy (49.57%)
 * Likes:    877
 * Dislikes: 0
 * Total Accepted:    522.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[4,5,8,3,4]'
 *
 * 仓库管理员以数组 stock 形式记录商品库存表。stock[i] 表示商品
 * id，可能存在重复。原库存表按商品 id
 * 升序排列。现因突发情况需要进行商品紧急调拨，管理员将这批商品 id
 * 提前依次整理至库存表最后。请你找到并返回库存表中编号的 最小的元素
 * 以便及时记录本次调拨。
 *
 *
 *
 * 示例 1：
 *
 * 输入：stock = [4,5,8,3,4]
 * 输出：3
 *
 *
 * 示例 2：
 *
 * 输入：stock = [5,7,9,1,2]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= stock.length <= 5000
 * -5000 <= stock[i] <= 5000
 *
 *
 *
 *
 * 注意：本题与主站 154
 * 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
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
  int inventoryManagement(vector<int>& stock) {
    int l = 0, r = stock.size() - 1;
    // 最小值在第一个逆序的位置，如果mid比最右边大，那最小值再mid右边
    // 如果mid比最右边小那就二分查找
    while (l < r) {
      int mid = (l + r) >> 1;
      if (stock[mid] > stock[r]) {  // 最小值再右边
        l = mid + 1;
      } else if (stock[mid] < stock[r]) {
        r = mid;
      } else {
        --r;
      }
    }
    return stock[l];
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,8,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,7,9,1,2]\n
// @lcpr case=end

 */
