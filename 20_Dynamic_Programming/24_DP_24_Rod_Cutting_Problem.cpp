#include <bits/stdc++.h>
using namespace std;

int recursionSol(int ind, int N, vector<int> &price) {
  if (ind == 0) {
    return N * price[0];
  }
  int notTake = 0 + recursionSol(ind - 1, N, price);

  int take = INT_MIN;
  int rodLength = ind + 1;
  if (rodLength <= N) {
    take = price[ind] + recursionSol(ind, N - rodLength, price);
  }

  return max(take, notTake);
}

int memoizationSol(int ind, int N, vector<int> &price,
                   vector<vector<int>> &dp) {
  if (ind == 0) {
    return N * price[0];
  }
  if (dp[ind][N] != -1) {
    return dp[ind][N];
  }
  int notTake = 0 + memoizationSol(ind - 1, N, price, dp);

  int take = INT_MIN;
  int rodLength = ind + 1;
  if (rodLength <= N) {
    take = price[ind] + memoizationSol(ind, N - rodLength, price, dp);
  }

  return dp[ind][N] = max(take, notTake);
}

int tabulationSol(int n, vector<int> &price, vector<vector<int>> &dp) {

  for (int N = 0; N <= n; N++) {
    dp[0][N] = N * price[0];
  }

  for (int ind = 1; ind < n; ind++) {
    for (int N = 0; N <= n; N++) {
      int notTake = 0 + dp[ind - 1][N];

      int take = INT_MIN;
      int rodLength = ind + 1;
      if (rodLength <= N) {
        take = price[ind] + dp[ind][N - rodLength];
      }

      dp[ind][N] = max(take, notTake);
    }
  }
  return dp[n - 1][n];
}

int spaceOptimization(int n, vector<int> &price) {
  vector<int> prev(n + 1, 0);
  vector<int> curr(n + 1, 0);
  for (int N = 0; N <= n; N++) {
    prev[N] = N * price[0];
  }

  for (int ind = 1; ind < n; ind++) {
    for (int N = 0; N <= n; N++) {
      int notTake = 0 + prev[N];

      int take = INT_MIN;
      int rodLength = ind + 1;
      if (rodLength <= N) {
        take = price[ind] + curr[N - rodLength];
      }

      curr[N] = max(take, notTake);
    }
    prev = curr;
  }
  return prev[n];
}
int spaceOptimizationDArray(int n, vector<int> &price) {
  vector<int> prev(n + 1, 0);
  for (int N = 0; N <= n; N++) {
    prev[N] = N * price[0];
  }

  for (int ind = 1; ind < n; ind++) {
    for (int N = 0; N <= n; N++) {
      int notTake = 0 + prev[N];

      int take = INT_MIN;
      int rodLength = ind + 1;
      if (rodLength <= N) {
        take = price[ind] + prev[N - rodLength];
      }

      prev[N] = max(take, notTake);
    }
  }
  return prev[n];
}

int cutRod(vector<int> &price, int n) {

  // Recursion
  int ans1 = recursionSol(n - 1, n, price);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  int ans2 = memoizationSol(n - 1, n, price, dp);

  // Tabulation
  vector<vector<int>> dp2(n, vector<int>(n + 1, 0));
  int ans3 = tabulationSol(n, price, dp2);

  // Space Optimization - 2 arrays
  int ans4 = spaceOptimization(n, price);

  // Space Optimization - 1 array
  int ans5 = spaceOptimizationDArray(n, price);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;
  cout << "1D Space Optimization: " << ans5 << endl;

  return ans5;
}

// | Approach                      |        Time |      Space |
// | ----------------------------- | ----------: | ---------: |
// | Recursion                     | Exponential | O(n) stack |
// | Memoization                   |       O(n²) |      O(n²) |
// | Tabulation                    |       O(n²) |      O(n²) |
// | Space optimization — 2 arrays |       O(n²) |       O(n) |
// | Space optimization — 1 array  |       O(n²) |       O(n) |

int main() {

  cout << "24 DP 24 Rod Cutting Problem" << endl;
  //   Problem Statement: Given a rod of length N inches and an array price[]
  //   where price[i] denotes the value of a piece of rod of length i inches
  //   (1-based indexing). Determine the maximum value obtainable by cutting up
  //   the rod and selling the pieces. Make any number of cuts, or none at all,
  //   and sell the resulting pieces.

  // Examples

  // Input : price = [1, 6, 8, 9, 10, 19, 7, 20], N = 8
  // Output :25
  // Explanation :Cut the rod into lengths of 2 and 6 for a total price of 6 +
  // 19= 25.

  // Input :price = [1, 5, 8, 9], N = 4
  // Output :10
  // Explanation :Cut the rod into lengths of 2 and 2 for a total price of 5 + 5
  // = 10.

  vector<int> price = {1, 6, 8, 9, 10, 19, 7, 20};

  int n = price.size();

  cout << "Answer: " << cutRod(price, n) << endl;
  return 0;
}
