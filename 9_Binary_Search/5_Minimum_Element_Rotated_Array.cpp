#include <bits/stdc++.h>
using namespace std;

int optimalMinimumElemRotatedArray(vector<int> arr, int size) {
  // O(n log n)
  int res = INT_MAX;

  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    // If search space is already Sorted then ans will always be arr[low]
    if (arr[low] <= arr[high]) {
      res = min(res, arr[low]);
      break;
    }
    if (arr[low] <= arr[mid]) {
      res = min(res, arr[low]);
      low = mid + 1;
    }
    // Either Left is sorted
    else {
      // Either Right is sorted
      res = min(res, arr[mid]);
      high = mid - 1;
    }
  }

  return res;
}
int optimalMinimumElemRotatedArrayDuplicates(vector<int> arr, int size) {
  // O(n log n)
  int res = INT_MAX;

  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == arr[low] && arr[mid] == arr[high]) {
      low++;
      high--;
      continue;
    }
    // If search space is already sorted
    if (arr[low] < arr[high]) {
      res = min(res, arr[low]);
      break;
    }
    if (arr[low] <= arr[mid]) {
      res = min(res, arr[low]);
      low = mid + 1;
    }
    // Either Left is sorted
    else {
      // Either Right is sorted
      res = min(res, arr[mid]);
      high = mid - 1;
    }
  }

  return res;
}

int optimalArrayRotatedByK(vector<int> arr, int size) {
  // O(n log n)
  int res = INT_MAX;
  int index = -1;

  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    // If search space is already Sorted then ans will always be arr[low]
    if (arr[low] <= arr[high]) {
      if (arr[low] < res) {
        res = arr[low];
        index = low;
      }
      break;
    }
    if (arr[low] <= arr[mid]) {
      if (arr[low] < res) {
        res = arr[low];
        index = low;
      }
      low = mid + 1;
    }
    // Either Left is sorted
    else {
      // Either Right is sorted
      if (arr[mid] < res) {
        res = arr[mid];
        index = mid;
      }
      high = mid - 1;
    }
  }

  return index;
}

int optimalArrayRotatedByKWithDuplicates(vector<int> arr, int size) {
  // O(n log n)
  int res = INT_MAX;
  int index = -1;
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == arr[low] && arr[mid] == arr[high]) {
      low++;
      high--;
      continue;
    }
    // If search space is already sorted
    if (arr[low] < arr[high]) {
      if (arr[low] < res) {
        res = arr[low];
        index = low;
      }
      break;
    }
    if (arr[low] <= arr[mid]) {
      if (arr[low] < res) {
        res = arr[low];
        index = low;
      }
      low = mid + 1;
    }
    // Either Left is sorted
    else {
      // Either Right is sorted
      if (arr[mid] < res) {
        res = arr[mid];
        index = mid;
      }
      high = mid - 1;
    }
  }

  return index;
}

int main() {
  cout << "BS 5" << endl;
  // Return the value of the minimum
  // Brute Force Linear Search O(N)

  vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

  int res = optimalMinimumElemRotatedArray(arr, arr.size());
  cout << res << endl;
  int res2 = optimalMinimumElemRotatedArrayDuplicates(arr, arr.size());
  cout << res2 << endl;

  // How many times the Array is Rotated
  // Its just the index at which our minimum value is present
  int res3 = optimalArrayRotatedByK(arr, arr.size());
  cout << res3 << endl;
  int res4 = optimalArrayRotatedByKWithDuplicates(arr, arr.size());
  cout << res4 << endl;
  return 0;
}