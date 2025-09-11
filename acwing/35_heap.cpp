#include <iostream>
#include <type_traits>
using namespace std;

const int N = 1e5 + 10;

int h[N], cnt;
int hp[N], ph[N];
// hp heap -> point 堆内的第几个元素是第几个插入的，
// ph point -> heap 第几个插入的元素在堆的那个位置

void h_swap(int a, int b) {  // a b 为heap中的位置
  swap(ph[hp[a]], ph[hp[b]]);
  swap(hp[a], hp[b]);
  swap(h[a], h[b]);
}

void down(int u) {
  int t = u;
  if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
  if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
  if (u != t) {
    h_swap(u, t);
    down(t);
  }
}

void up(int u) {
  while (u / 2 && h[u] < h[u / 2]) {
    h_swap(u / 2, u);
    u >>= 1;
  }
}

int main() {
  int n, m = 0;
  cin >> n;
  while (n--) {
    string op;
    int x, k;
    cin >> op;
    if (op == "I") {
      cin >> x;
      ++cnt;
      ++m;
      ph[m] = cnt;
      hp[cnt] = m;
      h[cnt] = x;
      up(cnt);
    } else if (op == "PM") {
      cout << h[1] << endl;
    } else if (op == "DM") {
      h_swap(1, cnt--);
      down(1);
    } else if (op == "D") {
      cin >> k;
      k = ph[k];
      h_swap(k, cnt--);
      up(k);
      down(k);
    } else if (op == "C") {
      cin >> k >> x;
      k = ph[k];
      h[k] = x;
      up(k);
      down(k);
    }
  }
}