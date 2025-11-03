#include <bits/stdc++.h>
using namespace std;

void parameterizedSumNNumbers(int i, int sum) {
  if (i < 1) {
    cout << sum;
    return;
  }
  parameterizedSumNNumbers(i - 1, sum + i);
}

int functionalsumOfNNumbers(int n) {
  if (n < 1)
    return 0;

  return n + functionalsumOfNNumbers(n - 1);
}
int factorialOfNNumbers(int n) {
  if (n <= 1)
    return 1;

  return n * functionalsumOfNNumbers(n - 1);
}
int main() {
  cout << "3 Re 3 Parameterised and Functional Recursion" << endl;
  int n;
  cin >> n;
  // Sum of N Numbers

  // parameterized way
  parameterizedSumNNumbers(n, 0);
  cout << endl;
  // // Functional way
  int res = functionalsumOfNNumbers(n);
  cout << res;
  cout << endl;
  int res2 = factorialOfNNumbers(n);
  cout << res2;
  return 0;
}