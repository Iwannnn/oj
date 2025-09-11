#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>

using namespace std;

const int N = 10;

typedef pair<int, int> PII;

int bfs(string state) {
  queue<string> q;
  unordered_map<string, int> d;

  string end = "12345678x";

  q.push(state);
  d[state] = 0;

  while (q.size()) {
    auto t = q.front();
    q.pop();

    if (t == end) return d[t];

    int c = t.find('x');
    int x = c / 3, y = c % 3;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int x_ = x + dx[i], y_ = y + dy[i];
      if (x_ >= 0 && x_ < 3 && y_ >= 0 && y_ < 3) {
        int idx = x_ * 3 + y_;
        string tt = t;
        swap(tt[c], tt[idx]);
        if (!d.count(tt)) {
          d[tt] = d[t] + 1;
          q.push(tt);
        }
      }
    }
  }
  return -1;
}

int main() {
  char s;
  string state;
  for (int i = 0; i < 9; ++i) {
    cin >> s;
    state += s;
  }
  cout << bfs(state) << endl;
}
