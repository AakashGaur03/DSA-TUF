#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> brute3Sum(vector<int> arr, int size) {
  // TC O(N^3) (three loops) * O(log unique triplets) (set)
  // SC O(2* number of triplets)

  set<vector<int>> st;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      for (int k = j + 1; k < size; k++) {
        if (arr[i] + arr[j] + arr[k] == 0) {
          vector<int> temp = {arr[i], arr[j], arr[k]};

          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
      }
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

vector<vector<int>> better3Sum(vector<int> arr, int size) {
  // We use two loops with hashing to avoid third loop

  // TC: O(n^2 * logM), where M is the number of unique triplets
  // SC: O(n) for hashSet + O(M) for storing triplets in the set

  set<vector<int>> st;
  for (int i = 0; i < size; i++) {
    set<int> hashSet;
    for (int j = i + 1; j < size; j++) {
      // We are looking for a third number such that:
      // arr[i] + arr[j] + third = 0  → third = -(arr[i] + arr[j])
      int third = -(arr[i] + arr[j]);
      // If third number is already seen, we found a valid triplet
      if (hashSet.find(third) != hashSet.end()) {
        vector<int> temp = {arr[i], arr[j], third};
        sort(temp.begin(), temp.end()); // Sort to ensure uniqueness in set
        st.insert(temp);                // Insert into set to avoid duplicates
      }

      // Add current number to hashSet for future lookups
      hashSet.insert(arr[j]);
    }
  }

  vector<vector<int>> ans(st.begin(), st.end()); // To put whole list in answer
  return ans;
}

vector<vector<int>> optimal3Sum(vector<int> arr, int size) {

  // TC O(nlogn) (sort) O(N) for loop ~O(N) for while loop
  // TC O(nlogn + N^2)
  // SC O(M) (for returing answer)

  // Sort the Array

  // Two Pointer Approach

  // we will keep i at start j at start+1 and k at last
  //  we will sum them up if i+j+k gives less tehn zero we will do j++ is
  //  greater than zero then k-- when j and k crosses or are equal then i++ and
  //  repeat
  // Also note to take every element that is taken at an iteration dont repeat
  // as we dont want to store duplicates Exampo [-2 -2 -2 -1 -1 -1 0 0 0 2 2 2]
  // So when -2 0 2 are taken taken then we do j++ till j is not equal to zero
  // and same for k, k-- till k is not 2
  // Similarly for i too we will move i, i++ till next element is not -2

  vector<vector<int>> ans;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < size; i++) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      // first element and same element
      continue;
    }

    int j = i + 1;
    int k = size - 1;

    while (j < k) {
      int sum = arr[i] + arr[j] + arr[k];

      if (sum < 0) {
        j++;
      } else if (sum > 0) {
        k--;
      } else {
        // sum = 0
        vector<int> temp = {arr[i], arr[j], arr[k]};
        ans.push_back(temp);
        j++;
        k--;

        while (j < k && arr[j] == arr[j - 1])
          j++;
        while (j < k && arr[k] == arr[k + 1])
          k--;
      }
    }
  }

  return ans;
}
int main() {
  cout << "3 Sum";
  vector<int> arr = {-1, 0, 1, 2, -1, -4};
  // Find all the triplet that sums add up to Zero
  // Each element should be taken once
  //   [-1,2,-1]
  //   [-1,0,1]
  //   [,0,1,-1]
  // Dont return duplicate triplets
  // We cant so like [-1,2,-1] and [2,-1,-1]

  // Brute
  // with three interations
  // vector<vector<int>> ans = brute3Sum(arr, arr.size());

  // for (auto row : ans) {
  //   for (auto it : row) {
  //     cout << it << " ";
  //   }
  //   cout << endl;
  // }
  vector<vector<int>> ans = optimal3Sum(arr, arr.size());

  for (auto row : ans) {
    for (auto it : row) {
      cout << it << " ";
    }
    cout << endl;
  }

  return 0;
}