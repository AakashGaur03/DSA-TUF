#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmallerBrute(vector<int> arr) {
  // TC O(n^2)
  // SC O(n)
  vector<int> res;

  for (int i = 0; i < arr.size(); i++) {
    int prevSmaller = -1;
    for (int j = i - 1; j >= 0; j--) {
      if (arr[j] < arr[i]) {
        prevSmaller = arr[j];
        break;
      }
    }
    res.push_back(prevSmaller);
  }
  return res;
}

vector<int> prevSmallerOptimized(vector<int> arr) {
  // TC O(N + N)
  // TC O(2N)

  // Appraoch is
  // We take a stack to store the smaller elements
  // if we get a smaller element than the current top
  // we pop out elements till stack is empty or lesser in stack
  // Refer to 11_L7_Prev_Samller_Element_Optimized_1

  // HERE WE ARE STORING IN Increasing ORDER
  // MONOTONIC STACK
  stack<int> st;
  vector<int> res(arr.size());
  for (int i = 0; i < arr.size(); i++) {
    while (!st.empty() && st.top() > arr[i]) {
      st.pop();
    }
    res[i] = st.empty() ? -1 : st.top();
    st.push(arr[i]);
  }
  return res;
}
int main() {
  cout << "11 L7 Prev Greater Element" << endl;
  // Concept of Monotonic Stack comes in
  // When we store elements in a stack in 'SPECIFIC ORDER' it is called
  // Monotonic Stack

  vector<int> arr = {5, 7, 9, 6, 7};
  //                 -1,5, 7, 5, 6

  vector<int> res = prevSmallerBrute(arr);
  for (int x : res)
    cout << x << " ";

  cout << endl;
  vector<int> res2 = prevSmallerOptimized(arr);
  for (int x2 : res2)
    cout << x2 << " ";
  return 0;
}