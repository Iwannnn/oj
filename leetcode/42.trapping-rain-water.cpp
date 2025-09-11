/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30204
 *
 * [42] 接雨水
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
  int trap(vector<int> &h) {
    int peak = h[0], p_i = 0;
    for (int i = 1; i < h.size(); ++i)
      if (h[i] > peak) {
        peak = h[i];
        p_i = i;
      }

    int res = 0;
    int peak_tmp = 0;

    for (int i = 0; i < p_i; ++i) {
      if (h[i] > peak_tmp)
        peak_tmp = h[i];
      res += (peak_tmp - h[i]);
    }

    peak_tmp = 0;
    for (int i = h.size() - 1; i > p_i; --i) {
      if (h[i] > peak_tmp)
        peak_tmp = h[i];
      res += (peak_tmp - h[i]);
    }

    return res;
  }
  int trap(vector<int> &height) {
    int res = 0;
    stack<int> st;

    st.push(0);
    for (int i = 1; i < height.size(); i++) {
      if (height[st.top()] >= height[i]) {
        st.push(i);
      } else {
        while (!st.empty() && height[st.top()] < height[i]) {
          int h_bottom = height[st.top()];
          st.pop();
          if (!st.empty()) {
            int h = min(height[st.top()], height[i]) - h_bottom;
            int w = i - st.top() - 1;
            res += h * w;
          }
        }
        st.push(i);
      }
    }
    return res;
  }

  int trap(vector<int> &h) {
    int l = 0, r = h.size() - 1;
    int res = 0, pre_max = 0, suf_max = 0;
    while (l < r) {
      pre_max = max(pre_max, h[l]);
      suf_max = max(suf_max, h[r]);
      res += (pre_max < suf_max) ? (pre_max - h[l++]) : (suf_max - h[r--]);
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */
