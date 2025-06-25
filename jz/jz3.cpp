#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param numbers int整型vector
   * @return int整型
   */
  int duplicate(vector<int>& numbers) {
    map<int, int> m;
    for (int i = 0; i < numbers.size(); ++i) {
      if (m[numbers[i]])
        return numbers[i];
      else
        m[numbers[i]] = 1;
    }
    return -1;
  }
};