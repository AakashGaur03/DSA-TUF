#include <bits/stdc++.h>
using namespace std;

int bruteForceLinearInteration(vector<int> arr, int size) {
  // TC O(N)
  if (size == 1)
    return arr[0];
  for (int i = 0; i < size; i++) {
    if (i == 0) {
      if (arr[i] != arr[i + 1]) {
        return arr[i];
      }
    } else if (i == size - 1) {
      if (arr[i] != arr[i - 1]) {
        return arr[i];
      }
    } else {
      if (arr[i] != arr[i + 1] && arr[i] != arr[i - 1]) {
        return arr[i];
      }
    }
  }

  return -1;
}
int OptimalBinarySearch(vector<int> arr, int size) {
  // TC: O(log N) | SC: O(1)
  // Array is sorted and every element appears twice except one

  if (size == 1)
    return arr[0]; // Single element case
  if (arr[0] != arr[1])
    return arr[0]; // Unique element is at the beginning
  if (arr[size - 1] != arr[size - 2])
    return arr[size - 1]; // Unique at end

  int low = 1;
  int high = size - 2;

  while (low <= high) {
    int mid = (low + high) / 2;

    // Check if arr[mid] is the unique element
    if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
      return arr[mid];
    }

    // Pattern Observation:
    // Before the single element:
    //    pairs start at even index (0,2,4,...)
    // After the single element:
    //    pairs start at odd index (1,3,5,...)

    if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
        (mid % 2 == 1 && arr[mid] == arr[mid - 1])) {
      // We are still on the left side → go right
      low = mid + 1;
    } else {
      // We are on the right side → go left
      high = mid - 1;
    }
  }

  return -1; // Should not reach here if input constraints are valid
}
int OptimalBinarySearchMyApproach(vector<int> arr, int size) {
  // TC: O(log N) | SC: O(1)
  // Array is sorted and every element appears twice except one

  // So yes, it works for correctness (you will get a valid index of the
  // searched element), but it loses efficiency and precision
  if (size == 1)
    return arr[0]; // Single element case
  if (arr[0] != arr[1])
    return arr[0]; // Unique element is at the beginning
  if (arr[size - 1] != arr[size - 2])
    return arr[size - 1]; // Unique at end

  int low = 1;
  int high = size - 2;

  while (low <= high) {
    int mid = (low + high) / 2;

    // Check if arr[mid] is the unique element
    if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
      return arr[mid];
    }

    // Find out if there are odd elements in Left or Right
    // whatever it is Single Element is present there
    if (arr[mid] == arr[mid + 1]) {
      if (((size - 1) - (mid + 1)) % 2 == 0) {
        // Even in right
        high = mid - 1;
      } else {
        low = mid + 2;
      }
    } else {
      // arr[mid] == arr[mid-1]
      if (((size - 1) - (mid)) % 2 == 0) {
        // Even in right
        high = mid - 2;
      } else {
        low = mid + 1;
      }
    }
  }

  return -1; // Should not reach here if input constraints are valid
}

int main() {
  // All number will apear twice and a single elemnt that appears once

  vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

  int res = bruteForceLinearInteration(arr, arr.size());
  cout << res << endl;
  int res2 = OptimalBinarySearch(arr, arr.size());
  cout << res2 << endl;
  int res3 = OptimalBinarySearchMyApproach(arr, arr.size());
  cout << res3 << endl;
  cout << "BS 6";
  return 0;
}