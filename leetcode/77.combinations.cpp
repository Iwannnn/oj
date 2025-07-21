/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30204
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.70%)
 * Likes:    1784
 * Dislikes: 0
 * Total Accepted:    910.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *
 * 你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 * 示例 2：
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
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
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> tmp;
    f(res, tmp, 1, n, k);
    return res;
  }

  void f(vector<vector<int>>& res, vector<int>& tmp, int start, int n, int k) {
    if (tmp.size() == k) {
      res.push_back(tmp);
      return;
    }

    for (int i = start; i <= n; ++i) {
      tmp.push_back(i);
      f(res, tmp, i + 1, n, k);
      tmp.pop_back();
    }
  }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */
