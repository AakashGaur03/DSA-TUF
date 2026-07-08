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

// Question 2

int countNodes(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  int ans = 1 + countNodes(root->left) + countNodes(root->right);
  return ans;
}

bool isCBT(TreeNode *root, int index, int count) {
  if (root == nullptr) {
    return true;
  }

  if (index >= count) {
    return false;
  } else {
    // 0 Based Indexing
    bool left = isCBT(root->left, 2 * index + 1, count);
    bool right = isCBT(root->right, 2 * index + 2, count);

    return left && right;
  }
}

bool isMaxOrder(TreeNode *root) {

  // Leaf Node
  if (root->left == nullptr && root->right == nullptr) {
    return true;
  }
  // Only Left Node
  if (root->right == nullptr) {
    return (root->left->val < root->val);
  } else {
    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);
    return (left && right &&
            (root->val > root->left->val && root->val > root->right->val));
  }
}
bool isHeap(TreeNode *root) {
  // TC O(N) + O(N)+ O(N)
  // SC O(N)
  int index = 0;
  int totalCount = countNodes(root);
  if (isCBT(root, index, totalCount) && isMaxOrder(root)) {
    return true;
  }
  return false;
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
  // For rest elements if(element<heap.top()) then pop from heap and insert
  // that element we can return the root node after whole iteration

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

  // ==========================
  // Question 2
  // ==========================

  // Is Binary Tree Heap
  // So we need to Check two things that if the Tree is
  //  CBT Complete Binary Tree
  //  Follows Max Heap Property

  cout << "Q2 Is Binary Tree Max Heap\n" << endl;

  /*
          100
         /   \
       90     80
      / \    /
    70  60 50

    Complete Binary Tree
    Satisfies Max Heap Property
  */

  TreeNode *root = new TreeNode(100);
  root->left = new TreeNode(90);
  root->right = new TreeNode(80);
  root->left->left = new TreeNode(70);
  root->left->right = new TreeNode(60);
  root->right->left = new TreeNode(50);

  if (isHeap(root))
    cout << "Tree 1 is a Max Heap." << endl;
  else
    cout << "Tree 1 is NOT a Max Heap." << endl;

  cout << "\n--------------------------\n" << endl;

  /*
          100
         /   \
       90     120
      / \
    70  60

    Not a Max Heap
    (120 > 100)
  */

  TreeNode *root2 = new TreeNode(100);
  root2->left = new TreeNode(90);
  root2->right = new TreeNode(120);
  root2->left->left = new TreeNode(70);
  root2->left->right = new TreeNode(60);

  if (isHeap(root2))
    cout << "Tree 2 is a Max Heap." << endl;
  else
    cout << "Tree 2 is NOT a Max Heap." << endl;

  return 0;
}
