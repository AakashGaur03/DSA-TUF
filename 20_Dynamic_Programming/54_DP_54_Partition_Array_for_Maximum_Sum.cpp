
#include <bits/stdc++.h>
using namespace std;

int recursionSol(int i, vector<int> &arr, int k) {
  int n = arr.size();

  if (i == n) {
    return 0;
  }

  int currLen = 0;
  int maxi = INT_MIN;
  int maxAns = INT_MIN;
  for (int j = i; j < min(n, i + k); j++) {
    currLen++;
    maxi = max(maxi, arr[j]);
    int sum = (currLen * maxi) + recursionSol(j + 1, arr, k);
    maxAns = max(maxAns, sum);
  }

  return maxAns;
}

int memoizationSol(int i, vector<int> &arr, int k, vector<int> &dp) {
  int n = arr.size();

  if (i == n) {
    return 0;
  }

  if (dp[i] != -1) {
    return dp[i];
  }
  int currLen = 0;
  int maxi = INT_MIN;
  int maxAns = 0;
  for (int j = i; j < min(n, i + k); j++) {
    currLen++;
    maxi = max(maxi, arr[j]);
    int sum = (currLen * maxi) + memoizationSol(j + 1, arr, k, dp);
    maxAns = max(maxAns, sum);
  }

  return dp[i] = maxAns;
}

int tabulationSol(vector<int> &arr, int k, vector<int> &dp) {

  int n = arr.size();
  dp[n] = 0;

  for (int i = n - 1; i >= 0; i--) {
    int currLen = 0;
    int maxi = INT_MIN;
    int maxAns = 0;
    for (int j = i; j < min(n, i + k); j++) {
      currLen++;
      maxi = max(maxi, arr[j]);
      int sum = (currLen * maxi) + dp[j + 1];
      maxAns = max(maxAns, sum);
    }

    dp[i] = maxAns;
  }
  return dp[0];
}

int maxSumAfterPartitioning(vector<int> &arr, int k) {

  int n = arr.size();

  int ans1 = recursionSol(0, arr, k);

  vector<int> dp(n, -1);
  int ans2 = memoizationSol(0, arr, k, dp);

  vector<int> dp2(n + 1, 0);
  int ans3 = tabulationSol(arr, k, dp2);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;

  return ans3;
}

int main() {

  cout << "54 DP 54 Partition Array for Maximum Sum" << endl;

  // 1043. Partition Array for Maximum Sum
  // Given an integer array arr, partition the array into (contiguous) subarrays
  // of length at most k. After partitioning, each subarray has their values
  // changed to become the maximum value of that subarray.

  // Return the largest sum of the given array after partitioning. Test cases
  // are generated so that the answer fits in a 32-bit integer.

  // Example 1:

  // Input: arr = [1,15,7,9,2,5,10], k = 3
  // Output: 84
  // Explanation: arr becomes [15,15,15,9,10,10,10]
  // Example 2:

  // Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
  // Output: 83
  // Example 3:

  // Input: arr = [1], k = 1
  // Output: 1

  vector<int> arr1 = {1, 15, 7, 9, 2, 5, 10};
  int k1 = 3;

  cout << "\nExample 1:" << endl;
  maxSumAfterPartitioning(arr1, k1);

  vector<int> arr2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
  int k2 = 4;

  cout << "\nExample 2:" << endl;
  maxSumAfterPartitioning(arr2, k2);

  vector<int> arr3 = {1};
  int k3 = 1;

  cout << "\nExample 3:" << endl;
  maxSumAfterPartitioning(arr3, k3);

  return 0;
}
