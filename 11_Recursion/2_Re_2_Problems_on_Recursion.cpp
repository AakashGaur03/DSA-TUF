#include <bits/stdc++.h>
using namespace std;

void printNameNTimes(int i, int n) {
  // TC O(N)
  // SC O(N) Stack space
  if (i >= n)
    return;

  cout << "Aakash" << endl;
  printNameNTimes(i + 1, n);
}
void print1toN(int i, int n) {
  // TC O(N)
  // SC O(N) Stack space
  if (i > n)
    return;

  cout << i << endl;
  print1toN(i + 1, n);
}
void printNto1(int i, int n) {
  // TC O(N)
  // SC O(N) Stack space
  if (i > n)
    return;

  cout << n << endl;
  printNto1(i, n - 1);
}

void printNto1_2ndAppraoch(int i, int n) {
  // TC O(N)
  // SC O(N) Stack space
  if (i < 1)
    return;

  cout << i << endl;
  printNto1_2ndAppraoch(i - 1, n);
}
int main() {
  cout << "2 Re 2 Problems on Recursion" << endl;
  int n;
  cin >> n;
  printNameNTimes(0, n);
  print1toN(1, n);
  printNto1(1, n);
  printNto1_2ndAppraoch(n, n);
  return 0;
}