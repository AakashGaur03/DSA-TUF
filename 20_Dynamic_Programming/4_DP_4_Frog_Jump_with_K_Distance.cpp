#include <bits/stdc++.h>
using namespace std;

int recursionSol(int ind, vector<int> &height, int k) {
  if (ind == 0)
    return 0;
  int minSteps = INT_MAX;
  int jump = INT_MAX;
  for (int i = 1; i <= k; i++) {
    if (ind - i >= 0) {
      jump =
          recursionSol(ind - i, height, k) + abs(height[ind] - height[ind - i]);
      minSteps = min(minSteps, jump);
    }
  }

  return minSteps;
}

// Memoization
// Top-Down
int minCostMemoization(int ind, vector<int> &height, vector<int> &dp, int k) {
  if (ind == 0)
    return 0;
  if (dp[ind] != -1)
    return dp[ind];
  int minSteps = INT_MAX;
  for (int i = 1; i <= k; i++) {
    if (ind - i >= 0) {
      int jump = minCostMemoization(ind - i, height, dp, k) +
                 abs(height[ind] - height[ind - i]);
      minSteps = min(minSteps, jump);
    }
  }
  dp[ind] = minSteps;
  return dp[ind];
}

// Tabulation
// Bottom Up
int minCostTabulation(int n, vector<int> &height, vector<int> &dp, int k) {

  dp[0] = 0;

  for (int i = 1; i < n; i++) {
    int minSteps = INT_MAX;

    for (int j = 1; j <= k; j++) {
      if (i - j >= 0) {
        int jump = dp[i - j] + abs(height[i] - height[i - j]);
        minSteps = min(minSteps, jump);
      }
    }
    dp[i] = minSteps;
  }
  return dp[n - 1];
}

// Possible But we have to carry a List of all the K Integers and in worst case
// scenario it can lead to N Just for Practice
int minCostTabulationSpaceOptimization(int n, vector<int> &height, int k) {
  deque<int> window;   // stores last k dp values
  window.push_back(0); // dp[0]

  for (int i = 1; i < n; i++) {

    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++) {
      if (i - j >= 0) {
        int dpValue = window[window.size() - j];
        int cost = dpValue + abs(height[i] - height[i - j]);

        minSteps = min(minSteps, cost);
      }
    }
    window.push_back(minSteps);

    if (window.size() > k)
      window.pop_front();
  }
  return window.back();
}

int minCost(int n, vector<int> &height, int k) {

  // GIVES TLE FOR BIG TEST CASES
  int ans1 = recursionSol(n - 1, height, k);

  vector<int> dp(n + 1, -1);
  int ans2 = minCostMemoization(n - 1, height, dp, k);

  vector<int> dp2(n, -1);
  int ans3 = minCostTabulation(n, height, dp2, k);

  // Possible But we have to carry a List of all the K Integers and in worst
  // case scenario it can lead to N
  int ans4 = minCostTabulationSpaceOptimization(n, height, k);

  cout << "Recursion: " << ans1 << '\n';
  cout << "Memoization: " << ans2 << '\n';
  cout << "Tabulation: " << ans3 << '\n';
  cout << "Space Optimization: " << ans4 << '\n';

  // return ans1;
  // return ans2;
  // return ans3;
  return ans4;
}

// | Method             | Time      | Space             |
// | ------------------ | -----     | ----------------- |
// | Recursion          | O(kⁿ)     | O(n) stack    |
// | Memoization        | O(n * K)  | O(n) + O(n) stack |
// | Tabulation         | O(n * K)  | O(n)              |
// | Space Optimization | O(n * K)  | O(K) or O(N)      |

int main() {
  cout << "3 DP 4 Frog Jump with K Distance" << endl;

  // Given an integer array height[] where height[i] represents the height of
  // the i-th stair, a frog starts from the first stair and wants to reach the
  // last stair. From any stair i, the frog has two options: it can either
  // jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the
  // absolute difference in height between the two stairs. Determine the
  // minimum total cost required for the frog to reach the last stair.

  // Example:

  // Input: heights[] = [20, 30, 40, 20]
  // Output: 20
  // Explanation:  Minimum cost is incurred when the frog jumps from stair 0
  // to 1 then 1 to 3: jump from stair 0 to 1: cost = |30 - 20| = 10 jump from
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
  int k = 2;
  cout << minCost(height.size(), height, k);

  return 0;
}
