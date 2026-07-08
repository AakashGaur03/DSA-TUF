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

// 0 Based Indexing
void heapify(vector<int> &arr, int n, int i) {
  // O(log n)
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

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

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
  // Step 1 Merge both arrays into 1

  vector<int> ans;
  for (auto it : a) {
    ans.push_back(it);
  }
  for (auto it : b) {
    ans.push_back(it);
  }
  int z = ans.size();
  // Step 2 Build Heap using merged array
  for (int i = z / 2 - 1; i >= 0; i--) { //(0 Based Indexing)
    heapify(ans, z, i);
  }

  return ans;
}

int main() {
  cout << "Merge Two Binary Max-Heap" << endl;
  cout << "Merge 2 Binary Max-Heap" << endl;

  vector<int> a = {10, 5, 6, 2}; // Max Heap
  vector<int> b = {12, 7, 9};    // Max Heap

  vector<int> ans = mergeHeaps(a, b, a.size(), b.size());

  cout << "Merged Max Heap: ";
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
