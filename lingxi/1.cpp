#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);

  for (int i = 0; i < n; ++i) cin >> h[i];

  int mx = *max_element(h.begin(), h.end());
  int res = count(h.begin(), h.end(), mx);

  cout << res << "\n";
  return 0;
}