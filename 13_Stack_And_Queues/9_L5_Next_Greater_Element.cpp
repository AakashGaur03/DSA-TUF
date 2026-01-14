#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterBrute(vector<int> arr) {
  // TC O(n^2)
  // SC O(n)
  vector<int> res;

  for (int i = 0; i < arr.size(); i++) {
    int nextGreater = -1;
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] > arr[i]) {
        nextGreater = arr[j];
        break;
      }
    }
    res.push_back(nextGreater);
  }
  return res;
}

vector<int> nextGreaterOptimized(vector<int> arr) {
  // TC O(N + N)
  // TC O(2N)

  // Appraoch is We start from the back
  // We take a stack to store the greater elements
  // if we get a higher element than the current top
  // we pop out elements till stack is empty or greater in stack
  // Refer to 9_L5_Next_Greater_Element_Optimized_1

  // HERE WE ARE STORING IN DECREASING ORDER
  // MONOTONIC STACK
  stack<int> st;
  vector<int> res(
      arr.size()); // requied because we are storing answers in reverse
  for (int i = arr.size() - 1; i >= 0; i--) {
    while (!st.empty() && st.top() <= arr[i]) {
      st.pop();
    }
    if (st.empty()) {
      res[i] = -1;
      st.push(arr[i]);
    } else {
      res[i] = st.top();
      st.push(arr[i]);
    }
  }
  return res;
}
int main() {
  cout << "9 L5 Next Greater Element" << endl;
  // Concept of Monotonic Stack comes in
  // When we store elements in a stack in 'SPECIFIC ORDER' it is called
  // Monotonic Stack

  vector<int> arr = {6, 0, 8, 1, 3};
  //                 8, 8,-1, 3, -1

  vector<int> res = nextGreaterBrute(arr);
  for (int x : res)
    cout << x << " ";

  cout << endl;
  vector<int> res2 = nextGreaterOptimized(arr);
  for (int x2 : res2)
    cout << x2 << " ";
  return 0;
}