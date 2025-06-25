#include <cstddef>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
int res = 0, n = 0;  // n为个数

int dfs(int id, vector<int> node) {
  if (id > n) return 1;
  int l = 1, r = 1;
  if (id * 2 <= n && node[id * 2] == 1) {
    l = dfs(id * 2, node);
  }
  if (id * 2 + 1 <= n && node[id * 2 + 1] == 1) {
    r = dfs(id * 2 + 1, node);
  }
  if (l == 0 || r == 0) {  //自身不能被传递到达
    ++res;
    return 2;
  }
  if (l == 2 || r == 2) {  //字有 自身能被传递到达
    return 1;
  }
  // 0表示自身没有但是能被到达
  return 0;
}

int main() {
  vector<int> node;
  int tmp;
  string s;
  string t;
  getline(cin, s);
  istringstream ss(s);
  node.push_back(0);
  while (ss >> t) {
    ++n;
    if (t == "N")
      node.push_back(0);
    else {
      while (n != 1 && node[n / 2] == 0) {
        node.push_back(0);
        ++n;
      }
      node.push_back(1);
    }
  }
  if (dfs(1, node) == 0) {
    ++res;
  }
  cout << res << endl;
  return 0;
}