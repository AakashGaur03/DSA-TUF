#include <bits/stdc++.h>
using namespace std;

void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans,
                  int freq[]) {
  if (ds.size() == nums.size()) {
    ans.push_back(ds);
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (!freq[i]) {
      ds.push_back(nums[i]);
      freq[i] = 1;
      recurPermute(ds, nums, ans, freq);
      // For recursion to go back up
      freq[i] = 0;
      ds.pop_back();
    }
  }
}

int main() {
  cout << "15 L12 Print all Permutations of a String Array" << endl;
  // Approach 1
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans;
  vector<int> ds;
  int freq[nums.size()];
  for (int i = 0; i < nums.size(); i++) {
    freq[i] = 0; // Marking every element in arr to 0
  }
  recurPermute(ds, nums, ans, freq);

  for (auto &vec : ans) {
    for (int x : vec)
      cout << x << " ";
    cout << endl;
  }
  return 0;
}

// TC O(n! * n)
// n! for number of permutations
// n for looping from 0 to n-1

// SC O(N + N)
// N for ds and N for map
// Auxilary Space O(N) for recursion call

// REVISITED