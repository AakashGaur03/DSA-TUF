// Given 'N' number of intervals, where each interval contains two integers
// denoting the boundaries of the interval. The task is to merge all the
// overlapping intervals and return the list of merged intervals sorted in
// ascending order.

// Two intervals will be considered to be overlapping if the starting integer of
// one interval is less than or equal to the finishing integer of another
// interval, and greater than or equal to the starting integer of that interval.

// Example:
// for the given 5 intervals - [1,4], [3,5], [6,8], [10,12], [8,9].
// Since intervals [1,4] and [3,5] overlap with each other, we will merge them
// into a single interval as [1,5].

// Similarly [6,8] and [8,9] overlaps, we merge them into [6,9].

// Interval [10,12] does not overlap with any interval.

// Final List after merging overlapping intervals: [1,5], [6,9], [10,12]

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bruteMergeOverlapInt(vector<vector<int>> &arr, int size) {
  // TC O(n log n) for sorting + O(2N) for two loops
  // SC O(N)
  sort(arr.begin(), arr.end()); // Sort by starting point
  vector<vector<int>> ans;

  // Step 2: Iterate through all intervals
  for (int i = 0; i < size; i++) {
    int start = arr[i][0]; // Start of current interval
    int end = arr[i][1];   // End of current interval

    // Skip the interval if it is already covered by the last interval in ans
    if (!ans.empty() && end <= ans.back()[1]) {
      continue;
    }

    // Step 3: Try to merge with overlapping intervals
    for (int j = i + 1; j < size; j++) {
      // If next interval overlaps with the current one
      if (arr[j][0] <= end) {
        end = max(end, arr[j][1]); // Extend the current interval
      } else {
        break; // No more overlap; exit inner loop
      }
    }

    // Step 4: Add the merged interval to the result
    ans.push_back({start, end});
  }
  return ans;
}
vector<vector<int>> optimalMergeOverlapInt(vector<vector<int>> &arr, int size) {
  // TC O(n log n) for sorting + O(N)
  // SC O(N)

  sort(arr.begin(), arr.end()); // Sort by starting point
  vector<vector<int>> ans;
  for (int i = 0; i < size; i++) {
    if (ans.empty() || arr[i][0] > ans.back()[1]) {
      ans.push_back(arr[i]);
    } else {
      ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
  }

  return ans;
}

int main() {
  cout << "Array 6" << endl;
  cout << "Merge Overlapping Intervals" << endl;
  // vector<vector<int>> arr = {{1, 3}, {2, 4}, {3, 5}, {6, 7}, {8, 10}, {9,
  // 12}}; vector<vector<int>> merged = bruteMergeOverlapInt(arr, arr.size());
  // cout << "Merged Intervals: ";
  // for (auto interval : merged) {
  //   cout << "[" << interval[0] << "," << interval[1] << "] ";
  // }
  // cout << endl;

  vector<vector<int>> arr = {{1, 3}, {2, 4}, {3, 5}, {6, 7}, {8, 10}, {9, 12}};
  vector<vector<int>> merged = optimalMergeOverlapInt(arr, arr.size());
  cout << "Merged Intervals: ";
  for (auto interval : merged) {
    cout << "[" << interval[0] << "," << interval[1] << "] ";
  }
  cout << endl;
  return 0;
}