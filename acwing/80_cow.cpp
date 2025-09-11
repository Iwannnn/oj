#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 50010;

int main() {
  int n;
  vector<PII> cow;
  cin >> n;
  while (n--) {
    int w, s;
    cin >> w >> s;
    cow.push_back({w + s, w});
  }

  sort(cow.begin(), cow.end());

  int res = -2e9, sum = 0;
  for (int i = 0; i < cow.size(); ++i) {
    int s = cow[i].first - cow[i].second, w = cow[i].second;
    res = max(res, sum - s);
    sum += w;
  }

  cout << res << endl;
}
