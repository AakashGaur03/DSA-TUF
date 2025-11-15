#include <bits/stdc++.h>
using namespace std;

void optimalSubsetSum_II(int index, vector<int> &arr, vector<int> &ds,
                         vector<vector<int>> &ans) {
  // TC O(2^N) * N
  // N  for putting into data structure
  // SC O(2^N) * O(k)
  // k is average length
  // Auxiliary space is O(N) that is depth of recursion
  ans.push_back(ds);
  for (int i = index; i < arr.size(); i++) {
    if (i != index && arr[i] == arr[i - 1])
      continue;
    ds.push_back(arr[i]);
    optimalSubsetSum_II(i + 1, arr, ds, ans);
    ds.pop_back();
  }
}

int main() {
  cout << "14_2 Subset Sum" << endl;
  vector<int> arr = {1, 2, 2};
  vector<int> ds;
  vector<vector<int>> res;
  sort(arr.begin(), arr.end());
  optimalSubsetSum_II(0, arr, ds, res);

  // Print result
  for (auto &subset : res) {
    cout << "{ ";
    for (auto x : subset)
      cout << x << " ";
    cout << "} ";
  }
  return 0;
}
