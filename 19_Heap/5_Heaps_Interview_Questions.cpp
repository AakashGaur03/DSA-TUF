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

class CustomNode {
  // Node stored inside the min heap.
  // We need:
  // data -> current value
  // i    -> which array this value belongs to
  // j    -> index of this value inside that array
public:
  int data;
  int i; // row (array number)
  int j; // column (index in that array)
  CustomNode(int data, int row, int col) {
    this->data = data;
    i = row;
    j = col;
  }
};

class compare {
  // Comparator for Min Heap.
  // The smallest data value should come to the top.
public:
  bool operator()(CustomNode *a, CustomNode *b) {
    // Makes this class callable as a function.
    // Used by priority_queue to compare two nodes.
    return a->data > b->data;
  }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k) {
  // TC O(N*K * log K)
  // SC O(K)
  priority_queue<CustomNode *, vector<CustomNode *>, compare> minHeap;

  // Step 1:
  // Push the first element of every array into the heap.
  // Initially heap contains K elements
  // O(K log K)
  for (int i = 0; i < k; i++) {
    if (!kArrays[i].empty()) {
      CustomNode *temp = new CustomNode(kArrays[i][0], i, 0);
      minHeap.push(temp);
    }
  }
  vector<int> ans;
  // Step 2:
  // Repeatedly take the smallest element.
  // O(N*K)
  while (minHeap.size() > 0) {
    CustomNode *temp = minHeap.top();
    ans.push_back(temp->data);
    minHeap.pop();
    int row = temp->i;
    int col = temp->j;
    // Push the next element from the same array
    // (if it exists).
    if (col + 1 < kArrays[row].size()) {
      CustomNode *next = new CustomNode(kArrays[row][col + 1], row, col + 1);
      minHeap.push(next);
    }
    delete temp; // Avoid memory leak
  }
  return ans;
}

class Node {
public:
  int data;
  Node *next;

public:
  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }

  // we can also add if we dont want to assign null
  // in code again and again
public:
  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

class compareLists {
public:
  bool operator()(Node *a, Node *b) { return a->data > b->data; }
};

Node *mergeKLists(vector<Node *> &listArray) {
  // TC (N* K log K)
  // SC (K)
  priority_queue<Node *, vector<Node *>, compareLists> minHeap;

  int k = listArray.size();

  if (k == 0) {
    return nullptr;
  }
  // Step 1
  for (int i = 0; i < k; i++) {
    if (listArray[i] != nullptr) {
      minHeap.push(listArray[i]);
    }
  }

  Node *head = nullptr;
  Node *tail = nullptr;

  while (minHeap.size() > 0) {
    Node *temp = minHeap.top();
    minHeap.pop();

    if (temp->next != nullptr) {
      minHeap.push(temp->next);
    }
    if (head == nullptr) {
      // LL is empty
      head = temp;
      tail = temp;

    } else {
      // Insert in LL
      tail->next = temp;
      tail = tail->next;
    }
  }
  if (tail != nullptr) {
    tail->next = nullptr;
  }
  return head;
}
int main() {

  cout << "----------------------------------------------" << endl;
  cout << "Q1 Kth Largest Sum Subaaray" << endl;
  // Kth Largest Sum Subaaray
  //   Problem statement
  // Given an array of integers, find the Kth largest sum subarray For
  // example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum
  // subarray would be [3, -4, 5], which has a sum of 4.

  // Please note that a subarray is the sequence of consecutive elements of
  // the array.

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

  cout << "Q2 Merge K Sorted Arrays" << endl;

  // Brute Force
  // Add everything in ans array and sort them (or create a min heap PQ)

  // Optimized Approach
  // Note we have given all the Arrays are sorted
  // So we will pick up first element of each Array and will take the minimum
  // and put in the ans we can take that using Min Heap

  vector<vector<int>> kArrays = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};

  int kArraysCount = kArrays.size();

  cout << "Input Arrays:" << endl;
  for (int i = 0; i < kArraysCount; i++) {
    cout << "Array " << i + 1 << ": ";
    for (int x : kArrays[i]) {
      cout << x << " ";
    }
    cout << endl;
  }

  vector<int> ans = mergeKSortedArrays(kArrays, kArraysCount);

  cout << "Merged Sorted Array: ";
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;

  cout << "----------------------------------------------" << endl;

  cout << "Q3 Merge K Sorted Linked List" << endl;

  // we dont ahve to use new List we need to update the Links
  // Brute
  // TC O(N*k (log N*K))
  // SC O(N*K)
  // Create new Vector put all elements in that
  // Sort that vector
  // Join all existing linked lists (Last of one to Start of other)
  // Replace existing data with vector sorted data

  // Optimal
  // Create MinHeap with first data as done in Merge K sorted Arrays
  // Create Linked List 1: 1 -> 4 -> 7
  Node *head1 = new Node(1);
  head1->next = new Node(4);
  head1->next->next = new Node(7);

  // Create Linked List 2: 2 -> 5 -> 8
  Node *head2 = new Node(2);
  head2->next = new Node(5);
  head2->next->next = new Node(8);

  // Create Linked List 3: 3 -> 6 -> 9
  Node *head3 = new Node(3);
  head3->next = new Node(6);
  head3->next->next = new Node(9);

  // Store all heads
  vector<Node *> listArray = {head1, head2, head3};

  Node *mergedHead = mergeKLists(listArray);

  cout << "Merged Linked List: ";
  Node *temp = mergedHead;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;

  cout << "----------------------------------------------" << endl;
  return 0;
}
