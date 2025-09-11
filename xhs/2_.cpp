#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int n;
  string plog;
  int res = 0;
  cin >> n >> plog;

  while (1) {
    string tmp = plog;
    vector<int> del;
    for (int i = 0; i < plog.size() - 1; ++i) {
      for (int j = i + 1; j < plog.size(); ++j) {
        if (plog[j] != plog[i] &&
            find(del.begin(), del.end(), j) == del.end()) {

          del.push_back(j);
          res++;
        }
      }
    }

    sort(del.begin(), del.end());
    for (int i = del.size() - 1; i >= 0; --i) {
      tmp.erase(del[i], 1);
    }

    cout << plog << endl;
    plog = tmp;
    cout << plog << endl;
    for (int i = 1; i < plog.size(); ++i) {
      if (plog[i] != plog[1])
        continue;
    }
    break;
  }

  cout << res << endl;
}