/*
 * @lc app=leetcode.cn id=LCR 157 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 157] 套餐内商品的排列顺序
 *
 * https://leetcode.cn/problems/zi-fu-chuan-de-pai-lie-lcof/description/
 *
 * algorithms
 * Medium (57.26%)
 * Likes:    731
 * Dislikes: 0
 * Total Accepted:    295.9K
 * Total Submissions: 516.8K
 * Testcase Example:  '"agew"'
 *
 * 某店铺将用于组成套餐的商品记作字符串 goods，其中 goods[i]
 * 表示对应商品。请返回该套餐内所含商品的 全部排列方式 。
 *
 * 返回结果 无顺序要求，但不能含有重复的元素。
 *
 *
 *
 * 示例 1：
 *
 * 输入：goods = "agew"
 *
 * 输出：["aegw","aewg","agew","agwe","aweg","awge","eagw","eawg","egaw","egwa","ewag","ewga","gaew","gawe","geaw","gewa","gwae","gwea","waeg","wage","weag","wega","wgae","wgea"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= goods.length <= 8
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
  vector<string> goodsOrder(string goods) {
    dfs(goods, 0);
    return res;
  }

 private:
  vector<string> res;

  void dfs(string goods, int idx) {  // 确定第x位是什么
    if (idx == goods.size() - 1) {
      res.push_back(goods);
      return;
    }
    unordered_set<int> st;

    for (int i = idx; i < goods.size(); ++i) {
      if (st.find(goods[i]) != st.end()) continue;  //这个位置出现过这个数了
      st.insert(goods[i]);

      swap(goods[i], goods[idx]);
      dfs(goods, idx + 1);
      swap(goods[idx], goods[idx]);
    }
  }
};
// @lc code=end

/*
// @lcpr case=start
// "agew"\n
// @lcpr case=end

 */
