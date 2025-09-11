#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> &A, vector<int> &B) {
  if (A.size() != B.size()) return A.size() > B.size();

  for (int i = A.size() - 1; i >= 0; --i) {
    if (A[i] != B[i]) return A[i] > B[i];
  }
  return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size(); ++i) {
    t = A[i] - t;
    if (i < B.size()) t -= B[i];
    C.push_back((t + 10) % 10);
    t = t < 0 ? 1 : 0;
  }
  while (C.size() > 1 && C.back() == 0) C.pop_back();
  return C;
}

vector<int> div(vector<int> &A, int B, int &r) {
  vector<int> C;
  r = 0;
  for (int i = A.size() - 1; i >= 0; --i) {
    r = r * 10 + A[i];
    C.push_back(r / B);
    r %= B;
  }
  reverse(C.begin(), C.end());
  while (C.size() > 1 && C.back() == 0) C.pop_back();
  return C;
}

int main() {
  string a;
  vector<int> A;
  int B;
  cin >> a >> B;
  for (int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');
  vector<int> C;
  int r;
  C = div(A, B, r);
  for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
  cout << endl << r << endl;
}