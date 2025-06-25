#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

int main() {
  int n;
  cin >> n;
  vector<PII> s, res;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    s.push_back({l, r});
  }
  sort(s.begin(), s.end());
  int l = -1e9 - 10, r = -1e9 - 10;
  for (auto item : s) {
    if (r < item.first) {
      if (l != -1e9 - 10) res.push_back({l, r});
      l = item.first;
      r = item.second;

    } else {
      r = max(r, item.second);
    }
  }
  if (l != -1e9 - 10) res.push_back({l, r});
  cout << res.size() << endl;
}