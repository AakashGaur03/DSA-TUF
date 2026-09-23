
#include <bits/stdc++.h>
using namespace std;

int recursionSol(int ind, int tranNo, vector<int> &values, int n, int k) {
  if (ind == n) {
    return 0;
  }
  if (tranNo == 2 * k) {
    return 0;
  }

  if (tranNo % 2 == 0) {
    int buy = -values[ind] + recursionSol(ind + 1, tranNo + 1, values, n, k);
    int notBuy = 0 + recursionSol(ind + 1, tranNo, values, n, k);
    return max(buy, notBuy);
  } else {
    int sell = values[ind] + recursionSol(ind + 1, tranNo + 1, values, n, k);
    int notSell = 0 + recursionSol(ind + 1, tranNo, values, n, k);
    return max(sell, notSell);
  }
}
int memoizationSol(int ind, int tranNo, vector<int> &values, int n, int k,
                   vector<vector<int>> &dp) {
  if (ind == n) {
    return 0;
  }
  if (tranNo == 2 * k) {
    return 0;
  }
  if (dp[ind][tranNo] != -1) {
    return dp[ind][tranNo];
  }
  if (tranNo % 2 == 0) {
    int buy =
        -values[ind] + memoizationSol(ind + 1, tranNo + 1, values, n, k, dp);
    int notBuy = 0 + memoizationSol(ind + 1, tranNo, values, n, k, dp);
    return dp[ind][tranNo] = max(buy, notBuy);
  } else {
    int sell =
        values[ind] + memoizationSol(ind + 1, tranNo + 1, values, n, k, dp);
    int notSell = 0 + memoizationSol(ind + 1, tranNo, values, n, k, dp);
    return dp[ind][tranNo] = max(sell, notSell);
  }
}

int tabulationSol(vector<int> &values, int n, int k, vector<vector<int>> &dp) {

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int tranNo = 2 * k - 1; tranNo >= 0; tranNo--) {
      if (tranNo % 2 == 0) {
        int buy = -values[ind] + dp[ind + 1][tranNo + 1];
        int notBuy = 0 + dp[ind + 1][tranNo];
        dp[ind][tranNo] = max(buy, notBuy);
      } else {
        int sell = values[ind] + dp[ind + 1][tranNo + 1];
        int notSell = 0 + dp[ind + 1][tranNo];
        dp[ind][tranNo] = max(sell, notSell);
      }
    }
  }
  return dp[0][0];
}
int spaceOptimized(vector<int> &values, int n, int k) {

  vector<int> after(2 * k + 1, 0);
  vector<int> curr(2 * k + 1, 0);

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int tranNo = 2 * k - 1; tranNo >= 0; tranNo--) {
      if (tranNo % 2 == 0) {
        int buy = -values[ind] + after[tranNo + 1];
        int notBuy = 0 + after[tranNo];
        curr[tranNo] = max(buy, notBuy);
      } else {
        int sell = values[ind] + after[tranNo + 1];
        int notSell = 0 + after[tranNo];
        curr[tranNo] = max(sell, notSell);
      }
    }
    after = curr;
  }
  return after[0];
}

int getMaximumProfit(vector<int> &Arr, int n, int k) {
  // Only K transaction can be Used

  // Recursion
  int ans1 = recursionSol(0, 0, Arr, n, k);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(2 * k + 1, -1));

  int ans2 = memoizationSol(0, 0, Arr, n, k, dp);

  // Tabulation
  vector<vector<int>> dp2(n + 1, vector<int>(2 * k + 1, 0));

  int ans3 = tabulationSol(Arr, n, k, dp2);

  // Space Optimization
  int ans4 = spaceOptimized(Arr, n, k);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}

// | Approach           |       Time |        Space |
// | ------------------ | ---------: | -----------: |
// | Recursion          |    O(2^N)  |  O(N)  stack |
// | Memoization        |  O(N × K)  |    O(N × K)  |
// | Tabulation         |  O(N × K)  |    O(N × K)  |
// | Space Optimization |  O(N × K)  |        O(K)  |

int main() {
  cout << "38 DP 38 Buy and Sell Stock IV 2nd Apporach" << endl;

  //   Best time to buy and sell stock IV
  // Given an array, arr, of n integers, where arr[i] represents the price
  // of the stock on an ith day, determine the maximum profit achievable by
  // completing at most k transactions in total. Holding at most one share
  // of the stock at any given time is allowed, meaning buying and selling
  // the stock k times is permitted, but the stock must be sold before
  // buying it again. Buying and selling the stock on the same day is
  // allowed.

  // Example 1:
  // Input: arr = [3, 2, 6, 5, 0, 3], k = 2

  // Output: 7

  // Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6),
  // profit = 6 - 2 = 4. Then buy on day 5 (price = 0) and sell on day 6
  // (price = 3), profit = 3 - 0 = 3. Total profit is 4 + 3 = 7.

  // Example 2:
  // Input: arr = [1, 2, 4, 2, 5, 7, 2, 4, 9, 0], k = 3

  // Output: 15

  // Explanation: Buy on day 1 (price = 1) and sell on day 3 (price = 4),
  // profit = 4 - 1 = 3. Then buy on day 4 (price = 2) and sell on day 6
  // (price = 7), profit = 7 - 2 = 5. Then buy on day 7 (price = 2) and sell
  // on day 9 (price = 9), profit = 9 - 2 = 7. Total profit is 3 + 5 + 7
  // = 15.

  int n = 6;

  vector<int> arr = {4, 2, 7, 1, 11, 5};
  int k = 4;
  int ans = getMaximumProfit(arr, n, k);

  cout << "Maximum Profit: " << ans << endl;

  return 0;
}
