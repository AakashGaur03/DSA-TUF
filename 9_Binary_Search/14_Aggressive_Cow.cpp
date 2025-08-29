#include <bits/stdc++.h>
using namespace std;

int minimumArr(vector<int> arr, int size) {
  int mini = INT_MAX;
  for (int i = 0; i < size; i++) {
    mini = min(arr[i], mini);
  }
  return mini;
}
int maximumArr(vector<int> arr, int size) {
  int maxi = INT_MIN;
  for (int i = 0; i < size; i++) {
    maxi = max(arr[i], maxi);
  }
  return maxi;
}

bool canCowBePlaced(vector<int> arr, int size, int cows, int gapToCheck) {

  int cowPlaced = 1;
  int lastPos =
      arr[0]; // First cow placed this will keep track of last cow placed
  for (int i = 1; i < size; i++) {
    if (arr[i] - lastPos >= gapToCheck) {
      cowPlaced += 1;
      lastPos = arr[i];
    }
    if (cowPlaced >= cows) {
      return true;
    }
  }
  return false;
}

int bruteAggressiveCow(vector<int> arr, int size, int cows) {
  // TC O(n log n) + O(n * (max - min))
  // O(n log n) for sorting

  sort(arr.begin(), arr.end());
  if (cows > size)
    return -1;
  int res = 1;
  int maxGap = arr[size - 1] - arr[0];
  for (int i = 1; i <= maxGap; i++) {
    if (canCowBePlaced(arr, size, cows, i)) {
      //   return i; // we do this of we want minimum cow to be place
      // But we want maximum
      res = i;
    } else {
      break;
    }
  }

  return res;
}

int optimalBSAggressiveCow(vector<int> arr, int size, int cows) {
  // TC O(n log n) + O(n * log(max - min))
  // O(n log n) for sorting
  sort(arr.begin(), arr.end());
  if (cows > size)
    return -1;
  int res = 1;
  int low = 1;
  //   int high = maximumArr(arr, size) - minimumArr(arr, size);
  // or simply as sorted
  int high = arr[size - 1] - arr[0];

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (canCowBePlaced(arr, size, cows, mid)) {
      res = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  //   return res;
  // Low is always possible
  // High is not possible
  // So acc to opposite polarity concept
  return high;
}

int main() {
  cout << "BS 14" << endl;
  // Now pattern starts of finding like Minimum of Maximum or
  // Maximum of minimum

  // You are given an array of N stall positions (integers, not necessarily
  // sorted).

  // You have C cows that you want to place in these stalls.

  // The rule is: place cows in such a way that the minimum distance between any
  // two cows is as large as possible.

  vector<int> arr = {0, 3, 4, 7, 10};
  int cows = 4;
  int res = bruteAggressiveCow(arr, arr.size(), cows);
  cout << res << endl;
  int res2 = optimalBSAggressiveCow(arr, arr.size(), cows);
  cout << res2 << endl;
  return 0;
}