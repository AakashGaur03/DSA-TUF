#include <bits/stdc++.h>
using namespace std;

vector<int> optimalLeaderInArray(vector<int> arr, int size) {
  // TC O(N)
  // SC O(N)
  vector<int> ans;
  int maxi = INT_MIN;
  for (int i = size - 1; i >= 0; i--) {
    if (arr[i] > maxi) {
      ans.push_back(arr[i]);
      maxi = arr[i];
    }
  }
  // If order matters
  //   reverse(ans.begin(), ans.end());
  // If Sorted Required
  //   sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  cout << "Array 11";
  //   Leaders In An Array
  // Everything on the right must be smaller than the element
  // 10 22 12 3 0 6
  // 22 is the leader
  // 12 is the leader
  // 6 is the leader

  //   brute
  // Two loops
  // Check for each element that on the right each element is smaller if thats
  // the case then push in answer and in end return answer

  // Brute Force - Find Leaders in Array
  //   TC O(N ^ 2)
  //   SC O(N)
  //   for (int i = 0; i < size; i++) {
  //     bool leader = true;
  //     for (int j = i + 1; j < size; j++) {
  //       if (arr[j] > arr[i]) {
  //         leader = false;
  //         break;
  //       }
  //     }
  //     if (leader)
  //       answer.push_back(arr[i]);
  //   }

  // Optimal
  vector<int> arr = {10, 22, 12, 3, 0, 6};
  vector<int> res = optimalLeaderInArray(arr, arr.size());
  for (auto it : res) {
    cout << it << " ";
  }

  return 0;
}
