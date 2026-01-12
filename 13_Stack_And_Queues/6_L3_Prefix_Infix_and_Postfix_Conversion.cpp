
#include <bits/stdc++.h>
using namespace std;
bool isOperand(char c) {
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
      (c >= '0' && c <= '9')) {
    return true;
  }
  return false;
}

string convertPostFixToInfix(string s) {
  // TC O(2N)
  // SC O(N)
  // Refer to 6_L3_Prefix_Infix_and_Postfix_Conversion_1

  // PUSH OPERAND INTO THE STACK
  // WHEN ENCOUTNER OPERATOR PICK UP LAST TWO ELEMENTS IN STACK
  // TAKE THEM AND PLACE OPERATOR IN BETWEEN OF THEM
  // WRAP IT IN BRACKET and Loop

  int i = 0;
  stack<string> st;
  int n = s.size();
  while (i < n) { // TC O(N)
    if (isOperand(s[i])) {
      st.push(string(1, s[i]));
    } else {
      string t1 = st.top();
      st.pop();
      string t2 = st.top();
      st.pop();
      string expr = '(' + t2 + s[i] + t1 + ')'; // TC O(N1 + N2)
      st.push(expr);
    }
    i++;
  }
  return st.top();
}

string convertPreFixToInfix(string s) {
  // TC O(2N)
  // SC O(N)
  // Refer to 6_L3_Prefix_Infix_and_Postfix_Conversion_2

  // Start from Back
  // PUSH OPERAND INTO THE STACK
  // WHEN ENCOUTNER OPERATOR PICK UP LAST TWO ELEMENTS IN STACK
  // TAKE THEM AND PLACE OPERATOR IN BETWEEN OF THEM
  // WRAP IT IN BRACKET and Loop

  int i = s.size() - 1;
  stack<string> st;

  while (i >= 0) {
    if (isOperand(s[i])) {
      st.push(string(1, s[i]));
    } else {
      string t1 = st.top();
      st.pop();
      string t2 = st.top();
      st.pop();
      string expr = '(' + t1 + s[i] + t2 + ')';
      st.push(expr);
    }
    i--;
  }
  return st.top();
}

int main() {
  cout << "6 L3 Prefix Infix and Postfix Conversion File 2" << endl;

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
  // Postfix to Infix
  cout << "Original String: " << s << endl;
  cout << "Postfix to Infix: " << convertPostFixToInfix(s) << endl;

  string s2 = "*+PQ-MN";
  // Prefix to Infix
  cout << "Original String: " << s2 << endl;
  cout << "Prefix to Infix: " << convertPreFixToInfix(s2) << endl;

  // HERE WE COVERED
  // Postfix to Infix
  // Prefix to Infix
  // CHECKOUT 7_L3_Prefix_Infix_and_Postfix_Conversion For Further

  return 0;
}
