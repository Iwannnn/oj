#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N], q[N];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int hh = 0, tt = -1;
  for (int i = 0; i < n; ++i) {  //窗口内最小
    if (hh <= tt && i - k + 1 > q[hh])
      ++hh;  // i-k+1为当前元素的窗口底部，如果当前队列中的元素最前面的位置在当前窗口外要重新放一个进去
    while (hh <= tt && a[q[tt]] >= a[i])  //当前窗孔内的元素全都大于当前元素
      --tt;
    q[++tt] = i;
    if (i >= k - 1) cout << a[q[hh]] << " ";
  }
  cout << endl;
  hh = 0, tt = -1;
  for (int i = 0; i < n; ++i) {
    if (hh <= tt && i - k + 1 > q[hh]) ++hh;
    while (hh <= tt && a[q[tt]] <= a[i]) --tt;
    q[++tt] = i;
    if (i >= k - 1) cout << a[q[hh]] << " ";
  }
  return 0;
}