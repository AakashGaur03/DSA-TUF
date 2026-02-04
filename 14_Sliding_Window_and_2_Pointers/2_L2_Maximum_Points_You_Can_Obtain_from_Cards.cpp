

#include <bits/stdc++.h>
using namespace std;

int maximumPointsObtainfromCards(vector<int> arr, int k) {
  // TC O(2K)
  // SC O(1)
  int size = arr.size();
  int leftSum = 0;
  int rightSum = 0;
  int maxSum = 0;
  int rightPtr = size - 1;
  // Pick K at start
  for (int i = 0; i < k; i++) { // O(K)
    leftSum += arr[i];
  }
  maxSum = leftSum;
  for (int i = k - 1; i >= 0; i--) { // O(K)
    // Remove 1 from left Window
    leftSum -= arr[i];
    // Add 1 from right Window
    rightSum += arr[rightPtr];
    rightPtr--;
    maxSum = max(maxSum, leftSum + rightSum);
  }

  return maxSum;
}

int main() {
  cout << "2 L2 Maximum Points You Can Obtain from N Cards" << endl;
  // Quetstion says Maximum Points You Can Obtain from N Cards
  // either from the Front or Either from the back and also consecutive
  // Ex arr = {6,2,3,4,7,2,1,7,1} K = 4
  // So we can pick 6 2 3 4 from start
  // or 1 7 1 2 from back
  // or 6 2 4 1 (6 2 4) from front (1) from back
  // so for Brute Force We will say
  // We will pick All 4 from front
  // Then 3 from front 1 from back
  // Then 2 from front 2 from back
  // Then 1 from front 4 from back
  // and in last all 4 from back
  // Maximum Summation will be anwer

  vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
  int K = 4;
  int maxi = maximumPointsObtainfromCards(arr, K);
  cout << maxi << endl;
  return 0;
}
