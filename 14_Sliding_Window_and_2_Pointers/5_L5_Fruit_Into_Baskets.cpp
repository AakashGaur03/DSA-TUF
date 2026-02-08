

#include <bits/stdc++.h>
using namespace std;

int bruteApproach(vector<int> arr) {
  // TC O(N^2)
  // SC O(3)
  // We generate all subarrays
  // we see at most 2 unique elements with maxLen
  int size = arr.size();
  int maxLen = 0;
  for (int i = 0; i < size; i++) { // O(N)
    set<int> st;
    for (int j = i; j < size; j++) { // O(N)
      st.insert(arr[j]);             // O(log N) = log(3) = 1
      if (st.size() > 2) {
        break;
      }
      maxLen = max(maxLen, j - i + 1);
    }
  }
  return maxLen;
}

int almostOptimalApproach(vector<int> arr) {
  // TC O(2N)
  // SC O(Number of Bucket + 1)
  int size = arr.size();
  int left = 0;
  int right = 0;
  int maxLen = 0;
  map<int, int> mpp;

  while (right < size) { // O(N)
    mpp[arr[right]]++;

    if (mpp.size() > 2) {
      while (mpp.size() > 2) { // O(N)
        mpp[arr[left]]--;
        if (mpp[arr[left]] == 0) {
          mpp.erase(arr[left]);
        }
        left++;
      }
    }
    if (mpp.size() <= 2) {
      maxLen = max(maxLen, right - left + 1);
    }
    right++;
  }
  return maxLen;
}

int optimalApproach(vector<int> arr) {
  // TC O(N)
  // SC O(Number of Bucket + 1)

  int size = arr.size();
  int left = 0;
  int right = 0;
  int maxLen = 0;
  map<int, int> mpp;

  while (right < size) { // O(N)
    mpp[arr[right]]++;

    if (mpp.size() > 2) {
      mpp[arr[left]]--;
      if (mpp[arr[left]] == 0) {
        mpp.erase(arr[left]);
      }
      left++;
    }
    if (mpp.size() <= 2) {
      maxLen = max(maxLen, right - left + 1);
    }
    right++;
  }
  return maxLen;
}

int main() {
  cout << "5 L5 Fruit Into Baskets" << endl;
  // You are visiting a farm that has a single row of fruit trees arranged from
  // left to right. The trees are represented by an integer array fruits where
  // fruits[i] is the type of fruit the ith tree produces.

  // You want to collect as much fruit as possible. However, the owner has some
  // strict rules that you must follow:

  // You only have two baskets, and each basket can only hold a single type of
  // fruit. There is no limit on the amount of fruit each basket can hold.
  // Starting from any tree of your choice, you must pick exactly one fruit from
  // every tree (including the start tree) while moving to the right. The picked
  // fruits must fit in one of your baskets. Once you reach a tree with fruit
  // that cannot fit in your baskets, you must stop. Given the integer array
  // fruits, return the maximum number of fruits you can pick.

  // We can refactor it as to find
  // max length of subarray with at most 2 type of fruits/Numbers

  vector<int> arr = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  int res = bruteApproach(arr);
  cout << res << endl;
  int res2 = almostOptimalApproach(arr);
  cout << res2 << endl;
  int res3 = optimalApproach(arr);
  cout << res3 << endl;
  return 0;
}
