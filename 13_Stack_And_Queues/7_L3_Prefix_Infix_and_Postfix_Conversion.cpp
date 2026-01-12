
#include <bits/stdc++.h>
using namespace std;
bool isOperand(char c) {
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
      (c >= '0' && c <= '9')) {
    return true;
  }
  return false;
}

string convertPostFixToPrefix(string s) {
  // TC O(2N)
  // SC O(N)
  // Refer to 7_L3_Prefix_Infix_and_Postfix_Conversion_1

  // PUSH OPERAND INTO THE STACK
  // WHEN ENCOUTNER OPERATOR PICK UP LAST TWO ELEMENTS IN STACK
  // TAKE THEM AND PLACE OPERATOR IN START OF THEM
  // Loop

  int i = 0;
  stack<string> st;
  int n = s.size();
  while (i < n) {
    if (isOperand(s[i])) {
      st.push(string(1, s[i]));
    } else {
      string t1 = st.top();
      st.pop();
      string t2 = st.top();
      st.pop();
      string expr = s[i] + t2 + t1;
      st.push(expr);
    }
    i++;
  }
  return st.top();
}

string convertPreFixToPostfix(string s) {
  // TC O(2N)
  // SC O(N)
  // Refer to 7_L3_Prefix_Infix_and_Postfix_Conversion_2

  // START FROM THE BACK
  // PUSH OPERAND INTO THE STACK
  // WHEN ENCOUTNER OPERATOR PICK UP LAST TWO ELEMENTS IN STACK
  // TAKE THEM AND PLACE OPERATOR IN START OF THEM
  // Loop

  int i = s.size() - 1;
  stack<string> st;
  int n = s.size();
  while (i >= 0) {
    if (isOperand(s[i])) {
      st.push(string(1, s[i]));
    } else {
      string t1 = st.top();
      st.pop();
      string t2 = st.top();
      st.pop();
      string expr = t1 + t2 + s[i];
      st.push(expr);
    }
    i--;
  }
  return st.top();
}

int main() {
  cout << "7 L3 Prefix Infix and Postfix Conversion File 2" << endl;

  // What is Operator / Operand
  // Priority
  // Infix to Postfix
  // Infix to Prefix
  // Postfix to Infix
  // Prefix to Infix
  // Prefix to Postfix
  // Postfix to Prefix

  // Operator is ^ * / + -
  // Operand A-Z a-z or 0 - 9
  // Prioriry Order
  //   ^    ->  3
  //   * /  ->  2
  //   + -  ->  1

  // INFIX EXPRESSION
  // When Expression has Operators in between
  // (p + q) * (m - n)

  // PREFIX EXPRESSION
  // Used in Programming Language LISP and also in TREE DS
  // When Expression has Operators in start
  // *+pq-mn

  // POSTFIX EXPRESSION
  // These are used in Stack Based Calculators
  // When Expression has Operators in end
  // pq+mn-*

  string s = "AB-DE+F*/";
  // Postfix to Prefix

  cout << "Original String: " << s << endl;
  cout << "Postfix to Prefix: " << convertPostFixToPrefix(s) << endl;

  string s2 = "/-AB*+DEF";
  // Prefix to Postfix

  cout << "Original String: " << s2 << endl;
  cout << "Prefix to Postfix: " << convertPreFixToPostfix(s2) << endl;

  // HERE WE COVERED
  // Postfix to Prefix
  // Prefix to Postfix

  return 0;
}
