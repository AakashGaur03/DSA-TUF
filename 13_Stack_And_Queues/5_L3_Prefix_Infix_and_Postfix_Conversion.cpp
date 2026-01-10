
#include <bits/stdc++.h>
using namespace std;
int priority(char ch) {
  if (ch == '^')
    return 3;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '+' || ch == '-')
    return 1;
  else
    return -1;
}
string convertInfixToPostFix(string s) {
  // TC O(N) + O(N)
  // SC O(N) + O(N)
  // s = "a+b*(c^d-e)"
  // REFER TO IMAGE 5_L3_Prefix_Infix_and_Postfix_Conversion_1
  // Main Logic is insert everything in stack one by one
  // if operators comes and in stack there is an operator
  // check if current stack top has higher priority then value present
  // in the stack top add top in answer
  // and reove from stack if ( then add and if ) remove any operator till (
  // comes In last check if anything in stack add them in answer
  int i = 0;
  stack<char> st;
  string ans = "";
  int n = s.size();
  while (i < n) {
    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
        (s[i] >= '0' && s[i] <= '9')) {
      // means an operand
      ans += s[i];
    } else if (s[i] == '(') {
      st.push(s[i]);
    } else if (s[i] == ')') {
      while (!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      st.pop(); // to remove ( at last
    } else {
      while (!st.empty() &&
             (priority(s[i]) < priority(st.top()) ||
              (priority(s[i]) == priority(st.top()) && s[i] != '^'))) {
        ans += st.top();
        st.pop();
      }

      st.push(s[i]);
    }
    i++;
  }
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  return ans;
}
int main() {
  cout << "5 L3 Prefix Infix and Postfix Conversion" << endl;

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
  string s = "a+b*(c^d-e)";
  // Infix to Postfix
  cout << convertInfixToPostFix(s);

  return 0;
}
