#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementIIBrute(vector<int> &nums) {
  vector<int> res;
  // TC O(N^2)
  // SC O(N)

  // for (int i = 0; i < nums.size(); i++) {
  //   int j = (i + 1) % nums.size();
  //   int nextGreater = -1;
  //   while (j != i) {
  //     if (nums[j] > nums[i]) {
  //       nextGreater = nums[j];
  //       break;
  //     }
  //     // Refer to 10_L6_Next_Greater_Element_II_Brute_1
  //     j = (j + 1) % nums.size(); // SO to get circular reference
  //   }
  //   res.push_back(nextGreater);
  // }

  for (int i = 0; i < nums.size(); i++) {
    int nextGreater = -1;
    for (int j = i + 1; j < i + nums.size(); j++) {
      // Refer to 10_L6_Next_Greater_Element_II_Brute_1
      int index = j % nums.size();
      if (nums[index] > nums[i]) {
        nextGreater = nums[index];
        break;
      }
    }
    res.push_back(nextGreater);
  }
  return res;
}

vector<int> nextGreaterIIOptimized(vector<int> &arr) {
  // TC O(4N)
  // SC O(2N)
  // Refer to 10_L6_Next_Greater_Element_II_Optimized_1.png
  // and 10_L6_Next_Greater_Element_II_Optimized_2.png
  int n = arr.size();
  vector<int> res(n, -1);
  stack<int> st;
  for (int i = 2 * n - 1; i >= 0; i--) { // TC O(2N)
    int idx = i % n;
    while (!st.empty() && st.top() <= arr[idx]) { // TC O(2N)
      st.pop();
    }
    if (i < n) {
      res[idx] = st.empty() ? -1 : st.top();
    }

    st.push(arr[idx]);
  }
  return res;
}

int main() {
  cout << "910 L6 Next Greater Element II" << endl;
  // Concept of Monotonic Stack comes in
  // When we store elements in a stack in 'SPECIFIC ORDER' it is called
  // Monotonic Stack
  // Same question as previous one But here we look in circular direction too

  vector<int> arr = {6, 0, 8, 1, 3};
  //                 8, 8,-1, 3, -1

  vector<int> res = nextGreaterElementIIBrute(arr);
  for (int x : res)
    cout << x << " ";

  cout << endl;
  vector<int> res2 = nextGreaterIIOptimized(arr);
  for (int x2 : res2)
    cout << x2 << " ";
  return 0;
}