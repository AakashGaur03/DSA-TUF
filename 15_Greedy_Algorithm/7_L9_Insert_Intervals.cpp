#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insertIntervals(vector<vector<int>> &intervals,
                                    vector<int> &newInterval) {
  // TC O(N)
  // SC O(N)

  // 1) Completely left     -> keep as it is
  // 2) Overlapping region  -> merge
  // 3) Completely right    -> keep as it is

  vector<vector<int>> result;
  int size = intervals.size();
  int i = 0;
  // if ending point of that inteval is < the starting point of newInterval
  // Left half
  while (i < size && intervals[i][1] < newInterval[0]) {
    result.push_back(intervals[i]);
    i++;
  }

  // Starting point of that interval is <= ending point of newInterval
  // overlapping interval
  while (i < size && intervals[i][0] <= newInterval[1]) {
    newInterval[0] = min(newInterval[0], intervals[i][0]);
    newInterval[1] = max(newInterval[1], intervals[i][1]);
    i++;
  }
  result.push_back(newInterval);
  while (i < size) {
    result.push_back(intervals[i]);
    i++;
  }
  return result;
}

int main() {
  cout << "7 L9 Insert Intervals" << endl;
  // Given an array of intervals intervals where intervals[i] = [starti, endi],
  // intervals are non-overlapping and in sorted manner.

  // We will be given newInterval that we need to insert in the array and then
  // return resultant array

  vector<vector<int>> intervals = {{1, 3}, {6, 7}};
  vector<int> newInterval = {2, 5};
  // So here if we insert it like
  // {1, 3},{2, 5} ,{6, 7}

  // So there will be a overlap
  // so we will cover that range and update the interval to {1,5}
  // Our answer will be
  // {1, 5} ,{6, 7}
  // Refer to one more example
  // 7_L9_Insert_Intervals_1

  vector<vector<int>> res = insertIntervals(intervals, newInterval);
  for (auto &it : res) {
    cout << "[" << it[0] << "," << it[1] << "] ";
  }

  return 0;
}
