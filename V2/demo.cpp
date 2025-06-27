#include <iostream>
#include <string>
using namespace std;

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
  cout << "Hi";
  return 0;
}