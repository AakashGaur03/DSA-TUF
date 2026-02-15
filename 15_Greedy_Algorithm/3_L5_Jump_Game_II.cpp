#include <bits/stdc++.h>
using namespace std;

int recursiveApproach(int index, int jumps, vector<int> arr) {
  // TC O(N^N)
  // SC O(N)
  // 3_L5_Jump_Game_II_1
  int size = arr.size();
  if (index >= size - 1) {
    return jumps;
  }
  int mini = INT_MAX;
  for (int i = 1; i <= arr[index]; i++) {
    mini = min(mini, recursiveApproach(index + i, jumps + 1, arr));
  }
  return mini;
}

int jumpGame2(vector<int> arr) {
  // TC O(2N)
  // SC O(1)
  int size = arr.size();
  if (size <= 1)
    return 0;

  int jumps = 0;
  int left = 0;
  int right = 0;

  while (right < size - 1) {
    int fartheset = 0;

    // explore current jump range
    for (int i = left; i <= right; i++) {
      fartheset = max(i + arr[i], fartheset);
    }

    // move to next range
    left = right + 1;
    right = fartheset;
    jumps++;
  }
  return jumps;
}

int main() {
  cout << "3 L5 Jump Game II" << endl;
  // Arr tells us what maximum we can jump
  // We need to tell minimum number of jumps to reach to end
  // It is mentioned We will definetely Reach the end
  vector<int> arr = {2, 3, 1, 4, 1, 1, 1, 2};
  int res = jumpGame2(arr);
  cout << res << endl;

  return 0;
}
