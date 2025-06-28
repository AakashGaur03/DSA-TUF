#include <iostream>
#include <string>
using namespace std;
// void function
// Non Parameterised Function
void printName() { cout << "Aakash" << endl; }

// Parameterised Function
void printCustomName(string name) { cout << name << endl; }

int sumNumbers(int num1, int num2) { return num1 + num2; }

// Pass by Value
void doSometing(int num) {
  cout << num << endl;
  num += 5;
  num += 5;
  cout << num << endl;
}

// Pass by Reference
void doSometingReference(int &num2) {
  cout << num2 << endl;
  num2 += 5;
  num2 += 5;
  cout << "Inside Func : " << num2 << endl;
}
int main() {
  cout << "Hi" << endl;

  int x;
  cin >> x;
  cout << "Val :" << x << endl;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  cout << "String is :" << s1 << s2 << endl;
  cin.ignore();

  string str;
  getline(cin, str);
  cout << str << endl;
  cout << "Hi" << endl;

  string s = "Aakash";
  int len = s.size();
  cout << s[0] << endl;
  cout << s[4] << endl;
  cout << s[len - 1] << endl;

  // For loop
  for (int i = 0; i < 5; i++) {
    cout << "Hi" << endl;
  }

  // While Loop
  int i;
  while (i < 5) {
    cout << "Hloe" << endl;
    i++;
  }

  // DO While Loop
  i = 206;
  do {
    cout << "Whatt" << endl;
  } while (i < 2);

  // Functions
  printName();
  printName();
  printCustomName("Raj");
  printCustomName("SAM");
  int num1, num2;
  cin >> num1 >> num2;
  cout << sumNumbers(num1, num2);

  int num = 5;
  doSometing(num);
  cout << num << endl;

  int someNum = 5;
  doSometingReference(someNum);
  cout << "Out Func : " << someNum << endl;

  // In C++, arrays are passed by reference by default (as pointers to their
  // first element). For other types like int, string, list, map, and vector,
  // you need to explicitly pass them by reference using the & symbol if you
  // want to avoid copying.
  return 0;
}