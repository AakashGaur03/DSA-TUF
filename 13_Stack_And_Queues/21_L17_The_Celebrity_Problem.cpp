#include <bits/stdc++.h>
using namespace std;

int celebrityProblemBrute(vector<vector<int>> arr) {
  // TC O(N*N) + O(N)
  // SC O(2N)
  // Brute Force
  // we can have two array
  // knowMe represents how many people knows me
  // IKnow how many people I know
  // Refer to 21_L17_The_Celebrity_Problem_1
  int n = arr.size();
  vector<int> knowMe(n, 0);
  vector<int> Iknow(n, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == 1) {
        Iknow[i]++;
        knowMe[j]++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (knowMe[i] == n - 1 && Iknow[i] == 0) {
      return i;
    }
  }

  return -1;
}
int celebrityProblemOptimal(vector<vector<int>> arr) {
  // TC O(2N)
  // SC O(1)
  // Minimum there can be 0 celebrity (If all are 1)
  // At max there can be only 1 celebrity (Think Logically)

  // We will take two pointers
  // Top and Down and will get to single person
  // that can be a celebrity after that check that
  // coloumn and row
  // Full Row = 0 and Full Col except that index 0 then Celebrity

  // arr[top][down] means does top knows down

  int n = arr.size();
  int top = 0;
  int down = n - 1;
  while (top < down) {
    if (arr[top][down] == 1) {
      top++; // top knows down → top not celebrity
    } else {
      down--; // top doesn't know down → down not celebrity
    }
  }

  // means top == down
  for (int i = 0; i < n; i++) {
    if (i == top) {
      // Diagnol 1 doesnt know himself
      continue;
    }
    if (arr[top][i] == 0 && arr[i][top] == 1) {
    } else {
      return -1;
    }
  }

  return top;
}

int main() {
  cout << "21 L17 The Celebrity Problem" << endl;
  // We will have N X N matrix containing 0 and 1s
  // We have N people
  // matrix is used to represent people at the party such that if an element of
  // row i and column j is set to 1 it means ith person knows jth person
  // So if arr[0][2] = 1 means 0 knows 2
  // and if arr[2][0] = 0 means 2 doesnt knows 0

  // We have to figure out celebrity over here
  // A celebrity is a person who is known to all but does not know anyone at a
  // party.
  // In this below example Person 1 is celebrity
  // He know Nobody and everyone knows him
  vector<vector<int>> arr = {
      {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
  int res = celebrityProblemBrute(arr);
  cout << "Celebrity is: " << res;
  cout << endl;
  int res2 = celebrityProblemOptimal(arr);
  cout << "Celebrity is: " << res2;
  return 0;
}
