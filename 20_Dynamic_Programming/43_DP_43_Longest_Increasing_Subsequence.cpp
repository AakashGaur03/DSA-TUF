
#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr) {
  // TC O(N logN)
  // SC O(N)
  // Note temp is not LIS correct state it just stores the correct lengths
  int n = arr.size();

  if (n == 0) {
    return 0;
  }
  vector<int> temp;
  temp.push_back(arr[0]);
  int len = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] > temp.back()) {
      temp.push_back(arr[i]);
      len++;
    } else {
      int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
      temp[ind] = arr[i];
    }
  }
  return len;
}
int main() {

  cout << "43 DP 43 Prinitng Longest Increasing Subsequence" << endl;

  // Longest Increasing Subsequence
  // Given an integer array nums, return the length of the longest strictly
  // increasing subsequence.

  // A subsequence is a sequence derived from an array by deleting some or no
  // elements without changing the order of the remaining elements. For example,
  // [3, 6, 2, 7] is a subsequence of [0, 3, 1, 6, 2, 2, 7].

  // The task is to find the length of the longest subsequence in which every
  // element is greater than the previous one.

  // Example 1:
  // Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]

  // Output: 4

  // Explanation: The longest increasing subsequence is [2, 3, 7, 101], and its
  // length is 4.

  // Example 2:
  // Input: nums = [0, 1, 0, 3, 2, 3]

  // Output: 4

  // Explanation: The longest increasing subsequence is [0, 1, 2, 3], and its
  // length is 4
  // Example 1
  vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};

  cout << "\nExample 1:" << endl;
  cout << "Answer: " << LIS(nums1) << endl;

  // Example 2
  vector<int> nums2 = {0, 1, 0, 3, 2, 3};

  cout << "\nExample 2:" << endl;
  cout << "Answer: " << LIS(nums2) << endl;

  // we can use Lower Bound here Binary Search
  // So the intuition os we just need length of the LIS so we will replace the
  // numbers and that we can do using Lower Bound
  //  Current element cannot increase the length. // // Find the first element
  // in temp which is // greater than or equal to arr[i]. // // This is Lower
  // Bound and uses Binary Search. // // We replace that element with arr[i]. //
  // // Why?
  // A smaller tail gives us a better chance // to extend the
  // subsequence in the future.

  return 0;
}