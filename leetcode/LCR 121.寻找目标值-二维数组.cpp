/*
 * @lc app=leetcode.cn id=LCR 121 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 121] 寻找目标值 - 二维数组
 *
 * https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/description/
 *
 * algorithms
 * Medium (39.53%)
 * Likes:    1037
 * Dislikes: 0
 * Total Accepted:    556.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[2,3,6,8],[4,5,8,9],[5,9,10,12]]\n8'
 *
 * m*n 的二维数组 plants 记录了园林景观的植物排布情况，具有以下特性：
 *
 *
 * 每行中，每棵植物的右侧相邻植物不矮于该植物；
 * 每列中，每棵植物的下侧相邻植物不矮于该植物。
 *
 *
 *
 *
 * 请判断 plants 中是否存在目标高度值 target。
 *
 *
 *
 * 示例 1：
 *
 * 输入：plants = [[2,3,6,8],[4,5,8,9],[5,9,10,12]], target = 8
 *
 * 输出：true
 *
 *
 *
 *
 * 示例 2：
 *
 * 输入：plants = [[1,3,5],[2,5,7]], target = 4
 *
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= n <= 1000
 * 0 <= m <= 1000
 *
 *
 * 注意：本题与主站 240
 * 题相同：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
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
  bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
    int m = plants.size();
    if (m == 0) return false;
    int n = plants[0].size();
    if (n == 0) return false;
    int i = 0, j = n - 1;

    while (i < m && j >= 0) {
      int v = plants[i][j];

      if (v == target) return true;
      if (v > target) --j;
      if (v < target) ++i;
    }
    return false;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,3,6,8],[4,5,8,9],[5,9,10,12]]\n8\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5],[2,5,7]]\n4\n
// @lcpr case=end

 */
