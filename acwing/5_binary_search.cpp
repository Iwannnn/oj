#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int q[N];

void binary_search(int q[], int x) {  //左右边界
  int l = 0, r = n - 1;
  int a = 0, b = n - 1;
  while (l < r) {  //左边界
    int mid = (l + r) >> 1;
    if (q[mid] >= x)  //找左边
      r = mid;
    else
      l = mid + 1;  //不等于 要再挪一个位置
  }
  if (q[l] != x) {
    cout << "-1 -1" << endl;
  } else {
    while (a < b) {  //右边界
      int mid = (a + b + 1) >> 1;
      if (q[mid] <= x)
        a = mid;
      else
        b = mid - 1;
    }
    cout << l << " " << b << endl;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> q[i];
  while (m--) {
    int x;
    cin >> x;
    binary_search(q, x);
  }
}

bool check(int mid) { return 0; }

//根据check向怎么划分
// 此例中 l=mid(右边届) / r=mid(左边界) 判断包括等号

void binary_search_1(int l, int r) {  //左边界
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;  // mid不+1
    else
      l = mid + 1;
  }
}

// +1 取决于l与r相邻时，1+2>>1 == 1  3+4>>1==3
// 再给l赋值mid会死循环，

void binary_sarch_2(int l, int r) {  //右边界
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid))
      l = mid;  // mid 得有+1
    else
      r = mid - 1;
  }
}