#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], d[N];  // d[len] = x 表示长度为len的上升序列中 最小的结尾为x

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int len = 0;
  d[0] = -1e9 - 10;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = len + 1;
    while (l < r) {  // 找到
      int mid = (l + r) >> 1;
      if (d[mid] >= a[i])
        r = mid;
      else
        l = mid + 1;
    }
    len = max(len, l);
    d[l] = a[i];
  }
  cout << len << endl;
}