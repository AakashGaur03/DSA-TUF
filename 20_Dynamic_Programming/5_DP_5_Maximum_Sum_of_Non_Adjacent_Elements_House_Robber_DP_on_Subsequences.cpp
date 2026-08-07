#include <bits/stdc++.h>
using namespace std;

int recursionSol(int ind, vector<int> &nums) {
  if (ind == 0) {
    return nums[ind];
  }
  if (ind < 0) {
    return 0;
  }

  // ind-2 because we want non adjacent
  int pick = nums[ind] + recursionSol(ind - 2, nums);

  int notpick = 0 + recursionSol(ind - 1, nums);

  return max(pick, notpick);
}

int memoizationSol(int ind, vector<int> &nums, vector<int> &dp) {
  if (ind == 0) {
    return nums[ind];
  }
  if (ind < 0) {
    return 0;
  }
  if (dp[ind] != -1) {
    return dp[ind];
  }

  int pick = nums[ind] + memoizationSol(ind - 2, nums, dp);
  int notPick = 0 + memoizationSol(ind - 1, nums, dp);

  dp[ind] = max(pick, notPick);

  return dp[ind];
}

int tabulationSol(int ind, vector<int> &nums, vector<int> &dp) {
  dp[0] = nums[0];

  for (int i = 1; i < nums.size(); i++) {

    int pick = nums[i];
    if (i > 1) {
      pick += dp[i - 2];
    }
    int notPick = 0 + dp[i - 1];

    dp[i] = max(pick, notPick);
  }

  return dp[ind];
}

int tabulationSolSpaceOptimized(int ind, vector<int> &nums) {
  int prev = nums[0];
  int prev2 = 0;

  for (int i = 1; i < nums.size(); i++) {

    int pick = nums[i];
    if (i > 1) {
      pick += prev2;
    }
    int notPick = 0 + prev;
    int curr = max(pick, notPick);
    prev2 = prev;
    prev = curr;
  }

  return prev;
}

int maximumNonAdjacentSum(vector<int> &nums) {
  int n = nums.size();

  // Recursion
  int recursionAns = recursionSol(n - 1, nums);
  cout << "Recursion: " << recursionAns << endl;

  // Memoization
  vector<int> dp(n, -1);
  int memoizationAns = memoizationSol(n - 1, nums, dp);
  cout << "Memoization: " << memoizationAns << endl;

  // Tabulation
  vector<int> dp2(n, 0);
  int tabulationAns = tabulationSol(n - 1, nums, dp2);
  cout << "Tabulation: " << tabulationAns << endl;

  // Space Optimized
  int spaceOptimizedAns = tabulationSolSpaceOptimized(n - 1, nums);
  cout << "Space Optimized: " << spaceOptimizedAns << endl;

  return spaceOptimizedAns;
}
// | Approach                      | Time Complexity | Space Complexity
// | ----------------------------- | --------------- | ----------------
// |   Recursion                   |   O(2^N)        |   O(N)
// |   Memoization (Top-Down DP)   |   O(N)          |   O(N) + O(N)(Stack)
// |   Tabulation (Bottom-Up DP)   |   O(N)          |   O(N)
// |   Space Optimized             |   O(N)          |   O(1)

int main() {
  cout << "5 DP 5 Maximum Sum of Non Adjacent Elements House Robber DP on "
          "Subsequences"
       << endl;

  // Maximum sum of non adjacent elements

  // Given an integer array nums of size n. Return the maximum sum possible
  // using the elements of nums such that no two elements taken are adjacent in
  // nums.

  // Example 1
  // Input: nums = [1, 2, 4]
  // Output: 5
  // Explanation:
  // [1, 2, 4], the underlined elements are taken to get the maximum sum.

  // Example 2
  // Input: nums = [2, 1, 4, 9]
  // Output: 11
  // Explanation:
  // [2, 1, 4, 9], the underlined elements are taken to get the maximum sum.

  // Lets Try out all Subsequence with given constrainr
  // Pick the one with maximum Sum

  // STEPS TO FOLLOW FOR RECURSION RELATION THAT WILL HELP TO SOLVE IN DP
  // 1) TRY TO REPRESENT THE PROBLEM IN TERMS OF INDEX
  // 2) DO ALL POSSIBLE STEPS ON THAT INDEX ACC TO PROBLEM STATEMENT
  // 3) IF QUESTION SAYS
  // COUNT ALL THE WAYS -> SUM UP ALL THE STUFF
  // FIND MINIMUM -> GET MINIMUM OF ALL STUFF
  // FIND MAXIMUM -> GET MAXIMUM OF ALL STUFF

  vector<int> nums = {2, 1, 4, 9};

  cout << "\nFinal Answer = " << maximumNonAdjacentSum(nums) << endl;

  return 0;
}
