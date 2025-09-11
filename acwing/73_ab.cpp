#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 1e9 + 10;

int n;
vector<PII> nums;

int main() {
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    nums.push_back({b, a});
  }
  sort(nums.begin(), nums.end());

  int res = 0;
  int b = -INF;
  for (auto num = nums.begin(); num != nums.end(); ++num) {
    if (num->second > b) {
      b = num->first;
      ++res;
    }
  }
  cout << res << endl;
}