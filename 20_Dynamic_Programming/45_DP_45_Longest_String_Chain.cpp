
#include <bits/stdc++.h>
using namespace std;
bool comp(string &a, string &b) { return a.size() < b.size(); }

bool compareStringDiffernceIsOne(string &a, string &b) {
  if (a.size() != b.size() + 1) {
    return false;
  }
  int first = 0;
  int second = 0;

  while (first < a.size()) {
    if (second < b.size() && a[first] == b[second]) {
      first++;
      second++;
    } else {
      first++;
    }
  }
  if (first == a.size() && second == b.size()) {
    return true;
  }
  return false;
}

int recursionSol(int ind, int prevInd, vector<string> &nums) {
  int n = nums.size();
  if (ind == n) {
    return 0;
  }

  int pick = 0;
  if (prevInd == -1 || compareStringDiffernceIsOne(nums[ind], nums[prevInd])) {
    pick = 1 + recursionSol(ind + 1, ind, nums);
  }

  int notPick = 0 + recursionSol(ind + 1, prevInd, nums);

  return max(pick, notPick);
}

int memoizationSol(int ind, int prevInd, vector<string> &nums,
                   vector<vector<int>> &dp) {
  int n = nums.size();
  if (ind == n) {
    return 0;
  }
  if (dp[ind][prevInd + 1] != -1) {
    return dp[ind][prevInd + 1];
  }

  int pick = 0;
  if (prevInd == -1 || compareStringDiffernceIsOne(nums[ind], nums[prevInd])) {
    pick = 1 + memoizationSol(ind + 1, ind, nums, dp);
  }

  int notPick = 0 + memoizationSol(ind + 1, prevInd, nums, dp);

  return dp[ind][prevInd + 1] = max(pick, notPick);
}

int tabulationSol(vector<string> &nums, vector<vector<int>> &dp) {
  int n = nums.size();

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
      int pick = 0;
      if (prevInd == -1 ||
          compareStringDiffernceIsOne(nums[ind], nums[prevInd])) {
        pick = 1 + dp[ind + 1][ind + 1];
      }

      int notPick = 0 + dp[ind + 1][prevInd + 1];

      dp[ind][prevInd + 1] = max(pick, notPick);
    }
  }
  return dp[0][0];
}
int spaceOptimziation(vector<string> &nums) {
  int n = nums.size();
  vector<int> next(n + 1, 0), curr(n + 1, 0);

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
      int pick = 0;
      if (prevInd == -1 ||
          compareStringDiffernceIsOne(nums[ind], nums[prevInd])) {
        pick = 1 + next[ind + 1];
      }

      int notPick = 0 + next[prevInd + 1];

      curr[prevInd + 1] = max(pick, notPick);
    }
    next = curr;
  }
  return next[0];
}
int spaceOptimziation2ndApporach(vector<string> &nums) {
  // Refer 42_DP_42_Prinitng_Longest_Increasing_Subsequence_1
  int n = nums.size();
  if (n == 0) {
    return 0;
  }
  int maxi = 1;
  vector<int> dp(n, 1);
  for (int i = 0; i < n; i++) {
    for (int prev = 0; prev < i; prev++) {
      if (compareStringDiffernceIsOne(nums[i], nums[prev])) {
        dp[i] = max(dp[i], 1 + dp[prev]);
      }
    }
    maxi = max(maxi, dp[i]);
  }
  return maxi;
}

int longestStrChain(vector<string> &words) {

  sort(words.begin(), words.end(), comp);

  int n = words.size();

  // Recursion
  int ans1 = recursionSol(0, -1, words);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  int ans2 = memoizationSol(0, -1, words, dp);

  // Tabulation
  vector<vector<int>> dp2(n + 1, vector<int>(n + 1, 0));
  int ans3 = tabulationSol(words, dp2);

  // Space Optimization
  int ans4 = spaceOptimziation(words);

  // Space Optimization 2nd Approach
  int ans5 = spaceOptimziation2ndApporach(words);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;
  cout << "Space Optimization 2nd Approach: " << ans5 << endl;

  return ans5;
}

int main() {

  cout << "45 DP 45 Longest String Chain" << endl;
  // Longest String Chain
  // You are given an array of words where each word consists of lowercase
  // English letters.

  // wordA is a predecessor of wordB if and only if we can insert exactly one
  // letter anywhere in wordA without changing the order of the other characters
  // to make it equal to wordB.

  // For example, "abc" is a predecessor of "abac", while "cba" is not a
  // predecessor of "bcad". A word chain is a sequence of words [word1, word2,
  // ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a
  // predecessor of word3, and so on. A single word is trivially a word chain
  // with k == 1.

  // Return the length of the longest possible word chain with words chosen from
  // the given list of words.

  // Example 1:

  // Input: words = ["a","b","ba","bca","bda","bdca"]
  // Output: 4
  // Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
  // Example 2:

  // Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
  // Output: 5
  // Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc",
  // "pcxbc", "pcxbcf"]. Example 3:

  // Input: words = ["abcd","dbqca"]
  // Output: 1
  // Explanation: The trivial word chain ["abcd"] is one of the longest word
  // chains.
  // ["abcd","dbqca"] is not a valid word chain because the ordering of the
  // letters is changed.

  // Similar to LIS just to sort acc to Size and instead of increasing we need
  // to check if the string size only differs by One or not

  // Example 1
  vector<string> words1 = {"a", "b", "ba", "bca", "bda", "bdca"};

  cout << "\nExample 1:" << endl;

  int answer1 = longestStrChain(words1);

  cout << "Final Answer: " << answer1 << endl;

  // Example 2
  vector<string> words2 = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};

  cout << "\nExample 2:" << endl;

  int answer2 = longestStrChain(words2);

  cout << "Final Answer: " << answer2 << endl;

  // Example 3
  vector<string> words3 = {"abcd", "dbqca"};

  cout << "\nExample 3:" << endl;

  int answer3 = longestStrChain(words3);

  cout << "Final Answer: " << answer3 << endl;

  return 0;
}