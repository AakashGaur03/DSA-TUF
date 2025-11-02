#include <bits/stdc++.h>
using namespace std;

void printSomething() {
  cout << "Something" << endl;
  printSomething();
  // Segmentation fault happens called Stack overflow
  // This is an example of Infinte Recursion
  // Condition used to stop recursion is called Base Condition
}
int cnt = 0;
void printSomething5Times() {
  // Base Condition
  if (cnt >= 5) {
    return;
  }
  cnt++;
  cout << "Something" << endl;
  printSomething5Times();
}
void printSomething5TimesWithoutGlobal(int &counter) {
  // Base Condition
  if (counter >= 5) {
    return;
  }
  counter++;
  cout << "Something 2" << endl;
  printSomething5TimesWithoutGlobal(counter);
}

int main() {
  cout << "1 Re 1 Introduction to Recursion" << endl;
  // When a funciton calls itself until a specified condition is met
  // it is called Recursion

  //   printSomething();
  printSomething5Times();
  int counter = 0;
  printSomething5TimesWithoutGlobal(counter);
  return 0;
}