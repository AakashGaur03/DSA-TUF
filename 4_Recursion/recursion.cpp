#include <bits/stdc++.h>
using namespace std;

// Stack Space stores the function that are yet to be completed
// Recursion
// When a function calls itself until a specified condition is met
void printOne() {
  // Segmentation Error or Stack Overflow
  cout << 1 << endl;
  printOne();
}

// Global Variable
int globalCount = 1;
void printTillFive() {
  if (globalCount > 5) // Base Condtion
    return;
  cout << globalCount << endl;
  globalCount++;
  printTillFive();
}

void printNameNTimes(int i, int n) {
  // TC O(n)
  // SC O(N)
  if (i > n)
    return;
  cout << i << " " << "Aakash" << endl;
  printNameNTimes(i + 1, n);
}

void printLinearlyFrom1ToN(int i, int n) {
  // TC O(n)
  // SC O(N)
  if (i > n)
    return;
  cout << i << endl;
  printLinearlyFrom1ToN(i + 1, n);
}

void printLinearlyFromNTo1(int i, int n) {
  // TC O(n)
  // SC O(N)
  if (i < 1)
    return;
  cout << i << endl;
  printLinearlyFromNTo1(i - 1, n);
}

void printLinearlyFrom1ToNUsingBacTracking(int i, int n) {
  // Bascially we will not do ++
  // Print statement will be after function call
  // Before We were getting 1 2 3 4 5 directly
  // But here If first function call we have 5,5 but we are not printing it then
  // we will have 4,5 then 3,5 then 2,5 then 1,5 then 0,5 so 0,5 returns to the
  // function of 1,5 then prints 1 then this returns to 2,5 prints 2 then
  // returns to 3,5 prints 3 then to 4,5 prints 4 then to 5,5 prints 5
  if (i < 1)
    return;
  printLinearlyFrom1ToNUsingBacTracking(i - 1, n);
  cout << i << endl;
}
void printLinearlyFrom_N_To_1_UsingBacTracking(int i, int n) {
  // Bascially we will not do --
  // Print statement will be after function call
  // Before We were getting 5 4 3 2 1 directly
  // But here If first function call we have 1,5 but we are not printing it then
  // we will have 2,5 then 3,5 then 4,5 then 5,5 then 6,5 so 6,5 returns to the
  // function of 5,5 then prints 5 then this returns to 4,5 prints 4 then
  // returns to 3,5 prints 3 then to 2,5 prints 2 then to 1,5 prints 1
  if (i > n)
    return;
  printLinearlyFrom_N_To_1_UsingBacTracking(i + 1, n);
  cout << i << endl;
}

int main() {
  cout << "Hi Recusion" << endl;
  int n;
  cin >> n;
  // printOne();
  // printTillFive();
  // printNameNTimes(1, n);
  // printLinearlyFrom1ToN(1, n);
  // printLinearlyFromNTo1(n, n);
  // printLinearlyFrom1ToNUsingBacTracking(n, n);
  printLinearlyFrom_N_To_1_UsingBacTracking(1, n);

  return 0;
}