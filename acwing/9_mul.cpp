#include <iostream>
#include <vector>
using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
  if (A.size() < B.size()) return add(B, A);
  int t = 0;
  vector<int> C;
  for (int i = 0; i < A.size(); ++i) {
    t += A[i];
    if (i < B.size()) t += B[i];
    C.push_back(t % 10);
    t /= 10;
  }
  if (t) C.push_back(t);
  return C;
}
vector<int> mul(vector<int> &A, vector<int> &B) {
  vector<int> C;
  for (int i = 0; i < B.size(); ++i) {
    vector<int> tmp;
    for (int j = 0; j < i; ++j) tmp.push_back(0);
    int t = 0;
    for (int j = 0; j < A.size(); ++j) {
      t += A[j] * B[i];
      tmp.push_back(t % 10);
      t /= 10;
    }
    if (t) tmp.push_back(t);
    if (C.empty())
      C = tmp;
    else
      C = add(C, tmp);
  }
  while (C.size() > 1 && C.back() == 0) C.pop_back();
  return C;
}
int main() {
  string a, b;
  vector<int> A, B;
  cin >> a >> b;
  for (int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');
  for (int i = b.size() - 1; i >= 0; --i) B.push_back(b[i] - '0');
  vector<int> C = mul(A, B);
  for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
  cout << endl;
}