#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
  if (a[1] == b[1])
    return a[0] < b[0]; // tie break by start
  return a[1] < b[1];   // earliest finish time
}

vector<int> meetingInARoom(vector<int> start, vector<int> end) {
  // TC O(2N + N log N)
  // SC O(3*N + N)
  // Approach will be to take meetings that are ending fast
  // We will sort both of them acc to end time and also keep there index
  // We will have (1,2,3) , (3,4,2), (0,5,1) , (5,7,5) (5,9,4) , (8,9,6 )
  // Refer 5_L7_N_Meeting_in_One_Room_3
  int size = start.size();
  if (size == 0)
    return {};

  vector<vector<int>> arr(size, vector<int>(3)); // SC O(3N)

  for (int i = 0; i < size; i++) { // O(N)
    arr[i][0] = start[i];
    arr[i][1] = end[i];
    arr[i][2] = i + 1; // 1 based Indexing
  }
  sort(arr.begin(), arr.end(), comp); // N log N
  int cnt = 1;
  int freeTime = arr[0][1]; // end time of first Value
  vector<int> ans;          // SC O(N)
  ans.push_back(arr[0][2]); // Store position of first value

  for (int i = 1; i < size; i++) { // O(N)
    if (arr[i][0] >= freeTime) {
      cnt++;
      freeTime = arr[i][1];
      ans.push_back(arr[i][2]);
    }
  }
  return ans;
}

int main() {
  cout << "4 L7 N Meeting in One Room" << endl;

  vector<int> start = {0, 3, 1, 5, 5, 8};
  vector<int> end = {5, 4, 2, 9, 7, 9};
  // We are given a one metting room with start and end time
  // One meeting at a time
  // Follow any order but perform max meetings
  // Refer 5_L7_N_Meeting_in_One_Room_1 and 5_L7_N_Meeting_in_One_Room_2
  vector<int> ans = meetingInARoom(start, end);
  for (auto it : ans) {
    cout << it << " ";
  }

  return 0;
}
