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

// Check if it's possible to make at least m bouquets
// on or before 'currentVal' day
bool possibleToMakeBouquets(vector<int> arr, int size, int m, int k,
                            int currentVal) {
  int noOfBouquet = 0; // count of bouquets formed
  int cnt = 0;         // consecutive bloomed flowers

  for (int i = 0; i < size; i++) {
    if (arr[i] <= currentVal) {
      // flower bloomed, count it
      cnt++;
    } else {
      // flower not bloomed, form bouquets from collected flowers
      noOfBouquet += (cnt / k);
      cnt = 0;
    }
  }
  // check last segment of consecutive bloomed flowers
  noOfBouquet += (cnt / k);

  return noOfBouquet >= m;
}
int bruteMinDaysMBouquets(vector<int> arr, int size, int m, int k) {
  // TC O(min-max * n)
  if (m * k > size)
    return -1;
  int min = minimumArr(arr, size);
  int max = maximumArr(arr, size);
  for (int i = min; i <= max; i++) {
    if (possibleToMakeBouquets(arr, size, m, k, i)) {
      return i;
    }
  }

  return -1;
}
int optimalMinDaysMBouquets(vector<int> arr, int size, int m, int k) {
  // TC O((log (min - max + 1)) * n)
  if (m * k > size)
    return -1;

  int low = minimumArr(arr, size);
  int high = maximumArr(arr, size);

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (possibleToMakeBouquets(arr, size, m, k, mid)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  // Concept of opposite polarity
  return low;
  // We can also return low as we can see that low and high starts at
  // opposite polarity that is at low it is not possible at high it is possible
  // so when starting low and high with opposite polarity we can see that if
  // answer exist then either high or low will be our answer in the end.

  //   In binary search, if we start with low = 7 (impossible) and
  //  high = maxElem (always possible), then after the loop ends:

  // low will be the smallest feasible answer
  // high will be the largest infeasible answer
}

int main() {
  cout << "10 BS" << endl;
  vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
  int m = 2;
  int k = 3;
  //   m = number of bouquets you need, and k = flowers per bouquet.
  int res = bruteMinDaysMBouquets(arr, arr.size(), m, k);
  cout << res << endl;
  int res2 = optimalMinDaysMBouquets(arr, arr.size(), m, k);
  cout << res2 << endl;
  return 0;
}