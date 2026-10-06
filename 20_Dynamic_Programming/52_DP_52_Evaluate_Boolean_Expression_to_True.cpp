
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int recursionSol(int i, int j, int isTrue, string a) {
  if (i > j) {
    return 0;
  }
  if (i == j) {
    if (isTrue == 1) {
      // If we are looking for True
      return a[i] == 'T';
    } else {
      // If we are looking for False
      return a[i] == 'F';
    }
  }
  int noOfWays = 0;

  for (int ind = i + 1; ind <= j - 1; ind = ind + 2) {
    int leftPartitionTrue = recursionSol(i, ind - 1, 1, a);
    int leftPartitionFalse = recursionSol(i, ind - 1, 0, a);
    int rightPartitionTrue = recursionSol(ind + 1, j, 1, a);
    int rightPartitionFalse = recursionSol(ind + 1, j, 0, a);

    if (a[ind] == '&') {
      if (isTrue) {
        noOfWays =
            (noOfWays + 1LL * leftPartitionTrue * rightPartitionTrue) % MOD;
      } else {
        noOfWays = (noOfWays + 1LL * leftPartitionTrue * rightPartitionFalse +
                    1LL * leftPartitionFalse * rightPartitionTrue +
                    1LL * leftPartitionFalse * rightPartitionFalse) %
                   MOD;
      }
    } else if (a[ind] == '|') {
      if (isTrue) {
        noOfWays = (noOfWays + (1LL * leftPartitionTrue * rightPartitionTrue) +
                    (1LL * leftPartitionTrue * rightPartitionFalse) +
                    (1LL * leftPartitionFalse * rightPartitionTrue)) %
                   MOD;
      } else {
        noOfWays =
            (noOfWays + (1LL * leftPartitionFalse * rightPartitionFalse)) % MOD;
      }
    } else {
      // a[ind] == '^'
      if (isTrue) {
        noOfWays = (noOfWays + (1LL * leftPartitionTrue * rightPartitionFalse) +
                    (1LL * leftPartitionFalse * rightPartitionTrue)) %
                   MOD;
      } else {
        noOfWays = (noOfWays + (1LL * leftPartitionTrue * rightPartitionTrue) +
                    (1LL * leftPartitionFalse * rightPartitionFalse)) %
                   MOD;
      }
    }
  }

  return noOfWays;
}

int memoizationSol(int i, int j, int isTrue, string a,
                   vector<vector<vector<int>>> &dp) {
  if (i > j) {
    return 0;
  }
  if (dp[i][j][isTrue] != -1) {
    return dp[i][j][isTrue];
  }

  if (i == j) {
    if (isTrue == 1) {
      // If we are looking for True
      return dp[i][j][isTrue] = (a[i] == 'T');

    } else {
      // If we are looking for False
      return dp[i][j][isTrue] = (a[i] == 'F');
    }
  }
  int noOfWays = 0;

  for (int ind = i + 1; ind <= j - 1; ind = ind + 2) {
    int leftPartitionTrue = memoizationSol(i, ind - 1, 1, a, dp);
    int leftPartitionFalse = memoizationSol(i, ind - 1, 0, a, dp);
    int rightPartitionTrue = memoizationSol(ind + 1, j, 1, a, dp);
    int rightPartitionFalse = memoizationSol(ind + 1, j, 0, a, dp);

    if (a[ind] == '&') {
      if (isTrue) {
        noOfWays =
            (noOfWays + (1LL * leftPartitionTrue * rightPartitionTrue)) % MOD;
      } else {
        noOfWays = (noOfWays + (1LL * leftPartitionTrue * rightPartitionFalse) +
                    (1LL * leftPartitionFalse * rightPartitionTrue) +
                    (1LL * leftPartitionFalse * rightPartitionFalse)) %
                   MOD;
      }
    } else if (a[ind] == '|') {
      if (isTrue) {
        noOfWays = (noOfWays + (1LL * leftPartitionTrue * rightPartitionTrue) +
                    (1LL * leftPartitionTrue * rightPartitionFalse) +
                    (1LL * leftPartitionFalse * rightPartitionTrue)) %
                   MOD;
      } else {
        noOfWays =
            (noOfWays + (1LL * leftPartitionFalse * rightPartitionFalse)) % MOD;
      }
    } else {
      // a[ind] == '^'
      if (isTrue) {
        noOfWays = (noOfWays + (1LL * leftPartitionTrue * rightPartitionFalse) +
                    (1LL * leftPartitionFalse * rightPartitionTrue)) %
                   MOD;
      } else {
        noOfWays = (noOfWays + (1LL * leftPartitionTrue * rightPartitionTrue) +
                    (1LL * leftPartitionFalse * rightPartitionFalse)) %
                   MOD;
      }
    }
  }

  return dp[i][j][isTrue] = noOfWays;
}

