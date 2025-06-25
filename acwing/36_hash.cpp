#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;

int main() {
  int n;
  cin >> n;
  unordered_map<int, int> m;
  while (n--) {
    string op;
    int x;
    cin >> op >> x;
    if (op == "I") {
      m[x]++;
    } else {
      cout << (m[x] == 0 ? "No" : "Yes") << endl;
    }
  }
  return 0;
}