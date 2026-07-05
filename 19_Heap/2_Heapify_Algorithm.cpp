#include <bits/stdc++.h>
using namespace std;

class heap {
public:
  int arr[100];
  int size;

  heap() {
    arr[0] = -1;
    size = 0;
  }

  void insert(int val) {
    // TC O(Log N)
    size++;
    int index = size;
    arr[index] = val;

    while (index > 1) {
      int parent = index / 2;

      if (arr[parent] < arr[index]) {
        swap(arr[parent], arr[index]);
        index = parent;
      } else {
        return;
      }
    }
  }

  void print() {
    for (int i = 1; i <= size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  void deleteFromHeap() {
    // TC O(Log N)

    if (size == 0) {
      cout << "Nothing to delete" << endl;
      return;
    }
    // Step 1: Swap Root node with Last Node
    arr[1] = arr[size]; // This or Swap means the same
    // Step 2: Remove Last node Now ( Removes the Original Root Node)
    size--;

    // Step 3: Propogate Root node to its correct position
    int i = 1;
    while (i < size) {
      int leftIdx = 2 * i;
      int rightIdx = 2 * i + 1;
      if (leftIdx < size && arr[i] < arr[leftIdx]) {
        swap(arr[leftIdx], arr[i]);
        i = leftIdx;
      } else if (rightIdx < size && arr[i] < arr[rightIdx]) {
        swap(arr[rightIdx], arr[i]);
        i = rightIdx;
      } else {
        return;
      }
    }
  }
};

// Max Heap
void heapify(vector<int> &arr, int n, int i) {
  // O(log n)
  int largest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  if (left < n && arr[largest] < arr[left]) {
    largest = left;
  }
  if (right < n && arr[largest] < arr[right]) {
    largest = right;
  }

  if (largest != i) {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

// Min Heap
void heapifyMinHeap(vector<int> &arr, int n, int i) {
  // O(log n)
  int smallest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  if (left < n && arr[smallest] > arr[left]) {
    smallest = left;
  }
  if (right < n && arr[smallest] > arr[right]) {
    smallest = right;
  }

  if (smallest != i) {
    swap(arr[smallest], arr[i]);
    heapifyMinHeap(arr, n, smallest);
  }
}

int main() {
  cout << "2 Heapify Algorithm" << endl;

  // 1 based Indexing
  // Note Node will be : ith index
  // Left Child : (2 * i) index
  // Right Child : (2 * i + 1)index
  // Parent : (i/2) index

  // 0 based Indexing
  // Note Node will be : ith index
  // Left Child : (2 * i +1) index
  // Right Child : (2 * i + 2)index
  // Parent : (i - 1) / 2

  // In a CBT
  // Nodes from (n/2 + 1) t0 N All nodes are Leaf Node

  // Consider Above Example N = 5 so
  // (n/2+1) = 3
  // and n = 5
  // so node from 3 to 5 that is 3 4 5 are the leaf nodes from above example
  // As these are already leaf nodes they are already heap so we dont need to
  // process them
  vector<int> arr = {-1, 54, 53, 55, 52, 50};
  int n = arr.size();
  for (int i = n / 2; i > 0; i--) {
    heapify(arr, n, i);
  }
  cout << "Printing array: " << endl;
  for (int i = 1; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  vector<int> arr2 = {-1, 54, 53, 55, 52, 50};
  int n2 = arr2.size();
  for (int i = n2 / 2; i > 0; i--) {
    heapifyMinHeap(arr2, n2, i);
  }

  cout << "Printing array 2: " << endl;
  for (int i = 1; i < n2; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;

  return 0;
}
