#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int h[N], cnt;

void down(int u) {
  int t = u;  // t为最值节点的位置
  // 两个if找出 当前节点和他的两个子节点的最值
  if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
  if (u * 2 + 1 <= cnt && h[u * 2 + 1] <= h[t]) t = u * 2 + 1;
  if (u != t) {  //如果交换了要维护交换后的堆的大小顶性质
    swap(h[u], h[t]);
    down(t);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> h[i];
  cnt = n;
  for (int i = n / 2; i >= 1; --i) down(i);

  while (m--) {
    cout << h[1] << " ";
    //换一个最大的数字上来，在对更新后的位置进行一次堆排序确保任然满足此性质,
    //同时小顶堆实现降序，大顶堆实现升序
    swap(h[1], h[cnt--]);
    down(1);
  }
}