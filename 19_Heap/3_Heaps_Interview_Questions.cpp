#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int N, int k) {
  // TC O(n log k)
  // SC O(K)
  priority_queue<int> pq;

  // Step 1
  for (int i = 0; i < k; i++) {
    pq.push(arr[i]);
  }

  // Step 2
  for (int i = k; i < N; i++) {
    if (arr[i] < pq.top()) {
      pq.pop();
      pq.push(arr[i]);
    }
  }

  return pq.top();
}

int kthLargest(vector<int> &arr, int N, int k) {
  // TC O(n log k)
  // SC O(K)
  priority_queue<int, vector<int>, greater<int>> pq;

  // Step 1
  for (int i = 0; i < k; i++) {
    pq.push(arr[i]);
  }

  // Step 2
  for (int i = k; i < N; i++) {
    if (arr[i] > pq.top()) {
      pq.pop();
      pq.push(arr[i]);
    }
  }

  return pq.top();
}

int main() {
  cout << "3 Heaps Interview Questions" << endl;

  // QUESTION 1
  // Kth Smallest Element
  // Given an integer array arr[] and an integer k, find and return the kth
  // smallest element in the given array. Note: The kth smallest element is
  // determined based on the sorted order of the array.

  // Examples :

  // Input: arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
  // Output: 5
  // Explanation: 4th smallest element in the given array is 5.
  // Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
  // Output: 7
  // Explanation: 3rd smallest element in the given array is 7.

  // Approach 1
  // Sort the Array  O(n log n) SC O(1)
  // return arr[k-1]

  // Approach 2 TC O(n log k) SC O(K)
  // Create a max Heap for First k Elements
  // For rest elements if(element<heap.top()) then pop from heap and insert that
  // element
  // we can return the root node after whole iteration

  cout << "Q1 Kth Smallest/Largest Element" << endl;
  cout << endl;
  vector<int> arr1 = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
  int n1 = arr1.size();
  int k1 = 4;

  cout << "Array 1: ";
  for (int x : arr1)
    cout << x << " ";
  cout << endl;

  cout << k1 << "th Smallest Element: " << kthSmallest(arr1, n1, k1) << endl;

  cout << k1 << "th Largest Element: " << kthLargest(arr1, n1, k1) << endl;

  cout << "\n----------------------\n" << endl;
  // Similarly Kth Largest can be found using min heap

  vector<int> arr2 = {7, 10, 4, 3, 20, 15};
  int n2 = arr2.size();
  int k2 = 3;

  cout << "Array 2: ";
  for (int x : arr2)
    cout << x << " ";
  cout << endl;

  cout << k2 << "th Smallest Element: " << kthSmallest(arr2, n2, k2) << endl;

  cout << k2 << "th Largest Element: " << kthLargest(arr2, n2, k2) << endl;

  // Question 2
  // Is Binary Tree Heap
  cout << "Q2 Is Binary Tree Max Heap" << endl;
  // So we need to Check two things that if the Tree is
  //  CBT Complete Binary Tree
  //  Follows Max Heap Property

  return 0;
}
