#include <bits/stdc++.h>
using namespace std;
int maximumArr(vector<int> arr, int size) {
  int maxi = INT_MIN;
  for (int i = 0; i < size; i++) {
    maxi = max(arr[i], maxi);
  }
  return maxi;
}
int sumOfAllWeights(vector<int> arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum = sum + arr[i];
  }
  return sum;
}

bool daysRequired(vector<int> weights, int size, int days, int currentVal) {
  int shipItems = 0;
  int count = 1;
  for (int i = 0; i < size; i++) {
    if ((shipItems + weights[i]) <= currentVal) {
      shipItems += weights[i];
    } else {
      shipItems = weights[i];
      count = count + 1;
    }
  }
  if (count <= days) {
    return true;
  } else
    return false;
}

int optimalCapcityToShipPackDDays(vector<int> weights, int size, int days) {
  // TC O(log base 2 of (min - max) * N)
  // Minimum we require C capacity that is max number of the array if we have to
  // ship all packages Maximum Number that is required is that is sum of all
  // numbers if we even have to ship everything in 1 day we require sum of
  // weights Our us defined now

  int low = maximumArr(weights, size);
  int high = sumOfAllWeights(weights, size);
  // In brute force we traverse from min to max each element one by one till we
  // find the answer and then breaks out
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (daysRequired(weights, size, days, mid)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return low; // opposite polarity
}
int main() {
  cout << "12 BS" << endl;
  vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int days = 5;
  //   You’re given an array weights[] where each element represents the weight
  //   of a package.
  // You need to ship all the packages in order (you cannot rearrange them).
  // You have to use a ship with some fixed capacity C.
  // Each day, you load packages (in order) until you can’t fit the next
  // package. Then that day’s trip ends, and the next day continues with the
  // next package.
  // You must ship all packages within days days.
  // The task: Find the minimum ship capacity C that allows you to do this.
  int res = optimalCapcityToShipPackDDays(weights, weights.size(), days);
  cout << res << endl;
  return 0;
}