#include <bits/stdc++.h>
using namespace std;

int recursionSol(int ind, vector<int> &height) {
  if (ind == 0)
    return 0;

  int left = recursionSol(ind - 1, height) + abs(height[ind] - height[ind - 1]);
  int right = INT_MAX;

  if (ind > 1)
    right = recursionSol(ind - 2, height) + abs(height[ind] - height[ind - 2]);

  return min(left, right);
}

// Memoization
// Top-Down
int minCostMemoization(int ind, vector<int> &height, vector<int> &dp) {
  if (ind == 0)
    return 0;
  if (dp[ind] != -1)
    return dp[ind];

  int left = minCostMemoization(ind - 1, height, dp) +
             abs(height[ind] - height[ind - 1]);
  int right = INT_MAX;

  if (ind > 1)
    right = minCostMemoization(ind - 2, height, dp) +
            abs(height[ind] - height[ind - 2]);

  dp[ind] = min(left, right);
  return dp[ind];
}

// Tabulation
// Bottom Up
int minCostTabulation(int n, vector<int> &height, vector<int> &dp) {

  dp[0] = 0;

  for (int i = 1; i < n; i++) {

    int firstStep = dp[i - 1] + abs(height[i] - height[i - 1]);
    int secondStep = INT_MAX;

    if (i > 1)
      secondStep = dp[i - 2] + abs(height[i] - height[i - 2]);

    dp[i] = min(firstStep, secondStep);
  }
  return dp[n - 1];
}

int minCostTabulationSpaceOptimization(int n, vector<int> &height) {
  int prev = 0;
  int prev2 = 0;

  for (int i = 1; i < n; i++) {

    int firstStep = prev + abs(height[i] - height[i - 1]);
    int secondStep = INT_MAX;

    if (i > 1)
      secondStep = prev2 + abs(height[i] - height[i - 2]);

    int curr = min(firstStep, secondStep);
    prev2 = prev;
    prev = curr;
  }
  return prev;
}

int minCost(int n, vector<int> &height) {

  // GIVES TLE FOR BIG TEST CASES
  int ans1 = recursionSol(n - 1, height);

  vector<int> dp(n + 1, -1);
  int ans2 = minCostMemoization(n - 1, height, dp);

  vector<int> dp2(n, -1);
  int ans3 = minCostTabulation(n, height, dp2);

  int ans4 = minCostTabulationSpaceOptimization(n, height);

  cout << "Recursion: " << ans1 << '\n';
  cout << "Memoization: " << ans2 << '\n';
  cout << "Tabulation: " << ans3 << '\n';
  cout << "Space Optimization: " << ans4 << '\n';

  // return ans1
  // return ans2
  // return ans3
  return ans4;
}

// | Method             | Time  | Space             |
// | ------------------ | ----- | ----------------- |
// | Recursion          | O(2ⁿ) | O(n) stack        |
// | Memoization        | O(n)  | O(n) + O(n) stack |
// | Tabulation         | O(n)  | O(n)              |
// | Space Optimization | O(n)  | O(1)              |

int main() {
  cout << "3 DP 3 Frog Jump | Learn to write 1D DP" << endl;

  // Given an integer array height[] where height[i] represents the height of
  // the i-th stair, a frog starts from the first stair and wants to reach the
  // last stair. From any stair i, the frog has two options: it can either jump
  // to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the
  // absolute difference in height between the two stairs. Determine the minimum
  // total cost required for the frog to reach the last stair.

  // Example:

  // Input: heights[] = [20, 30, 40, 20]
  // Output: 20
  // Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to
  // 1 then 1 to 3: jump from stair 0 to 1: cost = |30 - 20| = 10 jump from
  // stair 1 to 3: cost = |20 - 30| = 10 Total Cost = 10 + 10 = 20

  // STEPS TO FOLLOW FOR RECURSION RELATION THAT WILL HELP TO SOLVE IN DP
  // 1) TRY TO REPRESENT THE PROBLEM IN TERMS OF INDEX
  // 2) DO ALL POSSIBLE STEPS ON THAT INDEX ACC TO PROBLEM STATEMENT
  // 3) IF QUESTION SAYS
  // COUNT ALL THE WAYS -> SUM UP ALL THE STUFF
  // FIND MINIMUM -> GET MINIMUM OF ALL STUFF
  // FIND MAXIMUM -> GET MAXIMUM OF ALL STUFF

  // REFER 3_DP_3_Frog_Jump__Dynamic_Programming__Learn_to_write_1D_DP_1

  vector<int> height = {20, 30, 40, 20};

  cout << minCost(height.size(), height);

  return 0;
}
