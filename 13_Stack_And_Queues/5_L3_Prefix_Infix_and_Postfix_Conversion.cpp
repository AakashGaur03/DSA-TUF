
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
string reverseStringWithBracketConversion(string s) {
  int i = 0;
  int j = s.size() - 1;

  while (i < j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    if (s[i] == '(')
      s[i] = ')';
    else if (s[i] == ')')
      s[i] = '(';

    if (s[j] == '(')
      s[j] = ')';
    else if (s[j] == ')')
      s[j] = '(';

    i++;
    j--;
  }

  // handle middle character (for odd length)
  if (i == j) {
    if (s[i] == '(')
      s[i] = ')';
    else if (s[i] == ')')
      s[i] = '(';
  }

  return s;
}

string convertInfixToPrefix(string s) {
  // TC O(3N)
  // SC O(N) for Stack
  // s = "(a+b)*c-d+f"
  // REFER TO IMAGE 5_L3_Prefix_Infix_and_Postfix_Conversion_2

  // 3 Step
  // 1. Reverse the Infix
  // 2. Infix to Postfix Conversion with one change
  // 3. Reverse The answer

  // (a+b)*c-d+f
  // STEP 1: Reverse it
  // f + d - c * ) b + a (
  // convert ( to ) and ) to (
  // f + d - c * ( b + a )

  // STEP 2: Infix to Postfix
  // The Slight change is
  // if operator is not ^ we directly push it into the stack
  // means instead of priority(s[i]) <= priority(st.top())
  // we say priority(s[i]) < priority(st.top())

  // Step 3: Again reverse

  s = reverseStringWithBracketConversion(s); // O(N/2)
  int i = 0;
  stack<char> st;
  string ans = "";
  int n = s.size();
  while (i < n) { // O(N)
                  // And inside combined Operations // O(N)
    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
        (s[i] >= '0' && s[i] <= '9')) {
      // means an operand add directly in ans
      ans += s[i];
    } else if (s[i] == '(') {
      st.push(s[i]);
    } else if (s[i] == ')') {
      while (!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      st.pop(); // pop ( at last
    } else {
      if (s[i] == '^') {
        while (!st.empty() && priority(s[i]) <= priority(st.top())) {
          ans += st.top();
          st.pop();
        }
      } else {
        while (!st.empty() && priority(s[i]) < priority(st.top())) {
          ans += st.top();
          st.pop();
        }
      }
      st.push(s[i]);
    }
    i++;
  }
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  ans = reverseStringWithBracketConversion(ans); // O(N/2)
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
  cout << "Original String: " << s << endl;
  cout << "Infix to Postfix: " << convertInfixToPostFix(s) << endl;
  string s2 = "(a+b)*c-d+f";
  // Infix to Prefix
  cout << "Original String: " << s2 << endl;
  cout << "Infix to Prefix: " << convertInfixToPrefix(s2) << endl;

  // HERE WE COVERED
  // Infix to Postfix
  // Infix to Prefix
  // CHECKOUT 6_L3_Prefix_Infix_and_Postfix_Conversion For Further
  return 0;
}
