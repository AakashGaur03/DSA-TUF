
#include <bits/stdc++.h>
using namespace std;

int recursionSol(int ind, int prevInd, vector<int> &nums) {
  int n = nums.size();
  if (ind == n) {
    return 0;
  }

  int pick = 0;
  if (prevInd == -1 || nums[ind] > nums[prevInd]) {
    pick = 1 + recursionSol(ind + 1, ind, nums);
  }

  int notPick = 0 + recursionSol(ind + 1, prevInd, nums);

  return max(pick, notPick);
}
int memoizationSol(int ind, int prevInd, vector<int> &nums,
                   vector<vector<int>> &dp) {
  int n = nums.size();
  if (ind == n) {
    return 0;
  }
  if (dp[ind][prevInd + 1] != -1) {
    return dp[ind][prevInd + 1];
  }

  int pick = 0;
  if (prevInd == -1 || nums[ind] > nums[prevInd]) {
    pick = 1 + memoizationSol(ind + 1, ind, nums, dp);
  }

  int notPick = 0 + memoizationSol(ind + 1, prevInd, nums, dp);

  return dp[ind][prevInd + 1] = max(pick, notPick);
}

int LIS(vector<int> &nums) {

  int n = nums.size();

  // Recursion
  int ans1 = recursionSol(0, -1, nums);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  int ans2 = memoizationSol(0, -1, nums, dp);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;

  return ans2;
}

// | Approach        | Time Complexity | Space Complexity |
// | --------------- | --------------: | ---------------: |
// |   Recursion     |        O(2^N)   |           O(N)   |
// |   Memoization   |         O(N²)   |   O(N²) + O(N)   |

int main() {

  cout << "41 DP 41 Longest Increasing Subsequence" << endl;

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

  return 0;
}