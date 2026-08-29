#include <bits/stdc++.h>

using namespace std;

int recursionSol(int ind, vector<int> &coins, int amount) {

  // Base Case:
  // Only coin[0] is available.
  // If amount is divisible by coin[0], we can make the amount.
  if (ind == 0) {
    if (amount % coins[ind] == 0) {
      return amount / coins[ind];
    } else {
      return 1e9;
    }
  }

  // Don't Pick:
  // Move to the previous coin.
  int notPick = 0 + recursionSol(ind - 1, coins, amount);

  // Pick:
  // We can pick the same coin again because
  // there are infinite supplies of every coin.
  int pick = 1e9;

  if (coins[ind] <= amount) {

    // IMPORTANT:
    // We do NOT do ind - 1 here.
    // The same coin can be picked again.
    pick = 1 + recursionSol(ind, coins, amount - coins[ind]);
  }

  return min(pick, notPick);
}

int memoizationSol(int ind, vector<int> &coins, int amount,
                   vector<vector<int>> &dp) {

  // Base Case
  if (ind == 0) {
    if (amount % coins[ind] == 0) {
      return amount / coins[ind];
    } else {
      return 1e9;
    }
  }

  // Already calculated
  if (dp[ind][amount] != -1) {
    return dp[ind][amount];
  }

  // Don't Pick
  int notPick = 0 + memoizationSol(ind - 1, coins, amount, dp);

  // Pick
  int pick = 1e9;

  if (coins[ind] <= amount) {

    // Same index because we can use this coin infinitely many times.
    pick = 1 + memoizationSol(ind, coins, amount - coins[ind], dp);
  }

  return dp[ind][amount] = min(pick, notPick);
}

int tabulationSol(int n, vector<int> &coins, int target,
                  vector<vector<int>> &dp) {

  // Base Case:
  // When only coin[0] is available.
  for (int T = 0; T <= target; T++) {

    if (T % coins[0] == 0) {
      dp[0][T] = T / coins[0];
    } else {
      dp[0][T] = 1e9;
    }
  }

  // Fill the DP table
  for (int ind = 1; ind < n; ind++) {

    for (int amount = 0; amount <= target; amount++) {

      // Don't Pick:
      // Move to the previous coin.
      int notPick = dp[ind - 1][amount];

      // Pick:
      int pick = 1e9;

      if (coins[ind] <= amount) {

        // Because coins are available infinitely,
        // we stay on the SAME row (ind).
        //
        // amount becomes:
        // amount - coins[ind]
        //
        // NOT:
        // coins[ind] - amount
        pick = 1 + dp[ind][amount - coins[ind]];
      }

      dp[ind][amount] = min(pick, notPick);
    }
  }

  return dp[n - 1][target];
}

int spaceOptimization(int n, vector<int> &coins, int target) {

  vector<int> prev(target + 1, 0);
  vector<int> curr(target + 1, 0);

  // Base Case
  // Only coin[0] is available.
  for (int T = 0; T <= target; T++) {

    if (T % coins[0] == 0) {
      prev[T] = T / coins[0];
    } else {
      prev[T] = 1e9;
    }
  }

  for (int ind = 1; ind < n; ind++) {

    for (int amount = 0; amount <= target; amount++) {

      // Don't Pick:
      // Take answer from previous row.
      int notPick = prev[amount];

      // Pick:
      int pick = 1e9;

      if (coins[ind] <= amount) {

        // Same row because the coin can be picked again.
        pick = 1 + curr[amount - coins[ind]];
      }

      curr[amount] = min(pick, notPick);
    }

    // Current row becomes previous row
    prev = curr;
  }

  return prev[target];
}

/*
| Approach        |       Time |       Space |
| --------------- | ----------:| -----------:|
| Recursion       |    O(2^N)   |  O(N) stack |
| Memoization     |   O(N × A)  |  O(N × A)   |
| Tabulation      |   O(N × A)  |  O(N × A)   |
| Space Optimized |   O(N × A)  |     O(A)    |

Where:
N = Number of coins
A = Target Amount
*/

int coinChange(vector<int> &coins, int amount) {

  int n = coins.size();

  // Recursion
  int ans1 = recursionSol(n - 1, coins, amount);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

  int ans2 = memoizationSol(n - 1, coins, amount, dp);

  // Tabulation
  vector<vector<int>> dp2(n, vector<int>(amount + 1, 0));

  int ans3 = tabulationSol(n, coins, amount, dp2);

  // Space Optimization
  int ans4 = spaceOptimization(n, coins, amount);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  // If answer is 1e9, amount cannot be formed.
  if (ans4 >= 1e9) {
    return -1;
  }

  return ans4;
}

int main() {

  cout << "20 DP 20 Minimum Coins | Infinite Supplies Pattern" << endl;

  /*
  Problem Statement:

  Given an integer array coins representing coins of
  different denominations and an integer amount,
  return the fewest number of coins needed to make
  that amount.

  There are infinite supplies of every coin.

  Example 1:

  coins = [1, 2, 5]
  amount = 11

  Answer = 3

  11 = 5 + 5 + 1

  Example 2:

  coins = [2, 5]
  amount = 3

  Answer = -1

  It is impossible to make amount 3.
  */

  vector<int> coins = {1, 2, 5};
  int amount = 11;

  int ans = coinChange(coins, amount);

  cout << "Final Answer: " << ans << endl;

  return 0;
}
