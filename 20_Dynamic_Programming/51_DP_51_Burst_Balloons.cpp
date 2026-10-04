
#include <bits/stdc++.h>
using namespace std;

int recursionSol(int i, int j, vector<int> &arr) {
  if (i > j) {
    return 0;
  }

  int maxi = INT_MIN;
  for (int ind = i; ind <= j; ind++) {
    int cost = arr[i - 1] * arr[ind] * arr[j + 1] +
               recursionSol(i, ind - 1, arr) + recursionSol(ind + 1, j, arr);

    maxi = max(maxi, cost);
  }

  return maxi;
}

int memoizationSol(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
  if (i > j) {
    return 0;
  }

  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int maxi = INT_MIN;
  for (int ind = i; ind <= j; ind++) {
    int cost = arr[i - 1] * arr[ind] * arr[j + 1] +
               memoizationSol(i, ind - 1, arr, dp) +
               memoizationSol(ind + 1, j, arr, dp);

    maxi = max(maxi, cost);
  }

  return dp[i][j] = maxi;
}

int tabulationSol(int n, vector<int> &arr, vector<vector<int>> &dp) {

  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) {

      if (i > j) {
        continue;
      }

      int maxi = INT_MIN;
      for (int ind = i; ind <= j; ind++) {
        int cost = arr[i - 1] * arr[ind] * arr[j + 1] + dp[i][ind - 1] +
                   dp[ind + 1][j];

        maxi = max(maxi, cost);
      }

      dp[i][j] = maxi;
    }
  }

  return dp[1][n];
}

int maxCoins(vector<int> &nums) {

  int n = nums.size();

  nums.push_back(1);
  nums.insert(nums.begin(), 1);

  // Recursion
  int ans1 = recursionSol(1, n, nums);

  // Memoization
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  int ans2 = memoizationSol(1, n, nums, dp);

  // Tabulation
  vector<vector<int>> dp2(n + 2, vector<int>(n + 2, 0));
  int ans3 = tabulationSol(n, nums, dp2);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;

  return ans3;
}

// | Approach    | Time Complexity | Space Complexity |
// | ----------- | --------------: | ---------------: |
// | Recursion   |        O(2^N)   |           O(N)   |
// | Memoization |         O(N³)   |          O(N²)   |
// | Tabulation  |         O(N³)   |          O(N²)   |

int main() {

  cout << "51 DP 51 Burst Balloons" << endl;

  // Burst Balloons
  // You are given n balloons, indexed from 0 to n - 1. Each balloon is painted
  // with a number on it represented by an array nums. You are asked to burst
  // all the balloons.

  // If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i +
  // 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it
  // as if there is a balloon with a 1 painted on it.

  // Return the maximum coins you can collect by bursting the balloons wisely.

  // Example 1:

  // Input: nums = [3,1,5,8]
  // Output: 167
  // Explanation:
  // nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
  // coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
  // Example 2:

  // Input: nums = [1,5]
  // Output: 10
  vector<int> nums = {3, 1, 5, 8};

  int answer = maxCoins(nums);

  cout << "Final Answer: " << answer << endl;
}

// ============================================================
// DP 51 - Burst Balloons
// ============================================================
//
// Main Idea:
//
// We add 1 at both ends of the array.
//
// Example:
// nums = [3, 1, 5, 8]
//
// After adding boundaries:
//
// arr = [1, 3, 1, 5, 8, 1]
//
// Now recursionSol(i, j) means:
//
// "Find the maximum coins we can collect by bursting
//  all balloons from index i to j."
//
// ------------------------------------------------------------
// Important Observation:
//
// Instead of deciding which balloon to burst FIRST,
// we decide which balloon will be burst LAST.
//
// Why?
//
// If arr[ind] is the LAST balloon to burst in the range [i, j],
// then all balloons between i and ind are already gone,
// and all balloons between ind and j are already gone.
//
// Therefore, the only balloons remaining next to arr[ind] are:
//
// arr[i - 1] and arr[j + 1]
//
// So the coins gained from bursting ind last are:
//
// arr[i - 1] * arr[ind] * arr[j + 1]
//
// ------------------------------------------------------------
//
// After bursting ind last:
//
// Left part  -> [i ... ind - 1]
// Right part -> [ind + 1 ... j]
//
// Therefore:
//
// cost =
// arr[i - 1] * arr[ind] * arr[j + 1]
// + maximum coins from left part
// + maximum coins from right part
//
// We try every possible ind from i to j
// and take the maximum.
//
// ------------------------------------------------------------
//
// Base Case:
//
// If i > j, there are no balloons left to burst.
//
// Therefore:
//
// return 0;
//
// ------------------------------------------------------------
//
// Recursion:
// Try every balloon as the LAST balloon to burst.
//
// Time Complexity: O(2^N) approximately
// Space Complexity: O(N)
//
// ------------------------------------------------------------
//
// Memoization:
//
// The same states (i, j) are calculated multiple times
// in recursion.
//
// We store the answer of every state in dp[i][j].
//
// Number of states = O(N^2)
// For every state, we try O(N) possible last balloons.
//
// Time Complexity: O(N^3)
// Space Complexity: O(N^2) for DP table + O(N) recursion stack
//                 = O(N^2)
//
// ------------------------------------------------------------
//
// Tabulation:
//
// We calculate the same DP states iteratively.
//
// dp[i][j] = maximum coins obtained by bursting
// all balloons from i to j.
//
// dp[i][j] depends on:
//
// dp[i][ind - 1]
// dp[ind + 1][j]
//
// Therefore, we calculate smaller ranges before larger ranges.
//
// Time Complexity: O(N^3)
// Space Complexity: O(N^2)
//
// ------------------------------------------------------------
//
// Final Answer:
//
// dp[1][N] contains the maximum coins obtainable
// by bursting all balloons.
// ============================================================