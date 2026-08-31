#include <bits/stdc++.h>
using namespace std;

int recursionSol(int ind, int amount, vector<int> &coins) {

  if (ind == 0) {
    // So if amount is 4 and Coin is 1 so with 1 + 1+ 1+ 1 target is achieveable
    return (amount % coins[ind] == 0); // return 1 or 0
  }

  int pick = 0;
  if (coins[ind] <= amount) {
    // Because it is Infinite Supply so we stay at same Index
    pick = recursionSol(ind, amount - coins[ind], coins);
  }

  int notPick = recursionSol(ind - 1, amount, coins);

  return pick + notPick;
}

int memoizationSol(int ind, int amount, vector<int> &coins,
                   vector<vector<int>> &dp) {

  if (ind == 0) {
    // So if amount is 4 and Coin is 1 so with 1 + 1+ 1+ 1 target is achieveable
    return (amount % coins[ind] == 0); // return 1 or 0
  }
  if (dp[ind][amount] != -1) {
    return dp[ind][amount];
  }

  int pick = 0;
  if (coins[ind] <= amount) {
    // Because it is Infinite Supply so we stay at same Index
    pick = memoizationSol(ind, amount - coins[ind], coins, dp);
  }

  int notPick = memoizationSol(ind - 1, amount, coins, dp);

  return dp[ind][amount] = pick + notPick;
}

int tabulationSol(int n, int amount, vector<int> &coins,
                  vector<vector<int>> &dp) {

  for (int T = 0; T <= amount; T++) {
    dp[0][T] = (T % coins[0] == 0);
  }

  for (int i = 1; i < n; i++) {
    for (int T = 0; T <= amount; T++) {
      int pick = 0;
      if (coins[i] <= T) {
        // Because it is Infinite Supply so we stay at same Index
        pick = dp[i][T - coins[i]];
      }

      int notPick = dp[i - 1][T];
      dp[i][T] = pick + notPick;
    }
  }

  return dp[n - 1][amount];
}
int spaceOptimizedSol(int n, int amount, vector<int> &coins) {

  vector<int> prev(amount + 1, 0);
  vector<int> curr(amount + 1, 0);

  for (int T = 0; T <= amount; T++) {
    prev[T] = (T % coins[0] == 0);
  }

  for (int i = 1; i < n; i++) {
    for (int T = 0; T <= amount; T++) {
      int pick = 0;
      if (coins[i] <= T) {
        // Because it is Infinite Supply so we stay at same Index
        pick = curr[T - coins[i]];
      }

      int notPick = prev[T];
      curr[T] = pick + notPick;
    }
    prev = curr;
  }

  return prev[amount];
}

int change(int amount, vector<int> &coins) {

  int n = coins.size();

  // Recursion
  int ans1 = recursionSol(n - 1, amount, coins);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
  int ans2 = memoizationSol(n - 1, amount, coins, dp);

  // Tabulation
  vector<vector<int>> dp2(n, vector<int>(amount + 1, 0));
  int ans3 = tabulationSol(n, amount, coins, dp2);

  // Space Optimization
  int ans4 = spaceOptimizedSol(n, amount, coins);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}

// | Approach            |      Time Complexity |             Space Complexity |
// | ------------------- | -------------------: | ---------------------------: |
// |   Recursion         |  O(2^(N + Amount))  |         O(N + Amount)  stack |
// |   Memoization       |       O(N × Amount)  |  O(N × Amount) + O(N)  stack |
// |   Tabulation        |       O(N × Amount)  |               O(N × Amount)  |
// |   Space Optimized   |       O(N × Amount)  |                   O(Amount)  |

int main() {

  cout << "22 DP 22 Coin Change 2" << endl;

  //   You are given an integer array coins representing coins of different
  //   denominations and an integer amount representing a total amount of money.

  // Return the number of combinations that make up that amount. If that amount
  // of money cannot be made up by any combination of the coins, return 0.

  // You may assume that you have an infinite number of each kind of coin.

  // The final answer is guaranteed to fit into a signed 32-bit integer.

  // Example 1:

  // Input: amount = 5, coins = [1,2,5]
  // Output: 4
  // Explanation: there are four ways to make up the amount:
  // 5=5
  // 5=2+2+1
  // 5=2+1+1+1
  // 5=1+1+1+1+1

  vector<int> coins = {1, 2, 5};
  int amount = 5;

  int ans = change(amount, coins);

  cout << "Final Answer: " << ans << endl;

  return 0;
}
