#include <iostream>

using namespace std;

const int M = 110;
int N, V;
int s[M];
int v[M][M], w[M][M];
int f[M];

int main() {
  cin >> N >> V;
  for (int i = 1; i <= N; ++i) {
    cin >> s[i];
    for (int j = 1; j <= s[i]; ++j) {
      cin >> v[i][j] >> w[i][j];
    }
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = V; j >= 1; --j) {
      for (int k = 1; k <= s[i]; ++k) {
        if (j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
      }
    }
  }
  cout << f[V] << endl;
}