int tabulationSol(int n, string a, vector<vector<vector<int>>> &dp) {

  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {

      for (int isTrue = 0; isTrue <= 1; isTrue++) {
        int noOfWays = 0;

        if (i == j) {

          if (isTrue == 1) {
            dp[i][j][isTrue] = (a[i] == 'T');
          } else {
            dp[i][j][isTrue] = (a[i] == 'F');
          }

          continue;
        }
        for (int ind = i + 1; ind <= j - 1; ind = ind + 2) {

          int leftPartitionTrue = dp[i][ind - 1][1];
          int leftPartitionFalse = dp[i][ind - 1][0];
          int rightPartitionTrue = dp[ind + 1][j][1];
          int rightPartitionFalse = dp[ind + 1][j][0];

          if (a[ind] == '&') {
            if (isTrue) {
              noOfWays =
                  (noOfWays + (1LL * leftPartitionTrue * rightPartitionTrue)) %
                  MOD;
            } else {
              noOfWays =
                  (noOfWays + (1LL * leftPartitionTrue * rightPartitionFalse) +
                   (1LL * leftPartitionFalse * rightPartitionTrue) +
                   (1LL * leftPartitionFalse * rightPartitionFalse)) %
                  MOD;
            }
          } else if (a[ind] == '|') {
            if (isTrue) {
              noOfWays =
                  (noOfWays + (1LL * leftPartitionTrue * rightPartitionTrue) +
                   (1LL * leftPartitionTrue * rightPartitionFalse) +
                   (1LL * leftPartitionFalse * rightPartitionTrue)) %
                  MOD;
            } else {
              noOfWays = (noOfWays +
                          (1LL * leftPartitionFalse * rightPartitionFalse)) %
                         MOD;
            }
          } else {
            // a[ind] == '^'
            if (isTrue) {
              noOfWays =
                  (noOfWays + (1LL * leftPartitionTrue * rightPartitionFalse) +
                   (1LL * leftPartitionFalse * rightPartitionTrue)) %
                  MOD;
            } else {
              noOfWays =
                  (noOfWays + (1LL * leftPartitionTrue * rightPartitionTrue) +
                   (1LL * leftPartitionFalse * rightPartitionFalse)) %
                  MOD;
            }
          }
        }
        dp[i][j][isTrue] = noOfWays;
      }
    }
  }

  return dp[0][n - 1][1];
}

int evaluateExp(string &exp) {

  int n = exp.size();

  // Recursion
  int ans1 = recursionSol(0, n - 1, 1, exp);

  // Memoization
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

  int ans2 = memoizationSol(0, n - 1, 1, exp, dp);

  // Tabulation
  vector<vector<vector<int>>> dp2(n, vector<vector<int>>(n, vector<int>(2, 0)));

  int ans3 = tabulationSol(n, exp, dp2);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;

  return ans3;
}

// | Approach        | Time Complexity | Space Complexity |
// | --------------- | --------------: | ---------------: |
// |   Recursion     |       O(3^N)    |           O(N)   |
// |   Memoization   |         O(N³)   |          O(N²)   |
// |   Tabulation    |         O(N³)   |          O(N²)   |

int main() {
  // Refer 52_DP_52_Evaluate_Boolean_Expression_to_True_1 ,
  // 52_DP_52_Evaluate_Boolean_Expression_to_True_2,
  // 52_DP_52_Evaluate_Boolean_Expression_to_True_3

  cout << "52 DP 52 Evaluate Boolean Expression to True" << endl;

  //   You are given an expression 'exp' in the form of a string where operands
  //   will be : (TRUE or FALSE), and operators will be : (AND, OR or XOR).

  // Now you have to find the number of ways we can parenthesize the expression
  // such that it will evaluate to TRUE.
  // As the answer can be very large, return the output modulo 1000000007.

  // Note :
  // ‘T’ will represent the operand TRUE.
  // ‘F’ will represent the operand FALSE.
  // ‘|’ will represent the operator OR.
  // ‘&’ will represent the operator AND.
  // ‘^’ will represent the operator XOR.

  // Example :
  // Input: 'exp’ = "T|T & F".

  // Output: 1
  // Explanation:
  // There are total 2  ways to parenthesize this expression:
  //     (i) (T | T) & (F) = F
  //     (ii) (T) | (T & F) = T
  // Out of 2 ways, one will result in True, so we will return 1.

  // Example 1
  string exp1 = "T|T&F";

  cout << "\nExample 1: " << exp1 << endl;

  int ans1 = evaluateExp(exp1);

  cout << "Answer: " << ans1 << endl;

  // Example 2
  string exp2 = "T^F|F";

  cout << "\nExample 2: " << exp2 << endl;

  int ans2 = evaluateExp(exp2);

  cout << "Answer: " << ans2 << endl;

  return 0;
}

/*
Approach:
This problem is solved using Partition DP.

We define the state as:
recursionSol(i, j, isTrue)
= number of ways to parenthesize the expression from index i to j
such that it evaluates to True or False depending on isTrue.

For every operator between i and j, we consider that operator as the
last operator to be evaluated. This divides the expression into:

Left  = i ... ind-1
Right = ind+1 ... j

We calculate the number of ways for both left and right parts to become
True and False.

Then, based on the operator (&, |, ^), we use its truth table to find
which combinations of left and right values produce the required result.

Base Cases:
- If i > j, there is no valid expression, so return 0.
- If i == j, the expression contains only one operand.
  Return whether that operand matches the required True/False value.

Recursion:
Try every operator as the partition and recursively calculate all
possible True/False combinations.

Memoization:
Store the result of every (i, j, isTrue) state so that the same
subproblem is not calculated again.

Tabulation:
Build the same DP states iteratively from smaller expression ranges
to larger ranges.

Time Complexity:
- Recursion: Exponential
- Memoization: O(N^3)
- Tabulation: O(N^3)

Space Complexity:
- Recursion: O(N) recursion stack
- Memoization: O(N^2)
- Tabulation: O(N^2)
*/