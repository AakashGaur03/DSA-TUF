#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int size) {
  // n* (n+1)/2
  // TC approx O(N^2)
  for (int i = 0; i <= size - 2; i++) {
    // swap at 0 index and minimum value index [0 to n-1]
    //  swap at 1 index and minimum value index [1 to n-1]
    //  swap at 2 index and minimum value index [2 to n-1]
    // . . .
    // till n-2 index because last index is already sorted
    int mini = i;
    for (int j = i; j <= size - 1; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    // swap(arr[mini], arr[i])
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }
}

void bubbleSort(int arr[], int size) {

  // n* (n+1)/2
  // TC approx O(N^2) // Worst and Avg Complexity
  // what we can do is when there is sorted what we can do is when there is no
  // swap then break
  // So best case is O(N)

  // Adjacent Swapping
  // 13 46 24 52 20 9
  // First Interation (1)
  // 13 46 24 52 20 9
  // First Interation (2)
  // 13 24 46 52 20 9
  // First Interation (3)
  // 13 24 46 52 20 9
  // First Interation (4)
  // 13 24 46 20 52 9
  // First Interation (5)
  // 13 24 46 20 9 52

  // So after first Iteration 52 the most number goes to last

  for (int i = size - 1; i >= 1; i--) {
    int didSwap = 0;
    for (int j = 0; j <= i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j + 1], arr[j]);
        didSwap = 1;
      }
    }
    if (didSwap == 0) {
      break;
    }
  }
}

void insertionSort(int arr[], int n) {
  // n* (n+1)/2
  // Worst and Avg o(N^2)
  // Best Case O(N)
  // Because no Swaps are happening
  // Takes an element and places it at correct order
  for (int i = 0; i <= n - 1; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      swap(arr[j - 1], arr[j]);
      j--;
    }
  }
}

void mergeThem(vector<int> &arr, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  vector<int> temp;
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
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
}

void mergeSort(vector<int> &arr, int low, int high) {
  // Time Complexity
  // Divide O(log N)
  // Merge O(N)
  // So O(n log n)
  // SC : O(N) due to Temporary Array(Vector)
  // Divide and Merge
  if (low == high)
    return;
  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);

  mergeThem(arr, low, mid, high);
}

int getPartIdx(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;
  while (i < j) {
    while (arr[i] <= pivot && i <= high - 1) {
      // This gives first index that is greater than pivot
      i++;
    }
    while (arr[j] > pivot && j >= low + 1) {
      // This gives first index that is smaller than pivot
      j--;
    }
    if (i < j) {
      swap(arr[i], arr[j]);
    }
    // We swap them we do till all Smaller on the left and larger on the right
  }
  // TO position the first that is pivot at the right place after this Pivot
  // gets to the right position in the array
  swap(arr[low], arr[j]);
  return j;
}

void quickSort(vector<int> &arr, int low, int high) {
  // Divide and Conquer Algorithm
  if (low >= high)
    return;

  int partitionIndex = getPartIdx(arr, low, high);
  quickSort(arr, low, partitionIndex - 1);
  quickSort(arr, partitionIndex + 1, high);

  // TC O(N Log N)
  // SC O(1)
  // Pick a Pivot
  // Place it in correct place in the sorted array
  // How to Place
  // Smaller on the left and larger on the right
}
int main() {
  cout << "Sorting" << endl;
  // Selction Sort
  // We select mininum and we place it at first place swaps with the index
  // Ex 13 46 24 52 20 9
  // So after Step 1
  // 9 46 24 52 20 13
  // So after Step 2 13 comes and stays at same index
  // 9 13 24 52 20 46
  // So after Step 3 20 is minimum comes after 13 swaps
  // 9 13 20 52 24 46

  // 9 13 20 52 24 46
  // Now 24 and 52 swaps
  // 9 13 20 24 52 46
  // . Now 46 and 52
  // 9 13 20 24 46 52
  // .
  // .
  // 9 13 20 24 46 52

  // Get the minimum and swap it at correct index

  int arr[] = {23, 43, 23, 56, 3, 8};
  int size = 6;
  // selectionSort(arr, size);

  // cout << endl << "Selection" << endl;
  // for (auto it : arr) {
  //   cout << it << " ";
  // }
  // cout << endl;
  // cout << "Bubble" << endl;

  // int arr2[] = {23, 43, 23, 56, 3, 8};
  // bubbleSort(arr2, size);
  // for (auto it2 : arr2) {
  //   cout << it2 << " ";
  // }
  // cout << endl << "Insertion";
  // int arr3[] = {23, 43, 23, 56, 3, 8};
  // insertionSort(arr3, size);
  // for (auto it3 : arr3) {
  //   cout << it3 << " ";
  // }
  vector<int> arr4 = {23, 43, 23, 56, 3, 8};
  mergeSort(arr4, 0, size - 1);

  cout << "Sorted Array: ";
  for (auto it : arr4) {
    cout << it << " ";
  }
  cout << endl;
  vector<int> arr5 = {23, 43, 23, 56, 3, 8};
  quickSort(arr5, 0, arr5.size() - 1);

  cout << "Quick Sort Sorted Array: ";
  for (auto it : arr5) {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}