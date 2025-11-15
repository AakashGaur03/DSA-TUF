#include <bits/stdc++.h>
using namespace std;

void subsetSum_II(int index, vector<int> &arr, vector<int> &ds,
                  set<vector<int>> &res) {
  // TC O(2^N) * 2^N log 2^N
  // 2^N log 2^N for set
  // SC O(2^N)
  int n = arr.size();
  if (index == n) {
    res.insert(ds);
    return;
  }
  ds.push_back(arr[index]);
  subsetSum_II(index + 1, arr, ds, res);
  ds.pop_back();
  subsetSum_II(index + 1, arr, ds, res);
}

int main() {
  cout << "14_1 Subset Sum" << endl;
  vector<int> arr = {1, 2, 2};
  vector<int> ds;
  set<vector<int>> res;
  subsetSum_II(0, arr, ds, res);

  // Print result
  for (auto &subset : res) {
    cout << "{ ";
    for (auto x : subset)
      cout << x << " ";
    cout << "} ";
  }
  return 0;
}
