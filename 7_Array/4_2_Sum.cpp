#include <bits/stdc++.h>
using namespace std;
// Two loops
pair<int, int> brute_two_sum(vector<int> arr, int size, int sum) {
  // TC O(N^2)
  // SC O(1)
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (arr[i] + arr[j] == sum) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}
// Hashing
pair<int, int> better_two_sum(vector<int> arr, int size, int sum) {
  // TC O(N * logN)
  // SC O(N)
  map<int, int> mpp;
  for (int i = 0; i < size; i++) {
    int a = arr[i];
    int more = sum - a;
    // mpp.find(more) : It returns an iterator
    // If the key does not exist → it returns mpp.end()
    if (mpp.find(more) != mpp.end()) {
      //   return "YES"
      return {mpp[more], i};
    } else {
      mpp[a] = i;
    }
  }
  //   return "NO"
  return {-1, -1};
}
// Two Pointer
// First Sort Then pointer at left and one pointer at right and using greedy
// approach we solve it
// Only Optimal if we are returing YES or NO not optimal for indexes for indexes
// better one is optimal
string optimal_two_sum(vector<int> arr, int size, int sum) {
  // TC : O(N) + O(N LogN)(sorting)
  // SC : O(1)
  // SC : O(N) distoring array
  sort(arr.begin(), arr.end());
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    if (arr[left] + arr[right] == sum) {
      return "YES";
    } else if (arr[left] + arr[right] > sum) {
      right--;
    } else {
      left++;
    }
  }
  return "NO";
}

int main() {
  cout << " Array 4" << endl;
  vector<int> arr = {2, 6, 5, 8, 11};
  //   pair<int, int> result = brute_two_sum(arr, arr.size(), 14);
  //   pair<int, int> result = better_two_sum(arr, arr.size(), 14);
  string result2 = optimal_two_sum(arr, arr.size(), 14);
  cout << result2;
  //   if (result.first != -1) {
  //     cout << "Pair found: " << result.first << ", " << result.second <<
  //     endl;
  //   } else {
  //     cout << "No valid pair found.\n";
  //   }
  return 0;
}