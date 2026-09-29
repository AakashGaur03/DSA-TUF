
#include <bits/stdc++.h>
using namespace std;

// For all the other apporaches we need to make each
// RecursionInc RecursionDec
// MemoizationInc MemoizationDec
// TabulationInc TabulationDec
// To solve this

int recursionInc(int ind, vector<int> &nums) {
  if (ind == 0) {
    return 1;
  }

  int maxi = 1;
  for (int prev = 0; prev < ind; prev++) {
    if (nums[prev] < nums[ind]) {
      maxi = max(maxi, 1 + recursionInc(prev, nums));
    }
  }
  return maxi;
}

int recursionDec(int ind, vector<int> &nums) {
  int n = nums.size();

  if (ind == n - 1) {
    return 1;
  }

  int maxi = 1;
  for (int next = ind + 1; next < n; next++) {
    if (nums[next] < nums[ind]) {
      maxi = max(maxi, 1 + recursionDec(next, nums));
    }
  }
  return maxi;
}

int recursionBitonic(vector<int> &nums) {
  int n = nums.size();
  int maxi = 0;

  for (int i = 0; i < n; i++) {
    int inc = recursionInc(i, nums);
    int dec = recursionDec(i, nums);

    maxi = max(maxi, inc + dec - 1);
  }
  return maxi;
}

int spaceOptimziation2ndApporach(vector<int> &nums) {
  // Refer 42_DP_42_Prinitng_Longest_Increasing_Subsequence_1
  int n = nums.size();
  vector<int> dp1(n, 1);
  for (int i = 0; i < n; i++) {
    for (int prev = 0; prev < i; prev++) {
      if (nums[prev] < nums[i]) {
        dp1[i] = max(dp1[i], 1 + dp1[prev]);
      }
    }
  }

  vector<int> dp2(n, 1);
  for (int i = n - 1; i >= 0; i--) {
    for (int prev = n - 1; prev > i; prev--) {
      if (nums[prev] < nums[i]) {
        dp2[i] = max(dp2[i], 1 + dp2[prev]);
      }
    }
  }

  int maxi = 0;
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, dp1[i] + dp2[i] - 1);
  }
  return maxi;
}

int LongestBitonicSequence(vector<int> arr) {

  int n = arr.size();

  if (n == 0) {
    return 0;
  }

  // Recursion
  int ans1 = recursionBitonic(arr);

  // Space Optimization 2nd Approach
  int ans2 = spaceOptimziation2ndApporach(arr);

  cout << "Recursion: " << ans1 << endl;
  cout << "Space Optimization 2nd Approach: " << ans2 << endl;

  return ans2;
}

// | Approach                          |                     Time |      Space |
// | --------------------------------- | -----------------------: | ---------: |
// | Recursion                         |              Exponential | O(N) stack |
// | Memoization                       |                    O(N²) |       O(N) |
// | Tabulation                        |                    O(N²) |       O(N) |
// |  spaceOptimziation (ind, prevInd) | Not naturally applicable |          — |
// | 2nd approach ( dp1 + dp2 )        |                    O(N²) |       O(N) |

int main() {

  cout << "46 DP 46 Longest Bitonic Subsequence" << endl;
  //   Longest Bitonic Subsequence
  // Given an array arr of n integers, the task is to find the length of the
  // longest bitonic sequence. A sequence is considered bitonic if it first
  // increases, then decreases. The sequence does not have to be contiguous.

  // Example 1:
  // Input: arr = [5, 1, 4, 2, 3, 6, 8, 7]

  // Output: 6

  // Explanation: The longest bitonic sequence is [1, 2, 3, 6, 8, 7] with
  // length 6.

  // Example 2:
  // Input: arr = [10, 20, 30, 40, 50, 40, 30, 20]

  // Output: 8

  // Explanation: The entire array is bitonic, increasing up to 50 and then
  // decreasing.

  // Biotonic means Numbers First increase and then decrease
  // It can also be Only Increasing
  // It can also be Only Decreasing

  // Approach we are taking is that we get the LIS from start we get the LIS
  // from end then we take the bitonic that is dp1[i] + dp2[i] - 1 and we need
  // max value from there
  // Refer
  // 46_DP_46_Longest_Bitonic_Subsequence_1

  // Example 1
  vector<int> arr1 = {5, 1, 4, 2, 3, 6, 8, 7};

  cout << "\nExample 1:" << endl;

  int answer1 = LongestBitonicSequence(arr1);

  cout << "Final Answer: " << answer1 << endl;

  // Example 2
  vector<int> arr2 = {10, 20, 30, 40, 50, 40, 30, 20};

  cout << "\nExample 2:" << endl;

  int answer2 = LongestBitonicSequence(arr2);

  cout << "Final Answer: " << answer2 << endl;

  return 0;
}