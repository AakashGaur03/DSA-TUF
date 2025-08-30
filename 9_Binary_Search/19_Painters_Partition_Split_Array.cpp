#include <bits/stdc++.h>
using namespace std;

int maximumArr(vector<int> arr, int size) {
  int maxi = INT_MIN;
  for (int i = 0; i < size; i++) {
    maxi = max(arr[i], maxi);
  }
  return maxi;
}
int sumOfAllinArr(vector<int> arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

bool painterPartionWorks(vector<int> arr, int size, int k, int slotAlloted) {

  int count = 1;
  int sumOfPaints = 0;

  for (int i = 0; i < size; i++) {
    if (sumOfPaints + arr[i] > slotAlloted) {
      count++;
      sumOfPaints = arr[i];
    } else {
      sumOfPaints = sumOfPaints + arr[i];
    }
  }

  if (count <= k) {
    return true;
  }
  return false;
}

int optimalPainterPartition(vector<int> arr, int size, int k) {
  int low = maximumArr(arr, size);
  int high = sumOfAllinArr(arr, size);

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (painterPartionWorks(arr, size, k, mid)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return low;
}
int main() {
  cout << "19 BS" << endl;
  // Painters Partions / Split Array Larget Sum
  vector<int> arr = {10, 20, 30, 40};
  int k = 2;
  int res = optimalPainterPartition(arr, arr.size(), k);
  cout << res << endl;
  return 0;
}

// Exactly Same as Allocation Book Problem Do for Practice
//  Painter’s Partition Problem

// You are given n boards of different lengths, and k painters. Each painter
// takes 1 unit of time to paint 1 unit of board. A painter can only paint
// contiguous boards (no splitting in between). The task is to allocate boards
// to painters such that the time to paint all boards is minimized.

// Example:
// Boards = [10, 20, 30, 40]
// Painters = 2

// If Painter 1 paints [10, 20, 30] = 60 units,
// Painter 2 paints [40] = 40 units,
// The total time = max(60, 40) = 60.

//  The minimum possible time is 60.

// Split Array Largest Sum (Leetcode 410)

// You are given an array arr of n non-negative integers, and an integer k.
// Split the array into k non-empty contiguous subarrays.
// The largest sum among these subarrays should be minimized.
// Return that minimized largest sum.

// Example:
// arr = [10, 20, 30, 40]
// k = 2

// Possible splits:

// [10, 20, 30] and [40] → largest sum = 60

// [10, 20] and [30, 40] → largest sum = 70

// The answer = 60.