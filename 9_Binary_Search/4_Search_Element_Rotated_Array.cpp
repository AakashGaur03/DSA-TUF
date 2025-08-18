#include <bits/stdc++.h>
using namespace std;
int optimalSearchRoatedArray(vector<int> arr, int size, int target) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
      return mid;

    if (arr[low] <= arr[mid]) {
      // Either Left Half will be sorted
      if (arr[low] <= target && target <= arr[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    } else {
      // Or Right Half will be sorted
      if (arr[mid] <= target && target <= arr[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  return -1;
}

bool optimalSearchRoatedArray2(vector<int> arr, int size, int target) {
  // In average case O(log n)
  // In worst case O(n/2) // When almost every element is kind of duplicate
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == arr[low] && arr[mid] == arr[high]) {
      low = low + 1;
      high = high - 1;
      continue;
    }
    if (arr[mid] == target)
      return true;

    if (arr[low] <= arr[mid]) {
      // Either Left Half will be sorted
      if (arr[low] <= target && target <= arr[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    } else {
      // Or Right Half will be sorted
      if (arr[mid] <= target && target <= arr[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  return false;
}

int main() {
  cout << "BS 4" << endl;
  // Unique elements
  // Brute Force
  // Linear Search
  // O(N)
  vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};

  // Without Duplicates
  int res = optimalSearchRoatedArray(arr, arr.size(), 8);
  cout << res << endl;
  // With Duplicates
  // We have to just say true if exist or false if not
  // As returning element is not posisble in this version we have to use Linear
  // Search
  vector<int> arr2 = {7, 8, 9, 1, 1, 1, 2, 3, 4, 5, 6};
  vector<int> arr3 = {3, 1, 2, 3, 3, 3, 3, 3};
  bool res2 = optimalSearchRoatedArray2(arr2, arr2.size(), 4);
  bool res3 = optimalSearchRoatedArray2(arr2, arr2.size(), 12);
  cout << res2 << endl;
  cout << res3 << endl;
  return 0;
}