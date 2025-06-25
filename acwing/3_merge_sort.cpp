#include <bits/types/struct_tm.h>

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], tmp[N];

void merge_sort(int q[], int l, int r) {
  if (l >= r) return;
  int mid = (l + r) >> 1;
  merge_sort(q, l, mid);
  merge_sort(q, mid + 1, r);
  int k = 0, i = l, j = mid + 1;
  while (i <= mid && j <= r) tmp[k++] = q[i] <= q[j] ? q[i++] : q[j++];
  while (i <= mid) tmp[k++] = q[i++];
  while (j <= r) tmp[k++] = q[j++];
  for (int i = l, j = 0; i <= r; ++i, ++j) q[i] = tmp[j];
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  merge_sort(a, 0, n - 1);
  for (int i = 0; i < n; ++i) cout << a[i] << " ";
}