#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string plog;
  cin >> n >> plog;
  char a = plog[0];
  int l_a = 1;
  while (l_a < n && plog[l_a] == a)
    ++l_a;

  cout << n - l_a << endl;
}