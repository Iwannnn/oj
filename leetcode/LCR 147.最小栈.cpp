/*
 * @lc app=leetcode.cn id=LCR 147 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 147] 最小栈
 *
 * https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/description/
 *
 * algorithms
 * Easy (55.39%)
 * Likes:    546
 * Dislikes: 0
 * Total Accepted:    383.9K
 * Total Submissions: 692.9K
 * Testcase Example:
 '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 请你设计一个 最小栈 。它提供 push ，pop ，top
 操作，并能在常数时间内检索到最小元素的栈。
 *
 *
 *
 * 实现 MinStack 类:
 *
 *
 * MinStack() 初始化堆栈对象。
 * void push(int val) 将元素val推入堆栈。
 * void pop() 删除堆栈顶部的元素。
 * int top() 获取堆栈顶部的元素。
 * int getMin() 获取堆栈中的最小元素。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 *
 * 输出：
 * [null,null,null,null,-3,null,0,-2]
 *
 * 解释：
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * -2^31 <= val <= 2^31 - 1
 * pop、top 和 getMin 操作总是在 非空栈 上调用
 * push、pop、top 和 getMin 最多被调用 3 * 10^4 次
 *
 *
 *
 *
 * 注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/
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
class MinStack {
 public:
  /** initialize your data structure here. */
  const int SIZE = 8001;
  int *data;
  int *min;
  int size = 0;
  MinStack() {
    data = new int[SIZE];
    min = new int[SIZE];
  }

  void push(int x) {
    data[size] = x;
    if (size == 0 || x < getMin())
      min[size] = x;
    else
      min[size] = getMin();
    size++;
  }

  void pop() { size--; }

  int top() { return data[size - 1]; }

  int getMin() { return min[size - 1]; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

/*
// @lcpr case=start
//
["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */
