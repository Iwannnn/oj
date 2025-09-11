#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int s[N], top = 0;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    while (top && s[top] >= x) top--;
    if (!top)
      cout << "-1 ";
    else
      cout << s[top] << " ";
    s[++top] = x;  //在x之前不存在比x小的，x就是最小的
  }
}