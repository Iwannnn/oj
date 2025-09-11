#include <iostream>
#include <queue>

using namespace std;

const int N = 10010;

int main() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> q;
  while (n--) {
    int t;
    cin >> t;
    q.push(t);
  }
  int res = 0;
  while (q.size() != 1) {
    int a, b, c;
    a = q.top();
    q.pop();
    b = q.top();
    q.pop();
    c = a + b;
    res += c;
    q.push(c);
  }
  cout << res << endl;
}