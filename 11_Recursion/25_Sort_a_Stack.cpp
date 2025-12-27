#include <bits/stdc++.h>
using namespace std;

void recursiveAddInStack(vector<int> &arr, stack<int> &st, int index) {

  if (index == arr.size()) {
    return;
  }
  int curr = arr[index];

  // Temporarily hold elements greater than curr
  stack<int> temp;

  while (!st.empty() && st.top() > curr) {
    temp.push(st.top());
    st.pop();
  }

  // Insert current element
  st.push(curr);

  // Restore popped elements
  while (!temp.empty()) {
    st.push(temp.top());
    temp.pop();
  }

  // Process next element
  recursiveAddInStack(arr, st, index + 1);
}

void sortStackUsingRecursion(stack<int> &st) {
  vector<int> arr;
  while (!st.empty()) {
    arr.push_back(st.top());
    st.pop();
  }

  recursiveAddInStack(arr, st, 0);
}

void insertSorted(stack<int> &st, int element) {

  if (st.empty() || st.top() <= element) {
    st.push(element);
    return;
  }
  int top = st.top();
  st.pop();
  insertSorted(st, element);
  st.push(top);
}

void sortStackUsingPureRecursion(stack<int> &st) {
  if (st.empty()) {
    return;
  }

  int top = st.top();
  st.pop();
  // Basically this empties out the Stack Initially
  sortStackUsingPureRecursion(st);
  // This inserts sorted part
  insertSorted(st, top);
}

int main() {
  // Example 1:
  // Input:
  //  stack = [4, 1, 3, 2]
  // Output:
  //  [4, 3, 2, 1]
  // Explanation:
  //  After sorting, the largest element (4) is at the top, and the smallest (1)
  //  is at the bottom.

  // Example 2:
  // Input:
  //  stack = [1]
  // Output:
  //  [1]
  cout << "25 Sort a Stack Using Recursion" << endl;

  stack<int> s;
  s.push(4);
  s.push(1);
  s.push(3);
  s.push(2);

  sortStackUsingRecursion(s);

  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  stack<int> s2;
  s2.push(4);
  s2.push(1);
  s2.push(3);
  s2.push(2);

  cout << endl;
  sortStackUsingPureRecursion(s2);
  while (!s2.empty()) {
    cout << s2.top() << " ";
    s2.pop();
  }
  return 0;
}
