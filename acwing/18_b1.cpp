#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int x, res = 0;
    cin >> x;
    while (x) {
      res += x & 1;
      x >>= 1;
    }
    cout << res << " ";
  }
}