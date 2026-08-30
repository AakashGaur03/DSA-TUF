#include <bits/stdc++.h>
using namespace std;

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
  return spaceOptimizedSol(n, arr, (totalSum - d) / 2);
}

// Exact Same as 18_DP_18_Count_Partitions_With_Given_Difference
int targetSum(int target, vector<int> &arr) {
  int n = arr.size();
  return countPartitions(n, target, arr);
}

int main() {

  cout << "21 DP 21 Target Sum" << endl;

  //   You are given an integer array nums and an integer target.

  // You want to build an expression out of nums by adding one of the symbols
  // '+' and '-' before each integer in nums and then concatenate all the
  // integers.

  // For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before
  // 1 and concatenate them to build the expression "+2-1". Return the number of
  // different expressions that you can build, which evaluates to target.

  // Example 1:

  // Input: nums = [1,1,1,1,1], target = 3
  // Output: 5
  // Explanation: There are 5 ways to assign symbols to make the sum of nums be
  // target 3. -1 + 1 + 1 + 1 + 1 = 3 +1 - 1 + 1 + 1 + 1 = 3 +1 + 1 - 1 + 1 + 1
  // = 3 +1 + 1 + 1 - 1 + 1 = 3 +1 + 1 + 1 + 1 - 1 = 3 Example 2:

  // Input: nums = [1], target = 1
  // Output: 1

  vector<int> arr = {1, 2, 3, 1};
  int target = 3;

  int ans = targetSum(target, arr);

  cout << "Final Answer: " << ans << endl;

  //   Target Sum → Count Partitions

  // We have an expression where every number gets either + or -.
  // For example:
  // +1 +2 -3 +1

  // We combine all the positive (+) elements into S1:
  // S1 = 1 + 2 + 1

  // And combine all the negative (-) elements into S2:
  // S2 = 3

  // So the original expression:
  // +1 +2 -3 +1

  // becomes:
  // S1 - S2

  // Therefore:
  // S1 - S2 = target

  // And since every element is either in S1 or S2:
  // S1 + S2 = totalSum

  // So, Target Sum is converted into the Count Partitions With Given Difference
  // problem.
  return 0;
}
