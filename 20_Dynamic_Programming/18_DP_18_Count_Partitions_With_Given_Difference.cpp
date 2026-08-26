#include <bits/stdc++.h>
using namespace std;

int recursionSol(int ind, vector<int> &num, int k) {
  if (k == 0) {
    return 1;
  }
  if (ind == 0) {
    if (num[ind] == k) {
      return 1;
    } else {
      return 0;
    }
  }
  int notPick = recursionSol(ind - 1, num, k);
  int pick = 0;
  if (num[ind] <= k) {
    pick = recursionSol(ind - 1, num, k - num[ind]);
  }

  return pick + notPick;
}

int memoizationSol(int ind, vector<int> &num, int k, vector<vector<int>> &dp) {

  if (k == 0) {
    return 1;
  }
  if (ind == 0) {
    if (num[ind] == k) {
      return 1;
    } else {
      return 0;
    }
  }
  if (dp[ind][k] != -1) {
    return dp[ind][k];
  }
  int notPick = memoizationSol(ind - 1, num, k, dp);
  int pick = 0;
  if (num[ind] <= k) {
    pick = memoizationSol(ind - 1, num, k - num[ind], dp);
  }
  return dp[ind][k] = pick + notPick;
}

int tabulationSol(int n, vector<int> &num, int k, vector<vector<int>> &dp) {

  // Base Case
  // Look at Changing Parameters and write Nested Loops
  // Recursion will be same as memoization

  for (int i = 0; i < n; i++) {
    dp[i][0] = 1;
  }
  if (num[0] <= k) {
    dp[0][num[0]] = 1;
  }

  for (int ind = 1; ind < n; ind++) {
    for (int sum = 0; sum <= k; sum++) {
      int notPick = dp[ind - 1][sum];
      int pick = 0;
      if (num[ind] <= sum) {
        pick = dp[ind - 1][sum - num[ind]];
      }
      dp[ind][sum] = pick + notPick;
    }
  }

  return dp[n - 1][k];
}
int spaceOptimizedSol(int n, vector<int> &num, int k) {

  // Base Case
  // Look at Changing Parameters and write Nested Loops
  // Recursion will be same as memoization
  vector<int> prev(k + 1, 0);
  vector<int> curr(k + 1, 0);

  prev[0] = 1;
  if (num[0] <= k) {
    prev[num[0]] = 1;
  }

  for (int ind = 1; ind < n; ind++) {
    for (int sum = 0; sum <= k; sum++) {
      int notPick = prev[sum];
      int pick = 0;
      if (num[ind] <= sum) {
        pick = prev[sum - num[ind]];
      }
      curr[sum] = pick + notPick;
    }
    prev = curr;
  }

  return prev[k];
}

// | Approach        |       Time |       Space |
// | --------------- | ----------:| -----------:|
// | Recursion       |    O(2^N)  |  O(N) stack |
// | Memoization     |   O(N × K) |  O(N × K)   |
// | Tabulation      |   O(N × K) |  O(N × K)   |
// | Space Optimized |   O(N × K) |     O(K)    |

int findWays(vector<int> &num, int k) {

  int n = num.size();

  // Recursion
  int ans1 = recursionSol(n - 1, num, k);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));

  int ans2 = memoizationSol(n - 1, num, k, dp);

  // Tabulation
  vector<vector<int>> dp2(n, vector<int>(k + 1, 0));

  int ans3 = tabulationSol(n, num, k, dp2);

  // Space Optimization
  int ans4 = spaceOptimizedSol(n, num, k);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}

int countPartitions(int n, int d, vector<int> &arr) {
  // We convert the problem into Count Subsets With Sum K.
  //
  // Let:
  //      S1 + S2 = totalSum
  //      S1 - S2 = D
  //
  // Therefore:
  //
  //      2 * S2 = totalSum - D
  //
  //      S2 = (totalSum - D) / 2
  //
  // So we only need to count the number of subsets
  // whose sum is (totalSum - D) / 2.

  int totalSum = 0;
  for (auto it : arr) {
    totalSum += it;
  }
  if (totalSum - d < 0 || (totalSum - d) % 2)
    return 0;
  return findWays(arr, (totalSum - d) / 2);
}

int main() {
  cout << "18 DP 18 Count Partitions With Given Difference" << endl;

  //   Problem Statement : Given an array with N positive integers and an
  //   integer D, count the number of ways we can partition the given array into
  //   two subsets, S1 and S2 such that S1 - S2 = D and S1 is always greater
  //   than or equal to S2.

  // Examples
  // Input: arr = [1, 1, 2, 3], diff = 1
  // Output: 3
  // Explanation: The subsets are [1, 2] and [1, 3], [1, 3] and [1, 2], [1, 1,
  // 2] and [3]. Input:  arr = [1, 2, 3, 4], diff = 2 Output: 2 Explanation: The
  // subsets are [1, 3] and [2, 4], [1, 2, 3] and [4].

  vector<int> num = {1, 1, 2, 3};

  int d = 1;

  int ans = countPartitions(num.size(), d, num);

  cout << "Final Answer: " << ans << endl;

  return 0;
}
