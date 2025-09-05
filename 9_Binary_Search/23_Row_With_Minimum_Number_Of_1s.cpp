#include <bits/stdc++.h>
using namespace std;

int bruteRowWithMax1s(vector<vector<int>> &arr, int n, int m) {
  //  TC O(N*M)
  int res = -1;
  int indx = -1;

  for (int i = 0; i < n; i++) {
    int count1s = 0;
    for (int j = 0; j < m; j++) {
      count1s += arr[i][j];
    }
    if (count1s > res) {
      res = count1s;
      indx = i;
    }
  }

  return indx;
}

int lowerBound(vector<int> &arr, int size, int target) {

  // TC O(log base 2 N)
  int ans = size; // Hypothetical Answer
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] >= target) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans; // Gives the index
}

int optimalRowWithMax1s(vector<vector<int>> &arr, int n, int m) {
  //  TC O(N* log2 m)
  int res = -1;
  int indx = -1;

  for (int i = 0; i < n; i++) {
    int count1s = 0;
    count1s = m - lowerBound(arr[i], m, 1);
    if (count1s > res) {
      res = count1s;
      indx = i;
    }
  }

  return indx;
}

int main() {
  cout << "23 Row With Minimum Number Of 1s" << endl;
  // New Pattern
  // Binary search on 2d Arrays

  vector<vector<int>> arr = {{0, 0, 1, 1, 1},
                             {0, 0, 0, 0, 0},
                             {0, 1, 1, 1, 1},
                             {{0, 1, 1, 1, 1}},
                             {{0, 1, 1, 1, 1}}};

  int n = 5;
  int m = 5;
  int res = bruteRowWithMax1s(arr, n, m);
  cout << res;
  int res2 = optimalRowWithMax1s(arr, n, m);
  cout << res2;
  return 0;
}