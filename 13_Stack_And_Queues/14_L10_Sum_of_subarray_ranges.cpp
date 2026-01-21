#include <bits/stdc++.h>
using namespace std;

int SumofSubarrayRangesBrute(vector<int> arr) {
  // TC O(N^2)
  // SC O(1)
  // Generate all sub array
  // Get minimum and maximumof each
  // Add the subtracted part
  int size = arr.size();
  int sum = 0;
  for (int i = 0; i < size; i++) {
    int mini = arr[i];
    int maxi = arr[i];
    for (int j = i + 1; j < size; j++) {
      mini = min(mini, arr[j]);
      maxi = max(maxi, arr[j]);
      sum = (sum + (maxi - mini));
    }
  }
  return sum;
}

vector<int> findNSE(vector<int> arr) {
  // TC O(N + N)
  // TC O(2N)

  int n = arr.size();
  stack<int> st;
  vector<int> res(n);

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i]) {
      st.pop();
    }
    res[i] = st.empty() ? n : st.top();
    st.push(i);
  }
  return res;
}

vector<int> prevSmallerOrEqual(vector<int> arr) {
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
    while (!st.empty() && arr[st.top()] > arr[i]) {
      st.pop();
    }
    res[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  return res;
}

int SumofSubarrayMinimumOptimized(vector<int> arr) {
  // TC O(5N)
  // SC O(5N)
  // Approach is to find out indiviual contribution
  // and then summing up for res
  // Refer to 13_L9_Sum_of_Subarray_Minimum_2
  // Refer to 13_L9_Sum_of_Subarray_Minimum_3
  // In image PSE refers to Previous Smaller Element
  // In image NSE refers to Next Smaller Element
  vector<int> nse = findNSE(arr);            // TC O(2N)
  vector<int> pse = prevSmallerOrEqual(arr); // TC O(2N)
  int total = 0;
  int mod = (int)(1e9 + 7);
  int size = arr.size();
  for (int i = 0; i < size; i++) { // TC O(N)
    int left = i - pse[i];
    int right = nse[i] - i;
    total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
  }
  return total;
}

vector<int> findNGE(vector<int> arr) {
  int n = arr.size();
  stack<int> st;
  vector<int> res(n);

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] <= arr[i]) {
      st.pop();
    }
    res[i] = st.empty() ? n : st.top();
    st.push(i);
  }
  return res;
}

vector<int> prevGreaterOrEqual(vector<int> arr) {
  stack<int> st;
  vector<int> res(arr.size());
  for (int i = 0; i < arr.size(); i++) {
    while (!st.empty() && arr[st.top()] < arr[i]) {
      st.pop();
    }
    res[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  return res;
}

int SumofSubarrayMaximumOptimized(vector<int> arr) {
  // Approach is to find out indiviual contribution
  // and then summing up for res

  vector<int> nge = findNGE(arr);
  vector<int> pge = prevGreaterOrEqual(arr);
  int total = 0;
  int mod = (int)(1e9 + 7);
  int size = arr.size();
  for (int i = 0; i < size; i++) { // TC O(N)
    int left = i - pge[i];
    int right = nge[i] - i;
    total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
  }
  return total;
}

int SumofSubarrayRangesOptimized(vector<int> arr) {
  // TC O(N)
  // SC O(N)

  int mod = (int)(1e9 + 7);
  int SumOfAllMaxi = SumofSubarrayMaximumOptimized(arr);
  int SumOfAllMini = SumofSubarrayMinimumOptimized(arr);

  // It normalizes the subtraction back into valid modulo range
  return (SumOfAllMaxi - SumOfAllMini + mod) % mod;
}
int main() {
  cout << "14_L10_Sum_of_subarray_ranges" << endl;
  // We have to get all subarrays Get minimum and maximum of each subarray and
  // adding (max-min) for all of them and return added value
  // Refer 14_L10_Sum_of_subarray_ranges_1

  vector<int> arr = {1, 4, 3, 2};
  int res = SumofSubarrayRangesBrute(arr);
  cout << res << endl;

  int res4 = SumofSubarrayRangesOptimized(arr);
  cout << res4 << endl;

  return 0;
}
