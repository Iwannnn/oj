/*
 * @lc app=leetcode.cn id=71 lang=cpp
 * @lcpr version=30204
 *
 * [71] 简化路径
 *
 * https://leetcode.cn/problems/simplify-path/description/
 *
 * algorithms
 * Medium (47.46%)
 * Likes:    817
 * Dislikes: 0
 * Total Accepted:    302.6K
 * Total Submissions: 636.4K
 * Testcase Example:  '"/home/"'
 *
 * 给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/'
 * 开头），请你将其转化为 更加简洁的规范路径。
 *
 * 在 Unix 风格的文件系统中规则如下：
 *
 *
 * 一个点 '.' 表示当前目录本身。
 * 此外，两个点 '..' 表示将目录切换到上一级（指向父目录）。
 * 任意多个连续的斜杠（即，'//' 或 '///'）都被视为单个斜杠 '/'。
 * 任何其他格式的点（例如，'...' 或 '....'）均被视为有效的文件/目录名称。
 *
 *
 * 返回的 简化路径 必须遵循下述格式：
 *
 *
 * 始终以斜杠 '/' 开头。
 * 两个目录名之间必须只有一个斜杠 '/' 。
 * 最后一个目录名（如果存在）不能 以 '/' 结尾。
 * 此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或
 * '..'）。
 *
 *
 * 返回简化后得到的 规范路径 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：path = "/home/"
 *
 * 输出："/home"
 *
 * 解释：
 *
 * 应删除尾随斜杠。
 *
 *
 * 示例 2：
 *
 *
 * 输入：path = "/home//foo/"
 *
 * 输出："/home/foo"
 *
 * 解释：
 *
 * 多个连续的斜杠被单个斜杠替换。
 *
 *
 * 示例 3：
 *
 *
 * 输入：path = "/home/user/Documents/../Pictures"
 *
 * 输出："/home/user/Pictures"
 *
 * 解释：
 *
 * 两个点 ".." 表示上一级目录（父目录）。
 *
 *
 * 示例 4：
 *
 *
 * 输入：path = "/../"
 *
 * 输出："/"
 *
 * 解释：
 *
 * 不可能从根目录上升一级目录。
 *
 *
 * 示例 5：
 *
 *
 * 输入：path = "/.../a/../b/c/../d/./"
 *
 * 输出："/.../b/d"
 *
 * 解释：
 *
 * "..." 在这个问题中是一个合法的目录名。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= path.length <= 3000
 * path 由英文字母，数字，'.'，'/' 或 '_' 组成。
 * path 是一个有效的 Unix 风格绝对路径。
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
#include <sstream>
#include <stack>
#include <string>
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
  string simplifyPath(string path) {
    string res, t;
    stringstream paths(path);
    vector<string> v;
    while (getline(paths, t, '/')) {
      if (t == "" || t == ".") continue;
      if (t == ".." && !v.empty()) {
        v.pop_back();
      } else if (t != "..") {
        v.push_back(t);
      }
    }
    for (string s : v) res += "/" + s;
    return res.empty() ? "/" : res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "/home/"\n
// @lcpr case=end

// @lcpr case=start
// "/home//foo/"\n
// @lcpr case=end

// @lcpr case=start
// "/home/user/Documents/../Pictures"\n
// @lcpr case=end

// @lcpr case=start
// "/../"\n
// @lcpr case=end

// @lcpr case=start
// "/.../a/../b/c/../d/./"\n
// @lcpr case=end

 */
