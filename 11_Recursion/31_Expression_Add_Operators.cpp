// Expression Add Operators
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given a string num that contains only digits and an integer target, return
// all possibilities to insert the binary operators '+', '-', and/or '*' between
// the digits of num so that the resultant expression evaluates to the target
// value.

// Note that operands in the returned expressions should not contain leading
// zeros.

// Note that a number can contain multiple digits.

// Example 1:

// Input: num = "123", target = 6
// Output: ["1*2*3","1+2+3"]
// Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
// Example 2:

// Input: num = "232", target = 8
// Output: ["2*3+2","2+3*2"]
// Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
// Example 3:

// Input: num = "3456237490", target = 9191
// Output: []
// Explanation: There are no expressions that can be created from "3456237490"
// to evaluate to 9191.
#include <bits/stdc++.h>
using namespace std;

void solve(string s, int target, int i, const string &path,
           long eval,     // current evaluated value
           long residual, // last operand (for handling *)
           vector<string> &result) {

  // If we've consumed all digits
  if (i == s.size()) {
    if (eval == target) {
      result.push_back(path);
    }
    return;
  }

  string currStr;
  long num = 0;

  // Try all possible splits starting at index i
  for (int j = i; j < s.size(); j++) {

    // Prevent numbers with leading zero
    // "05", "00" are invalid
    if (j > i && s[i] == '0')
      return;

    currStr += s[j];
    num = num * 10 + (s[j] - '0');

    // First number → no operator before it
    if (i == 0) {
      solve(s, target, j + 1,
            currStr, // path starts with number
            num,     // eval = num
            num,     // residual = num
            result);
    } else {

      // Addition
      solve(s, target, j + 1, path + "+" + currStr, eval + num, num, result);

      // Subtraction
      solve(s, target, j + 1, path + "-" + currStr, eval - num, -num, result);

      // Multiplication
      // Remove last operand and replace with (residual * num)
      solve(s, target, j + 1, path + "*" + currStr,
            eval - residual + residual * num, residual * num, result);
    }
  }
}

vector<string> addOperators(string num, int target) {
  vector<string> result;
  solve(num, target, 0, "", 0, 0, result);
  return result;
}

int main() {
  string num = "123";
  int target = 6;

  vector<string> result = addOperators(num, target);
  for (auto &expr : result) {
    cout << expr << " ";
  }
  return 0;
}
