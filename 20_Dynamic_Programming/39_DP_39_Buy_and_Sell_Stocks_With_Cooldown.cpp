
#include <bits/stdc++.h>
using namespace std;

long recursionSol(int ind, int canBuy, vector<long> &values, int n) {
  if (ind >= n) {
    return 0;
  }
  long profit = 0;
  if (canBuy) {
    long buy = -values[ind] + recursionSol(ind + 1, 0, values, n);
    long notBuy = 0 + recursionSol(ind + 1, 1, values, n);
    profit = max(buy, notBuy);
  } else {
    long sell = values[ind] + recursionSol(ind + 2, 1, values, n);
    long notSell = 0 + recursionSol(ind + 1, 0, values, n);
    profit = max(sell, notSell);
  }

  return profit;
}

long memoizationSol(int ind, int canBuy, vector<long> &values, int n,
                    vector<vector<long>> &dp) {
  if (ind >= n) {
    return 0;
  }

  if (dp[ind][canBuy] != -1) {
    return dp[ind][canBuy];
  }

  long profit = 0;
  if (canBuy) {
    long buy = -values[ind] + memoizationSol(ind + 1, 0, values, n, dp);
    long notBuy = 0 + memoizationSol(ind + 1, 1, values, n, dp);
    profit = max(buy, notBuy);
  } else {
    long sell = values[ind] + memoizationSol(ind + 2, 1, values, n, dp);
    long notSell = 0 + memoizationSol(ind + 1, 0, values, n, dp);
    profit = max(sell, notSell);
  }

  return dp[ind][canBuy] = profit;
}

long tabulationSol(vector<long> &values, int n, vector<vector<long>> &dp) {

  long profit = 0;

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int canBuy = 0; canBuy <= 1; canBuy++) {
      if (canBuy) {
        long buy = -values[ind] + dp[ind + 1][0];
        long notBuy = 0 + dp[ind + 1][1];
        profit = max(buy, notBuy);
      } else {
        long sell = values[ind] + dp[ind + 2][1];
        long notSell = 0 + dp[ind + 1][0];
        profit = max(sell, notSell);
      }
      dp[ind][canBuy] = profit;
    }
  }
  return dp[0][1];
}

long spaceOptimized(vector<long> &values, int n) {

  vector<long> front1(2, 0);
  vector<long> front2(2, 0);
  vector<long> curr(2, 0);

  long profit = 0;

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int canBuy = 0; canBuy <= 1; canBuy++) {
      if (canBuy) {
        long buy = -values[ind] + front1[0];
        long notBuy = 0 + front1[1];
        profit = max(buy, notBuy);
      } else {
        long sell = values[ind] + front2[1];
        long notSell = 0 + front1[0];
        profit = max(sell, notSell);
      }
      curr[canBuy] = profit;
    }
    front2 = front1;
    front1 = curr;
  }
  return curr[1];
}

long spaceOptimized2ndApproach(vector<long> &values, int n) {

  vector<long> front1(2, 0);
  vector<long> front2(2, 0);
  vector<long> curr(2, 0);

  long profit = 0;

  for (int ind = n - 1; ind >= 0; ind--) {
    long buy = -values[ind] + front1[0];
    long notBuy = 0 + front1[1];
    curr[1] = max(buy, notBuy);
    long sell = values[ind] + front2[1];
    long notSell = 0 + front1[0];
    curr[0] = max(sell, notSell);
    front2 = front1;
    front1 = curr;
  }
  return curr[1];
}

long getMaximumProfit(vector<long> &Arr, int n) {

  // Recursion
  long ans1 = recursionSol(0, 1, Arr, n);

  // Memoization
  vector<vector<long>> dp(n, vector<long>(2, -1));
  long ans2 = memoizationSol(0, 1, Arr, n, dp);

  // Tabulation
  vector<vector<long>> dp2(n + 2, vector<long>(2, 0));
  long ans3 = tabulationSol(Arr, n, dp2);

  // Space Optimization
  long ans4 = spaceOptimized(Arr, n);

  // Space Optimization - 2nd Approach
  long ans5 = spaceOptimized2ndApproach(Arr, n);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;
  cout << "Space Optimization 2nd Approach: " << ans5 << endl;

  return ans5;
}

// | Approach             |            Time |            Space |
// | -------------------- | --------------: | ---------------: |
// | Recursion            |          O(2^N) |       O(N) stack |
// | Memoization          | O(N × 2) = O(N) | O(N × 2) + stack |
// | Tabulation           | O(N × 2) = O(N) |         O(N × 2) |
// | Space Optimization   | O(N × 2) = O(N) |             O(1) |
// | Space Optimization 2 | O(N × 2) = O(N) |             O(1) |

int main() {

  cout << "39 DP 39 Buy and Sell Stocks With Cooldown" << endl;

  // Cooldown here means cant buy directly after sell

  // Best Time to Buy and Sell Stock with Cooldown
  //
  // You are given an integer array prices where prices[i] is the price of a
  // stock on the ith day.
  //
  // You may complete any number of transactions (buy one share and sell one
  // share of the stock multiple times) subject to these rules:
  //
  // After you sell a share, you cannot buy on the very next day
  // (i.e. there is a one-day cooldown).
  //
  // You may not hold more than one share at a time.
  //
  // Example 1:
  // Input: prices = [1,2,3,0,2]
  // Output: 3
  //
  // Transactions:
  // Buy -> Sell -> Cooldown -> Buy -> Sell
  //
  // Example 2:
  // Input: prices = [1]
  // Output: 0
  //
  // Example 3:
  // Input: prices = [5,4,3,2,1]
  // Output: 0

  // Example 1
  vector<long> prices1 = {1, 2, 3, 0, 2};

  long ans1 = getMaximumProfit(prices1, prices1.size());

  cout << "--------------------------------" << endl;
  cout << "Example 1" << endl;

  cout << "Prices: ";

  for (long price : prices1) {
    cout << price << " ";
  }

  cout << endl;
  cout << "Maximum Profit: " << ans1 << endl;

  // Example 2
  vector<long> prices2 = {1};

  long ans2 = getMaximumProfit(prices2, prices2.size());

  cout << "--------------------------------" << endl;
  cout << "Example 2" << endl;

  cout << "Prices: ";

  for (long price : prices2) {
    cout << price << " ";
  }

  cout << endl;
  cout << "Maximum Profit: " << ans2 << endl;

  // Example 3
  vector<long> prices3 = {5, 4, 3, 2, 1};

  long ans3 = getMaximumProfit(prices3, prices3.size());

  cout << "--------------------------------" << endl;
  cout << "Example 3" << endl;

  cout << "Prices: ";

  for (long price : prices3) {
    cout << price << " ";
  }

  cout << endl;
  cout << "Maximum Profit: " << ans3 << endl;

  return 0;
}