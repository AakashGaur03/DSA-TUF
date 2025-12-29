#include <bits/stdc++.h>
using namespace std;

// bool validParenthesis(string str) {
//   int cnt = 0;
//   for (int i = 0; i < str.size(); i++) {
//     if (str[i] == '(') {
//       cnt++;
//     }
//     if (cnt > 0 && str[i] == ')') {
//       cnt--;
//     } else if (cnt == 0 && str[i] == ')') {
//       return false;
//     }
//   }

//   return cnt == 0;
// }

// void recursiveAllParenthesis(int index, string str, int n,
//                              vector<string> &arr) {
// TC O(2^(2N) * N)
// 2^(2N) for Generating all parenthesis and then N for validating it
//   if (index == 2 * n) {
//     if (validParenthesis(str)) {
//       arr.push_back(str);
//     }
//     return;
//   }

//   recursiveAllParenthesis(index + 1, str + "(", n, arr);
//   recursiveAllParenthesis(index + 1, str + ")", n, arr);
// }

// void generateAllParenthesis(int n, vector<string> &arr) {

//   recursiveAllParenthesis(0, "", n, arr);
// }

void recursiveAllParenthesis(int open, int close, string str, int n,
                             vector<string> &arr) {

  // TC O(Catalan(n)), which is approximately O(4^n / √n).”
  //  Only valid are geenrated
  if (str.size() == 2 * n) {
    arr.push_back(str);
    return;
  }
  if (open < n) {
    recursiveAllParenthesis(open + 1, close, str + "(", n, arr);
  }
  if (close < open) {
    recursiveAllParenthesis(open, close + 1, str + ")", n, arr);
  }
}

void generateAllParenthesis(int n, vector<string> &arr) {

  recursiveAllParenthesis(0, 0, "", n, arr);
}

int main() {

  // Generate Paranthesis

  // Problem Statement: Given n pairs of parentheses, write a function to
  // generate all combinations of well-formed parentheses.

  //  Example 1:
  // Input:
  //  n = 3
  // Output:
  //  ["((()))", "(()())", "(())()", "()(())", "()()()"]

  // Example 2:
  // Input:
  //  n = 1
  // Output:
  //  ["()"]

  cout << "28 Generate Parenthesis" << endl;
  int n = 2;
  vector<string> arr;
  generateAllParenthesis(n, arr);

  for (auto &s : arr) {
    cout << s << endl;
  }
  return 0;
}
