#include <iostream>
#include <vector>

using namespace std;

int get(vector<int> num, int l, int r) {
  int res = 0;
  for (int i = l; i >= r; --i) res = res * 10 + num[i];
  return res;
}

int pow10(int x) {
  int res = 1;
  while (x--) res *= 10;
  return res;
}

int count(int n, int x) {
  if (!n) return 0;
  vector<int> num;
  while (n) {
    num.push_back(n % 10);
    n /= 10;
  }
  n = num.size();

  int res = 0;
  // 1 <= xxx1yyy <= abcdefg = n
  for (int i = n - 1 - !x; i >= 0; --i) {
    if (i < n - 1) {  // xxx = 000 ~ abc - 1, yyy = 000 ~ 999,
                      // 总个数为：abc*1000(10elen(yyy))
      res += get(num, n - 1, i + 1) * pow10(i);
      if (!x) res -= pow10(i);
    }
    // xxx = abc
    // num[i] < x 0个
    if (num[i] == x)  // 000 ~ efg
      res += get(num, i - 1, 0) + 1;
    else if (num[i] > x)  // 10e(len(yyy))
      res += pow10(i);
  }
  return res;
}

int main() {
  int a, b;
  while (cin >> a >> b, a) {
    if (a > b) swap(a, b);
    for (int i = 0; i <= 9; ++i) cout << count(b, i) - count(a - 1, i) << " ";
    cout << endl;
  }
}