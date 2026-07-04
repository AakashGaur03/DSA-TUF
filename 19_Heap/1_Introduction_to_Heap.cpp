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

int main() {
  cout << "1 Introduction to Heap" << endl;
  // Heap is a DS that is a Complete Binary Tree (CBT) and comes with a Heap
  // Order Priority

  // Complete Binary Tree (CBT)
  // Every level is completely filled except the last level
  // Nodes always added from the left or we can say lean towards left
  //        1
  //      /   \
  //     2     3
  //    / \   /
  //   4   5 6

  // Heap Order Priority
  // Two Property
  // Max Heap: Each Child will be smaller than its parent
  //         60
  //       /    \
  //      50     40
  //     /  \   
  //   30   20
  // Min Heap: Each Child will be larger than its parent
  //        1
  //      /   \
  //     2     3
  //    / \   /
  //   4   5 6

  // Insertion in Heap
  //         60
  //       /    \
  //      50     40
  //     /  \   
  //   30   20
  // We will implement Heap in form of array

  // Note we will start the insertion from 1st Index will leave the 0th index as
  // blank or will mark it as some other values
  //                    0   1   2   3   4   5
  // arr will be like { X, 60, 50, 40, 30, 20}

  // Note Node will be : ith index
  // Left Child : (2 * i) index
  // Right Child : (2 * i + 1)index
  // Parent : (i/2) index

  // Now lets try to Insert a value in heap
  // val = 55
  // 1st Step: Insert at End
  // 2nd Step: Take it to its correct position

  // 1st Step
  // Insertion in Heap
  //         60
  //       /     \
  //      50      40
  //     /  \    /
  //   30   20  55

  // So we will compare it with its parent we will swap those
  // Insertion in Heap
  //         60
  //       /     \
  //      50      55
  //     /  \    /
  //   30   20  40
  // Now it satisfies the Max Heap Property

  // Now lets say we got another value that is 70

  // Insertion in End
  //         60
  //       /     \
  //      50      55
  //     /  \    /   \
  //   30   20  40   70

  // So we will compare it with its parent we will swap those
  //         60
  //       /     \
  //      50      70
  //     /  \    /  \
  //   30   20  40   55
  // Doesnt satisfies the Max Heap Property

  // So we will compare it with its parent we will swap those
  //          70
  //       /     \
  //      50      60
  //     /  \    /  \
  //   30   20  40   55
  // Now it satisfies the Max Heap Property

  // Lets Code this out
  heap h;
  h.insert(60);
  h.insert(65);
  h.insert(63);
  h.insert(62);
  h.insert(64);
  h.print();
  // IT WILL GIVE RESULT
  //        65
  //      /    \
  //    64     63
  //   / \
  // 60  62

  // Deletion in Heap
  // Deletion means we are mentioned root node to be deleted
  // Steps
  // Step 1: Swap Root node with Last Node
  // Step 2: Remove Last node Now ( Removes the Original Root Node)
  // Step 3: Propogate Root node to its correct position
  // Compare Root with its Children If Children is greater then Swap
  h.deleteFromHeap();
  h.print();
  h.deleteFromHeap();
  h.print();

  return 0;
}
