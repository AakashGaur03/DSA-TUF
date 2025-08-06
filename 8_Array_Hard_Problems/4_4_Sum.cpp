#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> brute4Sum(vector<int> arr, int size) {
  // TC O(N^4)
  // SC O(M) number of quads (4 that equals target)
  set<vector<int>> st;

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      for (int k = j + 1; k < size; k++) {
        for (int l = k + 1; l < size; l++) {
          if (arr[i] + arr[j] + arr[k] + arr[l] == 0) {
            vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
            sort(temp.begin(), temp.end());
            st.insert(temp);
          }
        }
      }
    }
  }

  vector<vector<int>> ans(st.begin(), st.end());

  return ans;
}

vector<vector<int>> better4Sum(vector<int> arr, int size) {
  // Same like did in 3 Sum using Hash
  // TC O(N^3 logn)
  // SC O(N) internal hash set + O(m) Number of quads
  set<vector<int>> st;

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      set<int> hashSet;
      for (int k = j + 1; k < size; k++) {
        int fourth = -(arr[i] + arr[j] + arr[k]);
        if (hashSet.find(fourth) != hashSet.end()) {
          vector<int> temp = {arr[i], arr[j], arr[k], fourth};
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
        hashSet.insert(arr[k]);
      }
    }
  }

  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

vector<vector<int>> optimal4Sum(vector<int> arr, int size, int target) {
  // Same approach as 3 sum optimal
  // Sort The Array
  // We will fix two variables and then same logic as in 3 Sum

  // TC O(N^3)
  // SC O(M) number of quads (space used to return answer)

  // We will use two fixed pointers (i, j) and two moving pointers (k, l)
  // Sort the array to enable skipping duplicates and two-pointer logic

  vector<vector<int>> ans;

  sort(arr.begin(), arr.end());

  for (int i = 0; i < size; i++) {
    // Skip duplicate values for the first pointer
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    for (int j = i + 1; j < size; j++) {
      // Skip duplicate values for the second pointer
      if (j != i + 1 && arr[j] == arr[j - 1]) {
        continue;
      }
      int k = j + 1;
      int l = size - 1;
      while (k < l) {
        // Use long long to avoid integer overflow
        long long sum = arr[i];
        sum += arr[j];
        sum += arr[k];
        sum += arr[l];
        if (sum == target) {
          vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
          ans.push_back(temp);
          k++;
          l--;
          // Skip duplicate values for third pointer
          while (k < l && arr[k] == arr[k - 1]) {
            k++;
          }
          // Skip duplicate values for fourth pointer
          while (k < l && arr[l] == arr[l + 1]) {
            l--;
          }
        } else if (sum < target) {
          k++;
        } else {
          l--;
        }
      }
    }
  }

  return ans;
}

int main() {
  cout << "4 Sum";
  vector<int> arr = {1, 0, -1, 0, -2, 2};
  // Brute Force
  // vector<vector<int>> ans = brute4Sum(arr, arr.size());

  // for (auto row : ans) {
  //   for (auto it : row) {
  //     cout << it << " ";
  //   }
  //   cout << endl;
  // }
  // vector<vector<int>> ans = better4Sum(arr, arr.size());

  // for (auto row : ans) {
  //   for (auto it : row) {
  //     cout << it << " ";
  //   }
  //   cout << endl;
  // }

  return 0;
}