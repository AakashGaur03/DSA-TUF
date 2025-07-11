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

  for (int i = size - 1; i >= 1; i++) {
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
  selectionSort(arr, size);

  for (auto it : arr) {
    cout << it << " ";
  }
  cout << endl;
  int arr2[] = {23, 43, 23, 56, 3, 8};
  bubbleSort(arr2, size);
  for (auto it : arr2) {
    cout << it << " ";
  }

  return 0;
}