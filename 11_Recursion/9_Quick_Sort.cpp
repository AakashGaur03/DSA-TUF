#include <bits/stdc++.h>
using namespace std;
int placePivotAtCorrectplace(vector<int> &arr, int low, int high) {

  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j) {
    // high - 1 because standing on last index and does i++ so doesnt goes Out
    // of Boundary
    while (arr[i] <= pivot && i <= high - 1) {
      i++;
    }
    // low + 1 because standing on first index and does j-- so doesnt goes Out
    // of Boundary
    while (arr[j] > pivot && j >= low + 1) {
      j--;
    }
    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[low], arr[j]);
  return j;
}

int placePivotAtCorrectplaceDescending(vector<int> &arr, int low, int high) {

  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j) {
    // high - 1 because standing on last index and does i++ so doesnt goes Out
    // of Boundary
    while (arr[i] >= pivot && i <= high - 1) {
      i++;
    }
    // low + 1 because standing on first index and does j-- so doesnt goes Out
    // of Boundary
    while (arr[j] < pivot && j >= low + 1) {
      j--;
    }
    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[low], arr[j]);
  return j;
}

void quickSort(vector<int> &arr, int low, int high) {
  // TC O(n Log N)
  // SC O(1)
  // O(N) for recursive Stack space not anything for storing answer
  if (low < high) {

    int ptIndex = placePivotAtCorrectplaceDescending(arr, low, high);
    quickSort(arr, low, ptIndex - 1);
    quickSort(arr, ptIndex + 1, high);
  }
}

// Pick a Pivot
// Pivot can be any element of the array
// Lets take 1st Element

// Pick that pivot and place that element at correct position

// means smaller on the left and larger on the right
int main() {
  cout << "9 Quick Sort" << endl;
  // DIVIDE AND CONQUER ALGORITHM

  vector<int> arr = {4, 6, 2, 5, 9, 1, 3};
  int n = arr.size() - 1;
  quickSort(arr, 0, n);

  for (auto it : arr) {
    cout << it << " ";
  }

  return 0;
}
