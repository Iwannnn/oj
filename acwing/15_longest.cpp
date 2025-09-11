#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], s[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int res = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    s[a[i]]++;                                 // a[i]出现的次数
    while (j < i && s[a[i]] > 1) s[a[j++]]--;  // 删除i之前 a[i]出现的情况
    res = max(res, i - j + 1);
  }
  cout << res;
}