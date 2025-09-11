/*
 * @lc app=leetcode.cn id=LCR 160 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 160] 数据流中的中位数
 *
 * https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/description/
 *
 * algorithms
 * Hard (58.18%)
 * Likes:    481
 * Dislikes: 0
 * Total Accepted:    150K
 * Total Submissions: 257.8K
 * Testcase Example:
 '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * 中位数 是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
 *
 * 例如，
 * [2,3,4] 的中位数是 3
 * [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 * 设计一个支持以下两种操作的数据结构：
 *
 *
 * void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 * double findMedian() - 返回目前所有元素的中位数。
 *
 *
 * 示例 1：
 *
 * 输入：
 * ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
 * [[],[1],[2],[],[3],[]]
 * 输出：[null,null,null,1.50000,null,2.00000]
 *
 *
 * 示例 2：
 *
 * 输入：
 * ["MedianFinder","addNum","findMedian","addNum","findMedian"]
 * [[],[2],[],[3],[]]
 * 输出：[null,null,2.00000,null,2.50000]
 *
 *
 *
 * 提示：
 *
 *
 * 最多会对 addNum、findMedian 进行 50000 次调用。
 *
 *
 * 注意：本题与主站 295
 * 题相同：https://leetcode-cn.com/problems/find-median-from-data-stream/
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
class MedianFinder {
 public:
  /** initialize your data structure here. */
  // 小顶堆 保存大的一半（大的一部分找最小的
  priority_queue<int, vector<int>, greater<int>> a;
  // 大顶堆 保存小的一半（小的一部分找最大的
  priority_queue<int, vector<int>, less<int>> b;
  MedianFinder() {}

  void addNum(int num) {
    if (a.size() != b.size()) {
      a.push(num);
      b.push(a.top());
      a.pop();
    } else {
      b.push(num);
      a.push((b.top()));
      b.pop();
    }
  }

  double findMedian() {
    return a.size() == b.size() ? (a.top() + b.top()) / 2.0 : a.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

/*
// @lcpr case=start
//
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"][[],[1],[2],[],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
//
["MedianFinder","addNum","findMedian","addNum","findMedian"][[],[2],[],[3],[]]\n
// @lcpr case=end

 */
