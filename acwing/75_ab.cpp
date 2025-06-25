#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

struct Range {
  int l, r;

  bool operator<(const Range& w) const { return l < w.l; }
} range[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> range[i].l >> range[i].r;

  sort(range, range + n);

  priority_queue<int, vector<int>, greater<int>> heap;
  for (int i = 0; i < n; ++i) {
    auto a = range[i];
    // l升序排列
    if (heap.empty() || heap.top() >= a.l) {  //最小的都相交
      heap.push(a.r);
    } else {  // 不相交
      heap.pop();
      heap.push(a.r);
    }
  }
  cout << heap.size() << endl;
}
