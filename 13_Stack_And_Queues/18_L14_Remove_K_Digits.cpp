#include <bits/stdc++.h>
using namespace std;

string removeKDigits(string num, int k) {
  // TC O(N + K + N + N)
  // SC O(N + N)
  // We will be iterating over the string
  // We will check if theres a value that is less then
  // top of stack we pop out the top value
  string res = "";
  int size = num.size();
  stack<char> st;
  for (int i = 0; i < size; i++) { // O(N)

    while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) { // O(N)
      st.pop();
      k--;
    }
    st.push(num[i]);
  }
  while (!st.empty() && k > 0) { // O(K)
    st.pop();
    k--;
  }

  // O(N)
  while (!st.empty()) {
    res += st.top();
    st.pop();
  }

  while (res.size() != 0 && res.back() == '0') {
    res.pop_back();
  }
  reverse(res.begin(), res.end());
  if (res.empty())
    return "0";

  return res;
}

int main() {
  cout << "18 L14 Remove K Digits" << endl;
  // We will be given a string that has numbers from 0-9
  // Remove K digits so that after removeing K digits
  // we have the smallest numbers
  // REFER 18_L14_Remove_K_Digits_1
  string num = "1432219";
  int k = 3;
  string res = removeKDigits(num, k);
  cout << res << endl;
  return 0;
}
