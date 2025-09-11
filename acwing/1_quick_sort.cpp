#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100010;

int q[N];

void quick_sort(int q[], int l, int r) {
  if (l >= r) return;
  int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
  while (i < j) {
    do i++;
    while (q[i] < x);  //找出>=x的在x左边的数字
    do j--;
    while (q[j] > x);  // 找出<=x的在x右边的数字
    if (i < j) swap(q[i], q[j]);
  }
  //边界问题，如果此处用i j与 x的取值有关系
  quick_sort(q, l, j);
  quick_sort(q, j + 1, r);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
  quick_sort(q, 0, n - 1);
  for (int i = 0; i < n - 1; ++i) printf("%d ", q[i]);
  printf("%d\n", q[n - 1]);
  return 0;
}