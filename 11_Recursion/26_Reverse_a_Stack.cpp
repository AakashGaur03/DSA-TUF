#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int element) {

  if (st.empty()) {
    st.push(element);
    return;
  }
  int top = st.top();
  st.pop();

  insertAtBottom(st, element);
  st.push(top);
}

void reverseStack(stack<int> &st) {
  if (st.empty()) {
    return;
  }

  int top = st.top();
  st.pop();
  // Basically this empties out the Stack Initially
  reverseStack(st);
  // This inserts Reverse part
  insertAtBottom(st, top);
}

int main() {
  // Example 1:
  // Input:
  //  stack = [4, 1, 3, 2]
  // Output:
  //  [2, 3, 1, 4]

  // Example 2:
  // Input:
  //  stack = [1]
  // Output:
  //  [1]
  cout << "26 Reverse a Stack Using Recursion" << endl;

  stack<int> st;
  st.push(4);
  st.push(1);
  st.push(3);
  st.push(2);

  stack<int> st2;
  st2.push(4);
  st2.push(1);
  st2.push(3);
  st2.push(2);

  cout << endl;
  while (!st2.empty()) {
    cout << st2.top() << " ";
    st2.pop();
  }
  cout << endl;
  reverseStack(st);
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}
