#include <bits/stdc++.h>
using namespace std;
int bruteMaxSubArraySum(vector<int> arr, int size) {
  // TC O(N^2)
  // SC O(1)
  int maxVal = INT_MIN;
  for (int i = 0; i < size; i++) {
    int sum = 0;
    for (int j = i; j < size; j++) {
      sum += arr[j];
      maxVal = max(sum, maxVal);
    }
  }
  return maxVal;
}
// KADANE'S ALGORITHM
int optimalMaxSubArraySum(vector<int> arr, int size) {
  // TC O(N)
  // SC O(1)
  // Intution is like we will iterate once in whole array taking the sum and a
  // maxVal if sum goes below zero we drops it makes it zero and continues
  // further and also check if the result is bigger than maxVal in each case

  // If we also need Tack of Subarray
  int sum = 0;
  int maxVal = INT_MIN;
  int ansStart = -1;
  int ansEnd = -1;
  int start = 0;
  for (int i = 0; i < size; i++) {
    if (sum == 0) {
      start = i;
    }
    sum += arr[i];
    // maxVal = max(sum, maxVal);
    if (sum > maxVal) {
      maxVal = sum;

      ansStart = start;
      ansEnd = i;
    }
    if (sum < 0) {
      sum = 0;
    }
  }
  cout << ansStart << " " << ansEnd;
  return maxVal;
}
int main() {
  cout << "Array 7";
  vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
  // vector<int> arr = {-2, -3, -1, -4};

  //   vector<int> arr = {};
  //   int res = bruteMaxSubArraySum(arr, arr.size());
  int res = optimalMaxSubArraySum(arr, arr.size());
  cout << "Result: " << res;
  return 0;
}