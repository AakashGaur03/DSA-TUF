#include <bits/stdc++.h>
using namespace std;

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

int main() {
  cout << "Hi Recusion" << endl;
  // printOne();
  printTillFive();

  return 0;
}