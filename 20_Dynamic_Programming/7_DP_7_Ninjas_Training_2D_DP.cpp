#include <bits/stdc++.h>
using namespace std;

int recursionSol(int day, int last, vector<vector<int>> &points) {
  if (day == 0) {
    int maxi = 0;

    for (int task = 0; task < 3; task++) {
      if (task != last) {
        maxi = max(maxi, points[0][task]);
      }
    }
    return maxi;
  }

  int maxi = 0;
  for (int task = 0; task < 3; task++) {
    if (task != last) {
      int point = points[day][task] + recursionSol(day - 1, task, points);
      maxi = max(maxi, point);
    }
  }
  return maxi;
}

int memoizationSol(int day, int last, vector<vector<int>> &points,
                   vector<vector<int>> &dp) {

  if (day == 0) {
    int maxi = 0;

    for (int task = 0; task < 3; task++) {
      if (task != last) {
        maxi = max(maxi, points[0][task]);
      }
    }
    return maxi;
  }

  if (dp[day][last] != -1) {
    return dp[day][last];
  }

  int maxi = 0;
  for (int task = 0; task < 3; task++) {
    if (task != last) {
      int point = points[day][task] + memoizationSol(day - 1, task, points, dp);
      maxi = max(maxi, point);
    }
  }

  dp[day][last] = maxi;
  return dp[day][last];
}
int tabulationSol(int n, vector<vector<int>> &points, vector<vector<int>> &dp) {

  // Base Case
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);

  // last = 3 means no task was performed before
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  // Start from day 1
  for (int day = 1; day < n; day++) {

    // last can be 0, 1, 2, or 3
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;

      for (int task = 0; task < 3; task++) {
        if (task != last) {
          int point = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], point);
        }
      }
    }
  }
  // On the last day, last = 3 means
  // there is no restriction from a previous task
  return dp[n - 1][3];
}

int spaceOptimizationSol(int n, vector<vector<int>> &points, vector<int> &dp) {

  // Base Case
  dp[0] = max(points[0][1], points[0][2]);
  dp[1] = max(points[0][0], points[0][2]);
  dp[2] = max(points[0][0], points[0][1]);

  // last = 3 means no task was performed before
  dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

  // Start from day 1
  for (int day = 1; day < n; day++) {
    vector<int> temp(4, -1);
    // last can be 0, 1, 2, or 3
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;

      for (int task = 0; task < 3; task++) {
        if (task != last) {
          int point = points[day][task] + dp[task];
          temp[last] = max(temp[last], point);
        }
      }
    }
    dp = temp;
  }
  // On the last day, last = 3 means
  // there is no restriction from a previous task
  return dp[3];
}

int ninjaTraining(int n, vector<vector<int>> &points) {

  // ---------------------------------
  // Recursion
  // ---------------------------------

  int ans1 = recursionSol(n - 1, 3, points);

  cout << "Recursion Answer: " << ans1 << endl;

  // ---------------------------------
  // Memoization
  // ---------------------------------

  vector<vector<int>> dp(n, vector<int>(4, -1));

  int ans2 = memoizationSol(n - 1, 3, points, dp);

  cout << "Memoization Answer: " << ans2 << endl;

  // ---------------------------------
  // Tabulation
  // ---------------------------------

  vector<vector<int>> dp2(n, vector<int>(4, -1));

  int ans3 = tabulationSol(n, points, dp2);

  cout << "Tabulation Answer: " << ans3 << endl;

  // ---------------------------------
  // Space Optimization
  // ---------------------------------

  vector<int> dp3(4, -1);

  int ans4 = spaceOptimizationSol(n, points, dp3);

  cout << "Space Optimization Answer: " << ans4 << endl;

  // ---------------------------------
  // Final Answer
  // ---------------------------------

  cout << "Final Answer: " << ans4 << endl;

  return ans4;
}
// | Approach           |                    Time |               Space |
// | ------------------ | ----------------------: | ------------------: |
// | Recursion          |   O(3^N)  approximately |               O(N)  |
// | Memoization        |  O(N × 4 × 3)  →  O(N)  |           O(N × 4)  |
// | Tabulation         |  O(N × 4 × 3)  →  O(N)  |           O(N × 4)  |
// | Space Optimization |  O(N × 4 × 3)  →  O(N)  |    O(4)  →  O(1)    |

int main() {
  cout << "7 DP 7 Ninjas Training 2D DP" << endl;

  // Ninja is planing this ‘N’ days-long training schedule. Each day, he can
  // perform any one of these three activities. (Running, Fighting Practice or
  // Learning New Moves). Each activity has some merit points on each day. As
  // Ninja has to improve all his skills, he can’t do the same activity in two
  // consecutive days. Can you help Ninja find out the maximum merit points
  // Ninja can earn?

  // You are given a 2D array of size N*3 ‘POINTS’ with the points
  // corresponding to each day and activity. Your task is to calculate the
  // maximum number of merit points that Ninja can earn.

  // For Example
  // If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer
  // will be 11 as 5 + 3 + 3.

  // Ninja is planning this N-days-long training schedule.
  //
  // Each day, he can perform one of three activities:
  //
  // 0 -> Running
  // 1 -> Fighting Practice
  // 2 -> Learning New Moves
  //
  // He cannot perform the same activity
  // on two consecutive days.
  //
  // Find the maximum merit points.

  vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};

  int n = points.size();

  ninjaTraining(n, points);
  return 0;
}
