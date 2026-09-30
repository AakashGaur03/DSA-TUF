
#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// Recursion
// ------------------------------------------------------------

pair<int, int> recursionSol(int ind, int prevInd, vector<int> &nums) {

  int n = nums.size();

  if (ind == n) {
    // Length = 0
    // One empty subsequence
    return {0, 1};
  }

  // Not Pick
  pair<int, int> notPick = recursionSol(ind + 1, prevInd, nums);

  pair<int, int> pick = {0, 0};

  // Pick
  if (prevInd == -1 || nums[ind] > nums[prevInd]) {

    pair<int, int> next = recursionSol(ind + 1, ind, nums);

    pick.first = 1 + next.first;
    pick.second = next.second;
  }

  // Pick gives longer LIS
  if (pick.first > notPick.first) {
    return pick;
  }

  // Not Pick gives longer LIS
  if (notPick.first > pick.first) {
    return notPick;
  }

  // Both give same LIS length
  return {pick.first, pick.second + notPick.second};
}

// ------------------------------------------------------------
// Memoization
// ------------------------------------------------------------

pair<int, int> memoizationSol(int ind, int prevInd, vector<int> &nums,
                              vector<vector<pair<int, int>>> &dp,
                              vector<vector<bool>> &visited) {

  int n = nums.size();

  if (ind == n) {
    return {0, 1};
  }

  if (visited[ind][prevInd + 1]) {
    return dp[ind][prevInd + 1];
  }

  visited[ind][prevInd + 1] = true;

  // Not Pick
  pair<int, int> notPick = memoizationSol(ind + 1, prevInd, nums, dp, visited);

  pair<int, int> pick = {0, 0};

  // Pick
  if (prevInd == -1 || nums[ind] > nums[prevInd]) {

    pair<int, int> next = memoizationSol(ind + 1, ind, nums, dp, visited);

    pick.first = 1 + next.first;
    pick.second = next.second;
  }

  // Pick gives longer LIS
  if (pick.first > notPick.first) {
    return dp[ind][prevInd + 1] = pick;
  }

  // Not Pick gives longer LIS
  if (notPick.first > pick.first) {
    return dp[ind][prevInd + 1] = notPick;
  }

  // Both give same LIS length
  return dp[ind][prevInd + 1] = {pick.first, pick.second + notPick.second};
}

// ------------------------------------------------------------
// Tabulation
// ------------------------------------------------------------

pair<int, int> tabulationSol(vector<int> &nums,
                             vector<vector<pair<int, int>>> &dp) {

  int n = nums.size();

  // Base case:
  // ind == n
  // Length = 0
  // Count = 1
  for (int prevInd = -1; prevInd < n; prevInd++) {
    dp[n][prevInd + 1] = {0, 1};
  }

  for (int ind = n - 1; ind >= 0; ind--) {

    for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {

      pair<int, int> notPick = dp[ind + 1][prevInd + 1];

      pair<int, int> pick = {0, 0};

      if (prevInd == -1 || nums[ind] > nums[prevInd]) {

        pair<int, int> next = dp[ind + 1][ind + 1];

        pick.first = 1 + next.first;
        pick.second = next.second;
      }

      // Pick gives longer LIS
      if (pick.first > notPick.first) {
        dp[ind][prevInd + 1] = pick;
      }

      // Not Pick gives longer LIS
      else if (notPick.first > pick.first) {
        dp[ind][prevInd + 1] = notPick;
      }

      // Both give same LIS length
      else {
        dp[ind][prevInd + 1] = {pick.first, pick.second + notPick.second};
      }
    }
  }

  return dp[0][0];
}

// ------------------------------------------------------------
// Space Optimization
// ------------------------------------------------------------

pair<int, int> spaceOptimziation(vector<int> &nums) {

  int n = nums.size();

  // {length, count}
  vector<pair<int, int>> next(n + 1, {0, 1});
  vector<pair<int, int>> curr(n + 1, {0, 1});

  for (int ind = n - 1; ind >= 0; ind--) {

    for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {

      pair<int, int> notPick = next[prevInd + 1];

      pair<int, int> pick = {0, 0};

      if (prevInd == -1 || nums[ind] > nums[prevInd]) {

        pair<int, int> afterPick = next[ind + 1];

        pick.first = 1 + afterPick.first;
        pick.second = afterPick.second;
      }

      // Pick gives longer LIS
      if (pick.first > notPick.first) {
        curr[prevInd + 1] = pick;
      }

      // Not Pick gives longer LIS
      else if (notPick.first > pick.first) {
        curr[prevInd + 1] = notPick;
      }

      // Both give same LIS length
      else {
        curr[prevInd + 1] = {pick.first, pick.second + notPick.second};
      }
    }

    next = curr;
  }

  return next[0];
}

// ------------------------------------------------------------
// Space Optimization 2nd Approach
// ------------------------------------------------------------

int spaceOptimziation2ndApporach(vector<int> &nums) {

  // Refer 42_DP_42_Prinitng_Longest_Increasing_Subsequence_1

  int n = nums.size();

  if (n == 0) {
    return 0;
  }

  vector<int> dp(n, 1);

  // cnt[i] = number of LIS of length dp[i]
  // ending at index i
  vector<int> cnt(n, 1);

  int maxi = 1;

  for (int i = 0; i < n; i++) {

    for (int prev = 0; prev < i; prev++) {

      if (nums[prev] < nums[i]) {

        // Found a longer LIS
        if (1 + dp[prev] > dp[i]) {

          dp[i] = 1 + dp[prev];

          cnt[i] = cnt[prev];
        }

        // Found another LIS of same length
        else if (1 + dp[prev] == dp[i]) {

          cnt[i] += cnt[prev];
        }
      }
    }

    maxi = max(maxi, dp[i]);
  }

  // Number of LIS having maximum length
  int nos = 0;

  for (int i = 0; i < n; i++) {

    if (dp[i] == maxi) {
      nos += cnt[i];
    }
  }

  return nos;
}

