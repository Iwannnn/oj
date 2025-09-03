/*
 * @lc app=leetcode.cn id=LCR 180 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 180] 文件组合
 *
 * https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/description/
 *
 * algorithms
 * Easy (70.51%)
 * Likes:    584
 * Dislikes: 0
 * Total Accepted:    265.4K
 * Total Submissions: 376.6K
 * Testcase Example:  '12'
 *
 * 待传输文件被切分成多个部分，按照原排列顺序，每部分文件编号均为一个
 * 正整数（至少含有两个文件）。传输要求为：连续文件编号总和为接收方指定数字
 * target 的所有文件。请返回所有符合该要求的文件传输组合列表。
 *
 * 注意，返回时需遵循以下规则：
 *
 *
 * 每种组合按照文件编号 升序 排列；
 * 不同组合按照第一个文件编号 升序 排列。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：target = 12
 * 输出：[[3, 4, 5]]
 * 解释：在上述示例中，存在一个连续正整数序列的和为 12，为 [3, 4, 5]。
 *
 *
 * 示例 2：
 *
 * 输入：target = 18
 * 输出：[[3,4,5,6],[5,6,7]]
 * 解释：在上述示例中，存在两个连续正整数序列的和分别为 18，分别为 [3, 4, 5, 6]
 * 和 [5, 6, 7]。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= target <= 10^5
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
  vector<vector<int>> fileCombination(int target) {
    vector<vector<int>> res;
    int i = 1, j = 2, s = 3;
    while (i < j) {
      if (s == target) {
        vector<int> ans;
        for (int k = i; k <= j; ++k) ans.push_back(k);
        res.push_back(ans);
      }

      if (s >= target) {
        s -= i;
        ++i;
      } else {
        ++j;
        s += j;
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 18\n
// @lcpr case=end

 */
