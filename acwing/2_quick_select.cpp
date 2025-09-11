#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100010;

int q[N];

int quick_select(int q[], int l, int r, int k) {  // 这一部分的前k个
  if (l >= r) return q[l];
  int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
  while (i < j) {
    while (q[++i] < x)  //找出>=x的在x左边的数字
      ;
    while (q[--j] > x)  // 找出<=x的在x右边的数字
      ;
    if (i < j) swap(q[i], q[j]);
  }
  //边界问题，如果此处用i j与 x的取值有关系
  if (j - l + 1 >= k)  // k在分界点左边
    return quick_select(q, l, j, k);
  else
    return quick_select(q, j + 1, r, k - (j - l + 1));
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
  quick_select(q, 0, n - 1, k);
  cout << quick_select(q, 0, n - 1, k) << endl;
  return 0;
}