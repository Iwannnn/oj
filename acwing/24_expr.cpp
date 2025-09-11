#include <cctype>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num;
stack<char> op;

void compute() {  //同一计算
  auto b = num.top();
  num.pop();
  auto a = num.top();
  num.pop();
  auto c = op.top();
  op.pop();
  int x;
  if (c == '+')
    x = a + b;
  else if (c == '-')
    x = a - b;
  else if (c == '*')
    x = a * b;
  else
    x = a / b;
  num.push(x);
}

int main() {
  unordered_map<char, int> opp{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
  string expr;
  cin >> expr;
  for (int i = 0; i < expr.size(); ++i) {
    auto c = expr[i];
    if (isdigit(c)) {
      int x = 0, j = i;
      while (j < expr.size() && isdigit(expr[j]))
        x = x * 10 + (expr[j++] - '0');
      i = j - 1;
      num.push(x);
    } else if (c == '(')
      op.push(c);
    else if (c == ')') {
      while (op.top() != '(') compute();
      op.pop();
    } else {
      while (op.size() && op.top() != '(' && opp[op.top()] >= opp[c]) compute();
      op.push(c);
    }
  }
  while (op.size()) compute();
  cout << num.top() << endl;
}