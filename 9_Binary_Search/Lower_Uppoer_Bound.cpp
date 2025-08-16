#include <bits/stdc++.h>
using namespace std;

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

  return ans;
}
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

int main() {

  cout << "2 Lower and Upper Bound" << endl;
  // Smallest Index such that arr[index] >= x
  //    Index 0 1 2  3  4
  //   arr = [3,5,8,15,19]   n = 5
  //   x = 8 so lb = 2
  //   x = 9 so lb = 3
  //   x = 16 so lb = 4
  //   x = 20 so lb = 5 (size of array)or last hypothetical value
  //    Index 0 1 2  3  4  5  6
  //   arr = [3,5,8,15,19,19,19]   n = 7
  //   x = 19 so lb = 4

  vector<int> arr = {3, 5, 8, 15, 19, 19, 19};
  int res = lowerBound(arr, arr.size(), 19);
  // OR
  //   int lb = lower_bound(arr.begin(), arr.end(), 19); // It gives a Iterator
  //   pointing to that target
  int lb = lower_bound(arr.begin(), arr.end(), 19) - arr.begin();
  cout << "ANS : " << res << endl;
  cout << "ANS : " << lb << endl;
  // In Array
  int arr2[] = {3, 5, 8, 15, 19, 19, 19};
  int n = sizeof(arr2) / sizeof(arr2[0]);
  int lb2 = lower_bound(arr2, arr2 + n, 19) - arr2;
  cout << "ANS : " << lb2 << endl;

  // Upper Bound
  // Smallest Index such that arr[index] > x
  // Index    0 1 2 3 4 5 6   7  8  9
  // arr[] = [2,3,6,7,8,8,11,11,11,12]
  // x = 6  ub = 4
  // x = 11  ub = 9
  // x = 12  ub = 10
  // x = 13  ub = 10
  // x = 0  ub = 0
  vector<int> arr3 = {2, 3, 6, 7, 8, 8, 11, 11, 11, 12};
  int resUpper = upperBound(arr3, arr3.size(), 0);
  cout << "Upper : " << resUpper << endl;

  int ub = upper_bound(arr3.begin(), arr3.end(), 11) - arr3.begin();
  cout << "Upper : " << ub << endl;

  // Search Insert Position Problem is Lower Bound
  // Insert Value at the same or greater Index

  // Floor and Ceil in Sorted Array
  // Floor is largest element in array that is <= target
  // Ceil is Smallest Number in array >= x

  // Ceil is Same as lower Bound

  // In Floor we will just update the conditions that is
  // PseudoCode
  //   0

  return 0;
}
