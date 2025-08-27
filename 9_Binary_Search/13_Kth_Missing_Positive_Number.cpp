#include <bits/stdc++.h>
using namespace std;
int optimalApproachKthMissingNumber(vector<int> arr, int size, int k) {
  // TC O(log base 2 N)
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int missing = arr[mid] - (mid + 1);
    if (missing < k) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  // low starts at not possible
  // high start at possible
  // Because of opposite polarity concept
  // High ends at maximum number that is not possible
  // low ends at minimum number that is possible
  //   so we can say ans = arr[high] + more
  // But arr[high] can be -1 in case where there is missing number at 1 st index
  // only so we can write more as k - (arr[high] - high - 1)
  // So ans = arr[high] + k - (arr[high] - high - 1)
  //   ans = arr[high] + k - arr[high] + high + 1
  // ans = k + high + 1;
  // or low = high + 1;
  // so ans = k + low;
  return high + 1 + k;
  return low + k;
}
int bruteForce(vector<int> arr, int size, int k) {
  // TC O(N)

  // Aproach is simple we check that before k how many numbers are present in
  // the array and add those in result and return that answer

  int res = k;
  for (int i = 0; i < size; i++) {
    if (arr[i] <= res) {
      res++;
    } else {
      break;
    }
  }

  //   arr = {2, 3, 4, 7, 11}, k = 5
  // res = 5
  // Loop over array:
  // arr[0] = 2 <= 5 → res = 6
  // arr[1] = 3 <= 6 → res = 7
  // arr[2] = 4 <= 7 → res = 8
  // arr[3] = 7 <= 8 → res = 9
  // arr[4] = 11 > 9 → return 9

  return res;
}

int main() {
  cout << "13 BS" << endl;
  // we have to return Kth missing number
  vector<int> arr = {2, 3, 4, 7, 11};
  int k = 5;
  // we have to return 5th Missing Number
  //                  1 2 3 4 5 6 7 8 9 10 11
  // Mising numbers   -       - -   - - -
  // Missing numbers are  1  5  6  8  9  10
  // 5th missing number is 9

  int res = bruteForce(arr, arr.size(), k);
  cout << res << endl;
  return 0;
}