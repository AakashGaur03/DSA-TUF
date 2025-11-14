#include <bits/stdc++.h>
using namespace std;

void optimalSubsetSum(int index, int sum, vector<int> &arr, vector<int> &ds) {
  // TC O(2^N) + 2^N log 2^N
  // 2^N log 2^N for sorting
  // SC O(2^N)
  int n = arr.size();
  if (index == n) {
    ds.push_back(sum);
    return;
  }
  optimalSubsetSum(index + 1, sum + arr[index], arr, ds);
  optimalSubsetSum(index + 1, sum, arr, ds);
}

int main() {
  cout << "13 Subset Sum" << endl;
  vector<int> arr = {3, 1, 4};
  vector<int> ds;
  optimalSubsetSum(0, 0, arr, ds);
  sort(ds.begin(), ds.end());
  for (auto it : ds) {
    cout << it << " ";
  }

  return 0;
}
