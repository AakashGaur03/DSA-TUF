#include <bits/stdc++.h>
using namespace std;

void recursiveAllBinartStrings(int index, bool canOneBePlaced, string str,
                               int n, vector<string> &arr) {
  if (index == n) {
    arr.push_back(str);
    return;
  }

  recursiveAllBinartStrings(index + 1, true, str + "0", n, arr);
  if (canOneBePlaced) {
    recursiveAllBinartStrings(index + 1, false, str + "1", n, arr);
  }
}

void generateAllBinartStrings(int n, vector<string> &arr) {

  recursiveAllBinartStrings(0, true, "", n, arr);
}

int main() {

  // Generate all binary strings
  // Problem Statement: Given an integer n, return all binary strings of length
  // n that do not contain consecutive 1s. Return the result in
  // lexicographically increasing order.

  // A binary string is a string consisting only of characters '0' and '1'.
  // Example 1:
  // Input:
  //  n = 3
  // Output:
  //  ["000", "001", "010", "100", "101"]
  // Explanation:
  //  All binary strings of length 3 that do not contain consecutive 1s.

  // Example 2:
  // Input:
  //  n = 2
  // Output:
  //  ["00", "01", "10"]
  // Explanation:
  //  All binary strings of length 2 that do not contain consecutive 1s.

  cout << "27 Generate All Binary Strings" << endl;
  int n = 4;
  vector<string> arr;
  generateAllBinartStrings(n, arr);

  for (auto &s : arr) {
    cout << s << endl;
  }
  return 0;
}
