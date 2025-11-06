#include <bits/stdc++.h>
using namespace std;

// Reverse an Array
void reverseArray(vector<int> &arr, int left, int right) {
  if (left >= right)
    return;
  swap(arr[left], arr[right]);
  reverseArray(arr, left + 1, right - 1);
}

void reverseArraySinglePointer(vector<int> &arr, int i) {
  int n = arr.size();
  if (i >= n - i - 1) // or i >= n/2
    return;
  swap(arr[i], arr[n - i - 1]);
  reverseArraySinglePointer(arr, i + 1);
}

// String is Palindrome or not
bool isPalindromString(string &str, int i) {
  int n = str.size();
  if (i >= n / 2)
    return true;
  if (str[i] != str[n - i - 1])
    return false;
  return isPalindromString(str, i + 1);
}
int main() {
  cout << "4 Re 4 Problems on Functional Recursion" << endl;
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  reverseArray(arr, 0, arr.size() - 1);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
  }
  cout << endl;
  reverseArraySinglePointer(arr, 0);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
  }

  cout << endl;
  string str = "madam";
  cout << isPalindromString(str, 0);

  return 0;
}