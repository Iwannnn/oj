#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    unsigned long long a = n / 2;
    unsigned long long b = n - a;
    unsigned long long res = a * b;
    printf("%lld\n", res);
  }
}