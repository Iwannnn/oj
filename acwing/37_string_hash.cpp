#include <iostream>

using namespace std;

//字符串hash，把前缀映射为hash值（看为P进制），再根据哈希值的计算方法计算字串的哈希值，长前缀r减去短前缀l-1扩展0至长前缀的位置
//P^(r-l+1)

typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 131;

ULL h[N], p[N];  // p的多少次方
char str[N];

ULL substr(int l, int r) {  //左边为高位右边为低位
  return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
  int n, m;
  cin >> n >> m;
  cin >> (str + 1);
  p[0] = 1;
  for (int i = 1; i <= n; ++i) {
    h[i] = h[i - 1] * P + str[i];
    p[i] = P * p[i - 1];
  }
  while (m--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (substr(l1, r1) == substr(l2, r2))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}