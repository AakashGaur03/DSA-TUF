#include <bits/stdc++.h>
using namespace std;
bool checkForBalancedParenthese(string s) {
  // TC O(N)
  // SC O(S)
  stack<char> st;

  for (int i = 0; i < s.size(); i++) {
    char ch = s[i];
    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else {
      if (st.empty())
        return false;

      if (ch == ')' && st.top() == '(')
        st.pop();
      else if (ch == '}' && st.top() == '{')
        st.pop();
      else if (ch == ']' && st.top() == '[')
        st.pop();
      else
        return false;
    }
  }
  return st.empty();
}
int main() {
  cout << "4 L2 Check for Balanced Parentheses" << endl;
  //   string s = "()[{}()]";
  string s = "()[{}(])"; // False
  cout << checkForBalancedParenthese(s);
  return 0;
}