
#include <bits/stdc++.h>
using namespace std;

// Recursive solution
//
// Main idea:
//
// We are given cut positions.
// Example:
// n = 7
// cuts = [1, 3, 4, 5]
//
// First, we add the two boundaries:
//
// cuts = [0, 1, 3, 4, 5, 7]
//
// Now recursionSol(i, j) means:
//
// "Find the minimum cost to perform all cuts from
//  index i to index j in the cuts array."
//
// Important:
//
// We are NOT deciding the order in which cuts are performed
// from left to right.
//
// Instead, we try every possible cut as the FIRST cut
// inside the current stick segment.
//
// Once we make one cut, the stick is divided into two parts.
// We recursively solve the left and right parts.

int recursionSol(int i, int j, vector<int> &cuts) {
  if (i > j) {
    return 0;
  }

  int mini = INT_MAX;
  for (int ind = i; ind <= j; ind++) {

    // Cost of making the current cut.
    //
    // The current stick segment starts at:
    // cuts[i - 1]
    //
    // and ends at:
    // cuts[j + 1]
    //
    // Therefore, length of the current stick is:
    //
    // cuts[j + 1] - cuts[i - 1]
    //
    // Since the current cut is the FIRST cut in this
    // segment, we have to pay the complete length
    // of this segment.
    //
    // After making this cut:
    //
    // Left part  -> recursionSol(i, ind - 1)
    // Right part -> recursionSol(ind + 1, j)
    //
    // So total cost is:
    //
    // Current cut cost
    // +
    // Minimum cost of left part
    // +
    // Minimum cost of right part
    int cost = cuts[j + 1] - cuts[i - 1] + recursionSol(i, ind - 1, cuts) +
               recursionSol(ind + 1, j, cuts);
    mini = min(mini, cost);
  }
  return mini;
}

int memoizationSol(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
  if (i > j) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  int mini = INT_MAX;
  for (int ind = i; ind <= j; ind++) {

    int cost = cuts[j + 1] - cuts[i - 1] +
               memoizationSol(i, ind - 1, cuts, dp) +
               memoizationSol(ind + 1, j, cuts, dp);
    mini = min(mini, cost);
  }
  return dp[i][j] = mini;
}

int tabulationSol(int c, vector<int> &cuts, vector<vector<int>> &dp) {

  for (int i = c; i >= 1; i--) {
    for (int j = i; j <= c; j++) {
      if (i > j) {
        continue;
      }

      int mini = INT_MAX;
      for (int ind = i; ind <= j; ind++) {

        int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
        mini = min(mini, cost);
      }
      dp[i][j] = mini;
    }
  }
  return dp[1][c];
}

int minCost(int n, vector<int> &cuts) {

  int c = cuts.size();

  cuts.push_back(n);
  cuts.insert(cuts.begin(), 0);

  sort(cuts.begin(), cuts.end());

  // Recursion
  int ans1 = recursionSol(1, c, cuts);

  // Memoization
  vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

  int ans2 = memoizationSol(1, c, cuts, dp);

  // Tabulation
  vector<vector<int>> dp2(c + 2, vector<int>(c + 2, 0));

  int ans3 = tabulationSol(c, cuts, dp2);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;

  return ans3;
}

int main() {

  cout << "50 DP 50 Minimum Cost to Cut the Stick" << endl;
  // Given a wooden stick of length n units. The stick is labelled from 0 to n.
  // For example, a stick of length 6 is labelled as follows:

  // Given an integer array cuts where cuts[i] denotes a position you should
  // perform a cut at.

  // You should perform the cuts in order, you can change the order of the cuts
  // as you wish.

  // The cost of one cut is the length of the stick to be cut, the total cost is
  // the sum of costs of all cuts. When you cut a stick, it will be split into
  // two smaller sticks (i.e. the sum of their lengths is the length of the
  // stick before the cut). Please refer to the first example for a better
  // explanation.

  // Return the minimum total cost of the cuts.

  // Example 1:

  // Input: n = 7, cuts = [1,3,4,5]
  // Output: 16
  // Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the
  // following scenario:

  // The first cut is done to a rod of length 7 so the cost is 7. The second cut
  // is done to a rod of length 6 (i.e. the second part of the first cut), the
  // third is done to a rod of length 4 and the last cut is to a rod of
  // length 3. The total cost is 7 + 6 + 4 + 3 = 20. Rearranging the cuts to be
  // [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as
  // shown in the example photo 7 + 4 + 3 + 2 = 16). Example 2:

  // Input: n = 9, cuts = [5,6,1,4,2]
  // Output: 22
  // Explanation: If you try the given cuts ordering the cost will be 25.
  // There are much ordering with total cost <= 25, for example, the order [4,
  // 6, 5, 2, 1] has total cost = 22 which is the minimum possible.

  vector<int> cuts = {1, 3, 4, 5};

  int answer = minCost(7, cuts);

  cout << "Final Answer: " << answer << endl;

  return 0;
}
