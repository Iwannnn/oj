#include <bits/stdc++.h>

using namespace std;

bool is_perfect(int x) {
  if (x <= 2)
    return false;
  for (int i = 3; i <= 30; ++i) {
    int lo = 1, hi = x;
    while (lo <= hi) {
      long long mid = (lo + hi) / 2;
      long long mm = 1;
      bool over_ = false;
      for (int j = 0; j < i; ++j) {
        mm *= (mid + j);
        if (mm > x) {
          over_ = true;
          break;
        }
      }

      if (!over_ && mm == x)
        return true;
      if (over_ || mm > x)
        hi = mid - 1;
      else
        lo = mid + 1;
    }
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    cout << (is_perfect(x) ? "YES" : "NO") << endl;
  }
}