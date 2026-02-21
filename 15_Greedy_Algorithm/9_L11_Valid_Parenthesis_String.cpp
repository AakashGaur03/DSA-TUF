#include <bits/stdc++.h>
using namespace std;

bool validParenthesisStringRecursive(string s, int index, int cnt) {
  // TC O(3^N)
  // SC O(N) // Auxiliary Stack Space
  int size = s.size();
  if (cnt < 0)
    return false;

  if (index == size) {
    return cnt == 0;
  }
  if (s[index] == '(') {
    return validParenthesisStringRecursive(s, index + 1, cnt + 1);
  } else if (s[index] == ')') {
    return validParenthesisStringRecursive(s, index + 1, cnt - 1);
  } else {                                                            // *
    return (validParenthesisStringRecursive(s, index + 1, cnt + 1) || // '('
            validParenthesisStringRecursive(s, index + 1, cnt - 1) || // ')'
            validParenthesisStringRecursive(s, index + 1, cnt));      // ' '
  }
}

bool validParenthesisStringOptimal(string s) {
  // TC O(N)
  // SC O(1)
  // We will be maintiaing Range
  // 9_L11_Valid_Parenthesis_String_2

  /*
  Idea:
  Instead of fixing '*' as '(' or ')' immediately,
  we maintain a RANGE of possible open brackets.

  minOpen -> minimum possible '(' still open
  maxOpen -> maximum possible '(' still open

  Because '*' can behave as:
      '('  OR  ')'  OR  empty
*/
  int size = s.size();
  int min = 0; // lowest possible open bracket count
  int max = 0; // highest possible open bracket count
  for (int i = 0; i < size; i++) {

    // Case 1: '(' increases both possibilities
    if (s[i] == '(') {
      min = min + 1;
      max = max + 1;
    }
    // Case 2: ')' decreases both possibilities
    else if (s[i] == ')') {
      min = min - 1;
      max = max - 1;
    }
    // Case 3: '*' -> can be '(', ')' or empty
    else {
      min = min - 1; // assume '*' acts as ')'
      max = max + 1; // assume '*' acts as '('
    }

    /*
      minOpen cannot be negative.
      If negative, we treat some '*' as empty string
    */
    if (min < 0)
      min = 0;
    /*
      If maxOpen < 0:
      Even in best case we have more ')' than '('
      => impossible to fix
    */
    if (max < 0)
      return false;
  }

  /*
    At the end:
    minOpen == 0 → we can close all brackets
    minOpen > 0  → some '(' left unmatched
  */
  return (min == 0);
}
int main() {
  cout << "9 L11 Valid Parenthesis String" << endl;
  string s = "()";
  // string s = "(*)";
  // string s = "(*))";
  // string s = "(**(";
  // A string can have ( or ) or *
  // * means its upto us to replace * with empty string or ( or )
  // after replacing we need to tell if string is valid Parenthesis or not
  // Refer 9_L11_Valid_Parenthesis_String_1

  cout << validParenthesisStringRecursive(s, 0, 0) << endl;
  // Better way is Memoization that is DP
  // Then recursive will convert it into TC and SC O(N^2)
  // WE havent Done it so far

  cout << validParenthesisStringOptimal(s) << endl;

  return 0;
}
