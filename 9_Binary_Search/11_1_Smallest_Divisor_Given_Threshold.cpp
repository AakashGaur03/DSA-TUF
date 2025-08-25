#include <bits/stdc++.h>
using namespace std;

int maximumArr(vector<int> arr, int size) {
  int maxi = INT_MIN;
  for (int i = 0; i < size; i++) {
    maxi = max(arr[i], maxi);
  }
  return maxi;
}

bool isMinimalDivisor(vector<int> &arr, int size, int threshold, int val) {

  int divisorAns = 0;
  for (int i = 0; i < size; i++) {
    divisorAns += ceil((double)arr[i] / double(val));
    // divisorAns += (arr[i] + val - 1) / val;  // integer ceil division
  }
  if (divisorAns <= threshold)
    return true;
  return false;
}
int optimalMinimumDivisor(vector<int> &arr, int size, int threshold) {

  // TC O(n * log(maxVal))

  if (threshold < size) {
    return -1;
  }
  int low = 1;
  int high = maximumArr(arr, size);

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (isMinimalDivisor(arr, size, threshold, mid)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return low;
}

int main() {
  cout << "11 BS" << endl;

  vector<int> arr = {1, 2, 5, 9};
  int threshold = 6;
  // Find a number that divides the all number in array after indiviual division
  // we sum all the ciel values of divided result and that should be less than
  // or equal to threshold
  // In brute false we go from 1 to maximum number in arr

  int res = optimalMinimumDivisor(arr, arr.size(), threshold);
  cout << res << endl;
  return 0;
}