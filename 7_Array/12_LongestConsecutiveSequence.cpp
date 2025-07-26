#include <bits/stdc++.h>
using namespace std;

bool linear_search(vector<int> arr, int num) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == num) {
      return true;
    }
  }
  return false;
}

int bruteLongestConSeq(vector<int> arr, int size) {
  // TC O(N^2)
  // SC O(1)
  int longest = 1;
  for (int i = 0; i < size; i++) {
    int x = arr[i];
    int count = 1;
    while (linear_search(arr, x + 1) == true) {
      x = x + 1;
      count = count + 1;
      longest = max(longest, count);
    }
  }
  return longest;
}

int betterLongestConSeq(vector<int> arr, int size) {
  // TC (N LogN + N)
  // SC (1)
  sort(arr.begin(), arr.end());
  int longest = 1;
  int count = 0;
  int lastSmallest = INT_MIN;

  for (int i = 0; i < size; i++) {
    if (arr[i] - 1 == lastSmallest) {
      count += 1;
      lastSmallest = arr[i];
    } else if (arr[i] == lastSmallest) {
    } else {
      count = 1;
      lastSmallest = arr[i];
    }
    longest = max(longest, count);
  }

  return longest;
}

int optimalLongestConSeq(vector<int> arr, int size) {
  // unordred_set in most case O(1)   or once in a blue moon O(N)
  // TC O(1) + O(N + 2N)
  // SC O(N)
  int longest = 1;
  unordered_set<int> st;

  for (int i = 0; i < size; i++) {
    st.insert(arr[i]);
  }

  for (auto it : st) {
    if (st.find(it - 1) == st.end()) {
      int count = 1;
      int x = it;
      while (st.find(x + 1) != st.end()) {
        x = x + 1;
        count += 1;
      }
      longest = max(longest, count);
    }
  }

  return longest;
}
int main() {
  cout << "Array 12" << endl;
  ;
  // Longest Consecutive Sequence
  vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1, 1, 1};

  //   int res = bruteLongestConSeq(arr, arr.size());
  //   int res = betterLongestConSeq(arr, arr.size());
  int res = optimalLongestConSeq(arr, arr.size());
  cout << res;
  //   for (auto it : res) {
  //     cout << it << " ";
  //   }

  return 0;
}
