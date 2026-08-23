#include <bits/stdc++.h>
using namespace std;

bool recursionSol(int ind, int target, vector<int> &arr) {
  if (target == 0)
    return true;
  if (ind == 0)
    return (arr[0] == target);

  bool notTake = recursionSol(ind - 1, target, arr);
  bool take = false;
  if (arr[ind] <= target) {
    take = recursionSol(ind - 1, target - arr[ind], arr);
  }

  return take | notTake;
}

bool memoizationSol(int ind, int target, vector<int> &arr,
                    vector<vector<int>> &dp) {
  if (target == 0)
    return true;
  if (ind == 0)
    return (arr[0] == target);
  if (dp[ind][target] != -1) {
    return dp[ind][target];
  }
  bool notTake = memoizationSol(ind - 1, target, arr, dp);
  bool take = false;
  if (arr[ind] <= target) {
    take = memoizationSol(ind - 1, target - arr[ind], arr, dp);
  }

  return dp[ind][target] = take | notTake;
}
bool tabulationSol(int n, int k, vector<int> &arr, vector<vector<bool>> &dp) {
  for (int i = 0; i < n; i++) {
    dp[i][0] = true;
  }
  if (arr[0] <= k) {

    dp[0][arr[0]] = true;
  }
  for (int ind = 1; ind < n; ind++) {
    for (int target = 1; target <= k; target++) {
      bool notTake = dp[ind - 1][target];
      bool take = false;
      if (arr[ind] <= target) {
        take = dp[ind - 1][target - arr[ind]];
      }

      dp[ind][target] = take | notTake;
    }
  }

  return dp[n - 1][k];
}
bool spaceoptimzedSol(int n, int k, vector<int> &arr) {
  vector<bool> prev(k + 1, 0);
  vector<bool> curr(k + 1, 0);
  prev[0] = curr[0] = true;

  if (arr[0] <= k) {

    prev[arr[0]] = true;
  }
  for (int ind = 1; ind < n; ind++) {
    for (int target = 1; target <= k; target++) {
      bool notTake = prev[target];
      bool take = false;
      if (arr[ind] <= target) {
        take = prev[target - arr[ind]];
      }

      curr[target] = take | notTake;
    }
    prev = curr;
  }

  return prev[k];
}

// | Approach        |       Time |        Space |
// | --------------- | ---------: | -----------: |
// | Recursion       |    O(2^N)  |  O(N)  stack |
// | Memoization     |  O(N × K)  |    O(N × K)  |
// | Tabulation      |  O(N × K)  |    O(N × K)  |
// | Space Optimized |  O(N × K)  |        O(K)  |

bool canPartition(int n, vector<int> &arr) {

  // dp[ind][target]

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  // If odd then False
  if (sum % 2 != 0)
    return false;

  // if even then check sum/2
  sum = sum / 2;

  vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

  vector<vector<bool>> dp2(n, vector<bool>(sum + 1, false));

  // Recursion
  bool ans1 = recursionSol(n - 1, sum, arr);

  // Memoization
  bool ans2 = memoizationSol(n - 1, sum, arr, dp);

  // Tabulation
  bool ans3 = tabulationSol(n, sum, arr, dp2);

  // Space Optimization
  bool ans4 = spaceoptimzedSol(n, sum, arr);

  // Console output
  cout << "Recursion: " << ans1 << endl;

  cout << "Memoization: " << ans2 << endl;

  cout << "Tabulation: " << ans3 << endl;

  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}
int main() {
  cout << "15 DP 15 Partition Equal Subset Sum | DP on Subsequences" << endl;

  // Given an integer array nums, return true if you can partition the array
  // into two subsets such that the sum of the elements in both subsets is equal
  // or false otherwise.

  // Example 1:

  // Input: nums = [1,5,11,5]
  // Output: true
  // Explanation: The array can be partitioned as [1, 5, 5] and [11].
  // Example 2:

  // Input: nums = [1,2,3,5]
  // Output: false
  // Explanation: The array cannot be partitioned into equal sum subsets.

  // So Here it is similar to 14_DP_14_Subset_Sum_Equals_to_Target
  // Catch is to break down it to same problem
  // So For Equal Sum we need to break down Sum So
  // S = S1+ S2 S1 is Sum of Subset 1 and S2 is Sum of Subset 2
  // Also S1 = S2 = S/2
  // Now if S is odd then it is not possible to break into two Subset so
  // directly return false if S is true then take S/2 as target and see if we
  // can get a target from that subset

  vector<int> arr = {1, 2, 3, 4};

  int n = arr.size();

  bool ans = canPartition(n, arr);

  cout << "Final Answer: " << ans << endl;
  return 0;
}
