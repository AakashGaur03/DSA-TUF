#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int size, int target) {

  // TC O(log base 2 N)
  int ans = size; // Hypothetical Answer
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] > target) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}

int countSmallEqual(vector<vector<int>> &mat, int n, int m, int x) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += upperBound(mat[i], m, x);
  }
  return cnt;
}

int optimalMedianSortedMatrix(vector<vector<int>> &mat, int n, int m) {
  // TC (log2(10^9) * (n * log2 m))
  // log2(10^9) for BS
  // (n * log2 m)) for Count Smaller Equals
  int low = INT_MAX;
  int high = INT_MIN;

  for (int i = 0; i < n; i++) {
    low = min(low, mat[i][0]);
    high = max(high, mat[i][m - 1]);
  }

  int req = (n * m) / 2;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    int smallEqual = countSmallEqual(mat, n, m, mid);
    if (smallEqual <= req) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return low;
}

int main() {
  cout << "26 Mdian In A Row Wise Sorted Matrix" << endl;
  // 2D aaray is row wise sorted
  // Always has odd elements

  vector<vector<int>> arr = {
      {1, 5, 7, 9, 11}, {2, 3, 4, 5, 10}, {9, 10, 12, 14, 16}};
  // So 1 2 3 4 5 5  7 9 9 10 10 11 12 14 16
  // Median is 9

  // Brute Force Go through each element in 2D array placing it in 1D array
  // Sorting the 1D array and then returning middle one

  // Optimal Approach
  // The range is min of 1 col till max of last col
  // after we know are range we will apply binary search in it
  // We will find that how many number are smaller than the current number
  // The first number that is smallest number that is greter than the n*m/2 size
  // is our median

  // How we will find the smallEquals we will perfrom BS on each row
  // apply upper bound that gives us the first index after our element is
  // present
  int res = optimalMedianSortedMatrix(arr, arr.size(), arr[0].size());
  cout << res << endl;
  return 0;
}