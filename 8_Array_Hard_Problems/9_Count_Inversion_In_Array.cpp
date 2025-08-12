#include <bits/stdc++.h>
using namespace std;

int bruteCountInversions(vector<int> arr, int size) {
  // TC O(N^2)
  // SC O(1)

  int cnt = 0;

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] > arr[j])
        cnt++;
    }
  }

  return cnt;
}

// Global Variable

int mergeThem(vector<int> &arr, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  vector<int> temp;
  int count = 0;
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      // Addition HERE ONLY
      count += (mid - left + 1);
      temp.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
  return count;
}

int mergeSort(vector<int> &arr, int low, int high) {
  // Time Complexity
  // Divide O(log N)
  // Merge O(N)
  // So O(n log n)
  // SC : O(N) due to Temporary Array(Vector)
  // Divide and Merge
  int cnt = 0;
  if (low == high)
    return cnt;
  int mid = (low + high) / 2;
  cnt += mergeSort(arr, low, mid);
  cnt += mergeSort(arr, mid + 1, high);

  cnt += mergeThem(arr, low, mid, high);
  return cnt;
}

int optimalCountInversion(vector<int> arr, int size) {
  // We will use concept of Merge Sort
  // We will First implement Merge Sort
  // TC O(N log N)
  // SC O(N) temporary Array
  // Note that we are changing the array if dont want that then we can create a
  // copy of it and work on it

  // // Example of creating a copy of a vector
  // vector<int> original = {1, 2, 3, 4, 5};

  // // Method 1: Using copy constructor
  // vector<int> copy1(original);

  // // Method 2: Using assignment operator
  // vector<int> copy2 = original;

  // // Method 3: Using std::copy (less common for whole vectors)
  // vector<int> copy3(original.size());
  // std::copy(original.begin(), original.end(), copy3.begin());

  int res = mergeSort(arr, 0, size - 1);
  return res;
}

int main() {
  cout << "9 Count Inversion in An Array" << endl;
  vector<int> arr = {5, 3, 2, 4, 1};
  // Inversion is when Left > Right
  // Valid Inversions
  // (5,3) ,(5,2) ,(5,4) ,(5,1) , (3,2) ,
  // (3,1) , (2,1) (4,1) so answer is 8
  // InValid Inversions
  // (4,2) as 4 is on right of 2
  // int res = bruteCountInversions(arr, arr.size());
  int res = optimalCountInversion(arr, arr.size());
  cout << res;
  return 0;
}