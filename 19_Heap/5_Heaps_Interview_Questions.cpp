#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val; // The data stored in the node (here it's an integer value)
  TreeNode *left, *right; // Pointers to the left and right child nodes

  // Constructor: initializes a node with value 'x'
  // left and right child pointers are set to NULL (meaning no children
  // initially)
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Brute
int getKthLargestBrute(vector<int> &arr, int k) {
  // TC O(N*N log N)
  // SC O(N*N)

  int n = arr.size();
  vector<int> sumStore;

  for (int i = 0; i < n; i++) {
    int sumVal = 0;
    for (int j = i; j < n; j++) {
      sumVal += arr[j];
      sumStore.push_back(sumVal);
    }
  }

  sort(sumStore.begin(), sumStore.end());
  int len = sumStore.size();
  return sumStore[len - k];
}

// Similar Approach in
// kthLargest in 3_Heaps_Interview_Questions.cpp
int getKthLargestHeap(vector<int> &arr, int k) {
  // TC O(N*N log K)
  // SC O(K)

  int n = arr.size();
  priority_queue<int, vector<int>, greater<int>> mini;

  for (int i = 0; i < n; i++) {
    int sumVal = 0;
    for (int j = i; j < n; j++) {
      sumVal += arr[j];
      if (mini.size() < k) {
        mini.push(sumVal);
      } else {
        if (sumVal > mini.top()) {
          mini.pop();
          mini.push(sumVal);
        }
      }
    }
  }

  return mini.top();
}

int main() {

  cout << "----------------------------------------------" << endl;
  cout << "Q1 Kth Largest Sum Subaaray" << endl;
  // Kth Largest Sum Subaaray
  //   Problem statement
  // Given an array of integers, find the Kth largest sum subarray For example,
  // given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray
  // would be [3, -4, 5], which has a sum of 4.

  // Please note that a subarray is the sequence of consecutive elements of the
  // array.

  // Brute Force
  // Iterate Over Array get all subarrays sum TC O(N*N)
  // Sort that in increasing order TC O(L log L)
  // Kth Largest is from last of that array O(1)

  vector<int> arr = {1, -2, 3, -4, 5};
  int k = 2;

  cout << "Array: ";
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl;

  cout << "K = " << k << endl;

  cout << "Brute Force Answer : " << getKthLargestBrute(arr, k) << endl;

  cout << "Heap Answer        : " << getKthLargestHeap(arr, k) << endl;
  cout << "----------------------------------------------" << endl;

  return 0;
}
