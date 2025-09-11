/*
 * @lc app=leetcode.cn id=LCR 170 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 170] 交易逆序对的总数
 *
 * https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/
 *
 * algorithms
 * Hard (49.83%)
 * Likes:    1144
 * Dislikes: 0
 * Total Accepted:    238.8K
 * Total Submissions: 478.7K
 * Testcase Example:  '[7,5,6,4]'
 *
 * 在股票交易中，如果前一天的股价高于后一天的股价，则可以认为存在一个「交易逆序对」。请设计一个程序，输入一段时间内的股票交易记录
 * record，返回其中存在的「交易逆序对」总数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：record = [9, 7, 5, 4, 6]
 * 输出：8
 * 解释：交易中的逆序对为 (9, 7), (9, 5), (9, 4), (9, 6), (7, 5), (7, 4), (7,
 * 6), (5, 4)。
 *
 *
 *
 *
 * 提示：
 *
 * 0 <= record.length <= 50000
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
  int reversePairs(vector<int>& record) {
    vector<int> tmp(record.size());
    return mergeSort(0, record.size(), record, tmp);
  }
  int mergeSort(int l, int r, vector<int>& record, vector<int>& tmp) {
    if (r - l <= 1) return 0;
    int m = l + (r - l) / 2;
    int res = 0;
    res += mergeSort(l, m, record, tmp);
    res += mergeSort(m, r, record, tmp);

    int i = l, j = m, k = l;
    while (i < m && j < r) {
      if (record[i] <= record[j]) {
        tmp[k++] = record[i++];
      } else {
        // [i,m)
        tmp[k++] = record[j++];
        res += (m - i);
      }
    }

    while (i < m) tmp[k++] = record[i++];
    while (j < r) tmp[k++] = record[j++];

    for (int t = l; t < r; ++t) record[t] = tmp[t];
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [9, 7, 5, 4, 6]\n
// @lcpr case=end

 */
