#include <cstddef>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], d[N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) d[i] = a[i] - a[i - 1];
  while (m--) {
    int l, r, c;
    cin >> l >> r >> c;
    d[l] += c;
    d[r + 1] -= c;
  }
  int t = 0;
  for (int i = 1; i <= n; ++i) {
    t += d[i];
    cout << t << " ";
  }
  return 0;
}