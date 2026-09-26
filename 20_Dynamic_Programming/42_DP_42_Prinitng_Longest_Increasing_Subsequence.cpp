
#include <bits/stdc++.h>
using namespace std;

int recursionSol(int ind, int prevInd, vector<int> &nums) {
  int n = nums.size();
  if (ind == n) {
    return 0;
  }

  int pick = 0;
  if (prevInd == -1 || nums[ind] > nums[prevInd]) {
    pick = 1 + recursionSol(ind + 1, ind, nums);
  }

  int notPick = 0 + recursionSol(ind + 1, prevInd, nums);

  return max(pick, notPick);
}

int memoizationSol(int ind, int prevInd, vector<int> &nums,
                   vector<vector<int>> &dp) {
  int n = nums.size();
  if (ind == n) {
    return 0;
  }
  if (dp[ind][prevInd + 1] != -1) {
    return dp[ind][prevInd + 1];
  }

  int pick = 0;
  if (prevInd == -1 || nums[ind] > nums[prevInd]) {
    pick = 1 + memoizationSol(ind + 1, ind, nums, dp);
  }

  int notPick = 0 + memoizationSol(ind + 1, prevInd, nums, dp);

  return dp[ind][prevInd + 1] = max(pick, notPick);
}

int tabulationSol(vector<int> &nums, vector<vector<int>> &dp) {
  int n = nums.size();

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
      int pick = 0;
      if (prevInd == -1 || nums[ind] > nums[prevInd]) {
        pick = 1 + dp[ind + 1][ind + 1];
      }

      int notPick = 0 + dp[ind + 1][prevInd + 1];

      dp[ind][prevInd + 1] = max(pick, notPick);
    }
  }
  return dp[0][0];
}
int spaceOptimziation(vector<int> &nums) {
  int n = nums.size();
  vector<int> next(n + 1, 0), curr(n + 1, 0);

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
      int pick = 0;
      if (prevInd == -1 || nums[ind] > nums[prevInd]) {
        pick = 1 + next[ind + 1];
      }

      int notPick = 0 + next[prevInd + 1];

      curr[prevInd + 1] = max(pick, notPick);
    }
    next = curr;
  }
  return next[0];
}
int spaceOptimziation2ndApporach(vector<int> &nums) {
  // Refer 42_DP_42_Prinitng_Longest_Increasing_Subsequence_1
  int n = nums.size();
  int maxi = 1;
  vector<int> dp(n, 1);
  for (int i = 0; i < n; i++) {
    for (int prev = 0; prev < i; prev++) {
      if (nums[prev] < nums[i]) {
        dp[i] = max(dp[i], 1 + dp[prev]);
      }
    }
    maxi = max(maxi, dp[i]);
  }
  return maxi;
}
int spaceOptimziation2ndApporachAndPrintLIS(vector<int> &nums) {
  // Refer 42_DP_42_Prinitng_Longest_Increasing_Subsequence_2 &
  // 42_DP_42_Prinitng_Longest_Increasing_Subsequence_3
  int n = nums.size();
  int maxi = 1;
  int lastInd = 0;
  vector<int> dp(n, 1), hash(n);
  for (int i = 0; i < n; i++) {
    hash[i] = i;
    for (int prev = 0; prev < i; prev++) {
      if (nums[prev] < nums[i] && dp[i] < 1 + dp[prev]) {
        dp[i] = 1 + dp[prev];
        hash[i] = prev;
      }
    }
    if (dp[i] > maxi) {
      maxi = dp[i];
      lastInd = i;
    }
  }

  vector<int> temp;
  temp.push_back(nums[lastInd]);
  while (hash[lastInd] != lastInd) {
    lastInd = hash[lastInd];
    temp.push_back(nums[lastInd]);
  }

  reverse(temp.begin(), temp.end());
  for (auto it : temp) {
    cout << it << " ";
  }
  cout << endl;

  return maxi;
}

int LIS(vector<int> &nums) {

  int n = nums.size();

  // Recursion
  int ans1 = recursionSol(0, -1, nums);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  int ans2 = memoizationSol(0, -1, nums, dp);
  vector<vector<int>> dp2(n + 1, vector<int>(n + 1, 0));
  int ans3 = tabulationSol(nums, dp2);
  int ans4 = spaceOptimziation(nums);
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;
  int ans5 = spaceOptimziation2ndApporach(nums);
  int ans6 = spaceOptimziation2ndApporachAndPrintLIS(nums);

  cout << "Space Optimization 2nd Approach: " << ans5 << endl;
  cout << "Space Optimization 2nd Approach + Print LIS: " << ans6 << endl;

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;

  return ans2;
}

// | Approach                       |     Time |                    Space |
// | ------------------------------ | -------: | -----------------------: |
// | Recursion                      |  O(2^N)  |                    O(N)  |
// | Memoization                    |   O(N²)  |  O(N²) + O(N)  →  O(N²)  |
// | Tabulation                     |   O(N²)  |                   O(N²)  |
// | Space Optimization             |   O(N²)  |                    O(N)  |
// | Space Optimization 2nd         |   O(N²)  |                    O(N)  |
// | Space Optimization + Print LIS |   O(N²)  |                    O(N)  |

int main() {

  cout << "42 DP 42 Prinitng Longest Increasing Subsequence" << endl;

  // Longest Increasing Subsequence
  // Given an integer array nums, return the length of the longest strictly
  // increasing subsequence.

  // A subsequence is a sequence derived from an array by deleting some or no
  // elements without changing the order of the remaining elements. For example,
  // [3, 6, 2, 7] is a subsequence of [0, 3, 1, 6, 2, 2, 7].

  // The task is to find the length of the longest subsequence in which every
  // element is greater than the previous one.

  // Example 1:
  // Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]

  // Output: 4

  // Explanation: The longest increasing subsequence is [2, 3, 7, 101], and its
  // length is 4.

  // Example 2:
  // Input: nums = [0, 1, 0, 3, 2, 3]

  // Output: 4

  // Explanation: The longest increasing subsequence is [0, 1, 2, 3], and its
  // length is 4
  // Example 1
  vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};

  cout << "\nExample 1:" << endl;
  cout << "Answer: " << LIS(nums1) << endl;

  // Example 2
  vector<int> nums2 = {0, 1, 0, 3, 2, 3};

  cout << "\nExample 2:" << endl;
  cout << "Answer: " << LIS(nums2) << endl;

  return 0;
}