int findNumberOfLIS(vector<int> &nums) {

  int n = nums.size();

  if (n == 0) {
    return 0;
  }

  // Recursion
  pair<int, int> ans1 = recursionSol(0, -1, nums);

  // Memoization
  vector<vector<pair<int, int>>> dp1(n, vector<pair<int, int>>(n + 1));

  vector<vector<bool>> visited(n, vector<bool>(n + 1, false));

  pair<int, int> ans2 = memoizationSol(0, -1, nums, dp1, visited);

  // Tabulation
  vector<vector<pair<int, int>>> dp2(n + 1,
                                     vector<pair<int, int>>(n + 1, {0, 1}));

  pair<int, int> ans3 = tabulationSol(nums, dp2);

  // Space Optimization
  pair<int, int> ans4 = spaceOptimziation(nums);

  // Space Optimization 2nd Approach
  int ans5 = spaceOptimziation2ndApporach(nums);

  cout << "Recursion: " << ans1.second << endl;
  cout << "Memoization: " << ans2.second << endl;
  cout << "Tabulation: " << ans3.second << endl;
  cout << "Space Optimization: " << ans4.second << endl;
  cout << "Space Optimization 2nd Approach: " << ans5 << endl;

  return ans5;
}

// | Approach                        | Time Complexity | Space Complexity |
// | --------------------------------| --------------: | ---------------: |
// | Recursion                       |         O(2^N)  |            O(N)  |
// | Memoization                     |          O(N²)  |    O(N²) + O(N)  |
// | Tabulation                      |          O(N²)  |           O(N²)  |
// | Space Optimization              |          O(N²)  |            O(N)  |
// | Space Optimization 2nd Approach |          O(N²)  |            O(N)  |

int main() {

  cout << "47 DP 47 Number of Longest Increasing Subsequences" << endl;

  // Number of Longest Increasing Subsequence
  // Given an integer array nums, return the number of longest increasing
  // subsequences.

  // Notice that the sequence has to be strictly increasing.

  // Example 1:

  // Input: nums = [1,3,5,4,7]
  // Output: 2
  // Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and
  // [1, 3, 5, 7]. Example 2:

  // Input: nums = [2,2,2,2,2]
  // Output: 5
  // Explanation: The length of the longest increasing subsequence is 1, and
  // there are 5 increasing subsequences of length 1, so output 5.

  // It is the extension of 42_DP_42_Prinitng_Longest_Increasing_Subsequence

  vector<int> arr1 = {1, 3, 5, 4, 7};

  cout << "\nExample 1:" << endl;

  int answer1 = findNumberOfLIS(arr1);

  cout << "Final Answer: " << answer1 << endl;

  vector<int> arr2 = {2, 2, 2, 2, 2};

  cout << "\nExample 2:" << endl;

  int answer2 = findNumberOfLIS(arr2);

  cout << "Final Answer: " << answer2 << endl;
  return 0;
}

/*

// cnt[i] = Number of Longest Increasing Subsequences
//          having length dp[i] and ending at index i.
//
// Initially:
// Every single element itself is an LIS of length 1.
// Therefore:
// dp[i] = 1
// cnt[i] = 1


if (nums[prev] < nums[i]) {

    // --------------------------------------------------------
    // Case 1: We found a LONGER LIS
    // --------------------------------------------------------
    //
    // If:
    // 1 + dp[prev] > dp[i]
    //
    // It means by taking nums[i] after nums[prev],
    // we can create a longer increasing subsequence.
    //
    // So update the LIS length.
    //
    // Since all the LIS ending at prev can be extended
    // by nums[i], the number of ways becomes cnt[prev].
    //
    // Example:
    //
    // dp[i] = 2
    // 1 + dp[prev] = 3
    //
    // New better length found.
    //
    // Therefore:
    // dp[i] = 3
    // cnt[i] = cnt[prev]
    //
    // Longer Length -> Replace Count
    // --------------------------------------------------------

    if (1 + dp[prev] > dp[i]) {

        dp[i] = 1 + dp[prev];

        cnt[i] = cnt[prev];
    }

    // --------------------------------------------------------
    // Case 2: We found ANOTHER LIS of the SAME length
    // --------------------------------------------------------
    //
    // If:
    // 1 + dp[prev] == dp[i]
    //
    // It means we already have an LIS of this length
    // ending at i, but now we found another way to create
    // an LIS of the SAME length.
    //
    // Therefore, add the number of ways from prev.
    //
    // Example:
    //
    // Existing:
    // dp[i] = 3
    // cnt[i] = 2
    //
    // From another prev:
    // 1 + dp[prev] = 3
    // cnt[prev] = 1
    //
    // Therefore:
    // cnt[i] = 2 + 1 = 3
    //
    // Same Length -> Add Count
    // --------------------------------------------------------

    else if (1 + dp[prev] == dp[i]) {

        cnt[i] += cnt[prev];
    }
}

*/