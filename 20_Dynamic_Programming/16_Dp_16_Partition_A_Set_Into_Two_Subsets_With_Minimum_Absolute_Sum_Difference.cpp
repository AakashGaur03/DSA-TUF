#include <bits/stdc++.h>
using namespace std;

// L 14
// Why does Subset Sum help solve this problem?
//
// The DP table contains all possible subset sums.
//
// dp[n-1][s1] tells us whether we can create a subset
// whose sum is s1 using all the elements.
//
// If we choose one subset with sum s1, then the remaining
// elements automatically form the second subset:
//
//     s2 = totalSum - s1
//
// Therefore:
//
//     difference = |s1 - s2|
//
//                 = |s1 - (totalSum - s1)|
//
//                 = |2*s1 - totalSum|
//
// So instead of directly trying every possible partition,
// we generate all possible subset sums using Subset Sum DP.
//
// Since we want the two subset sums to be as close as possible,
// we want s1 to be as close as possible to totalSum / 2.
//
// Therefore, we only need to check subset sums from:
//
//     0 -> totalSum / 2
//
// Once we find the best possible s1:
//
//     s2 = totalSum - s1
//
// and:
//
//     answer = |s2 - s1|
//
// We can use Tabulation here because the last row of the DP
// table contains all possible subset sums.
//
// The same DP can also be space optimized to O(totalSum).
bool subsetSumToK(int n, int k, vector<int> &arr, vector<vector<bool>> &dp) {

  for (int i = 0; i < n; i++) {
    dp[i][0] = true;
  }
  if (arr[0] <= k)
    dp[0][arr[0]] = true;
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

int minimumDifference(vector<int> &nums) {
  int n = nums.size();
  int totSum = 0;
  for (int i = 0; i < n; i++) {
    totSum += nums[i];
  }
  vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

  subsetSumToK(n, totSum, nums, dp);
  int mini = 1e9;
  // If s1 > totalSum / 2,
  // then s2 < totalSum / 2.
  //
  // That partition is already represented when we
  // consider s2 instead of s1.
  //
  // Therefore, checking both sides would be redundant.
  //
  // Also, the closer s1 is to totalSum / 2,
  // the smaller the difference will be.

  for (int s1 = 0; s1 <= totSum / 2; s1++) {
    if (dp[n - 1][s1] == true) {
      mini = min(mini, abs((totSum - s1) - s1));
    }
  }
  return mini;
}
int main() {
  cout << "16 Dp 16 Partition A Set Into Two Subsets With Minimum Absolute"
          "Sum Difference "
       << endl;

  // Partition Array Into Two Arrays to Minimize Sum Difference
  // You are given an integer array nums of 2 * n integers. You need to
  // partition nums into two arrays of length n to minimize the absolute
  // difference of the sums of the arrays. To partition nums, put each element
  // of nums into one of the two arrays.

  // Return the minimum possible absolute difference.

  vector<int> nums = {1, 2, 3, 4};

  cout << "Minimum Difference: " << minimumDifference(nums) << endl;

  return 0;
}
