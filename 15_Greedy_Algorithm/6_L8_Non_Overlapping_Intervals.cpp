#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
  if (a[1] == b[1])
    return a[0] < b[0]; // tie break by start
  return a[1] < b[1];   // earliest finish time
}

int nonOverlappingIntervals(vector<vector<int>> &intervals) {
  // TC O(N + N log N)
  // Approach will be to take meetings that are ending fast
  // We will sort both of them acc to end time and also keep there index
  int intervalSize = intervals.size();
  if (intervalSize == 0)
    return 0;

  sort(intervals.begin(), intervals.end(), comp); // N log N
  int cnt = 1;
  int lastEndTime = intervals[0][1]; // end time of first Value

  for (int i = 1; i < intervalSize; i++) { // O(N)
    if (intervals[i][0] >= lastEndTime) {
      cnt++;
      lastEndTime = intervals[i][1];
    }
  }
  return intervalSize - cnt;
}

int main() {
  cout << "6 L8 Non Overlapping Intervals" << endl;
  // Given an array of intervals intervals where intervals[i] = [starti, endi],
  // return the minimum number of intervals you need to remove to make the rest
  // of the intervals non-overlapping.

  // Note that intervals which only touch at a point are non-overlapping. For
  // example, [1, 2] and [2, 3] are non-overlapping.

  vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

  // WE can use the same concept of 5_L7_N_Meeting_in_One_Room
  // Basically it gave us max meetings that can be done
  // So here numberOfInterval - maxMeetings is our ans
  // Refer to 6_L8_Non_Overlapping_Intervals_1

  int res = nonOverlappingIntervals(intervals);
  cout << res;

  return 0;
}

// REVISITED