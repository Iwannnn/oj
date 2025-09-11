#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  unordered_set<string> st;
  int n = s.size();
  int i = 0, j = 1;
  while (j < n) {
    string ss = s.substr(j, 2);
    if (ss == "dp") {
      string tmp = s.substr(i, j + 1 - i + 1);
      if (st.find(tmp) == st.end()) st.insert(tmp);
      i = j + 2;
      j = j + 2;
    }
    ++j;
  }
  cout << st.size() << endl;
  return 0;
}