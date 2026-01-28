#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximumBrute(vector<int> arr, int k) {
  // TC O((N-K)*K)
  // SC O(N-K)
  int size = arr.size();
  vector<int> ans;
  for (int i = 0; i <= size - k; i++) { // TC (N-K)
    int maxi = arr[i];
    for (int j = i; j < i + k; j++) { // TC (K)
      maxi = max(maxi, arr[j]);
    }
    ans.push_back(maxi);
  }

  return ans;
}

int main() {
  cout << "20 L16 Sliding Window Maximum " << endl;
  // Here K is window and we have to see in windows of three Largest element and
  // Return vector as an answer
  // 1, 3, -1      max=   3
  // 3, -1, -3     max=   3
  // -1, -3, 5     max=   5
  // -3, 5, 3      max=   5
  // 5, 3, 2,      max=   5
  // 3, 2, 1       max=   3
  // 2, 1, 6       max=   6
  // ans is
  // {3, 3, 5, 5, 5, 3, 6}

  vector<int> arr = {1, 3, -1, -3, 5, 3, 2, 1, 6};
  int k = 3;
  vector<int> ans = slidingWindowMaximumBrute(arr, k);

  for (auto it : ans) {
    cout << it << " ";
  }

  return 0;
}
