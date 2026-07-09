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

// Q2
long long costOfRopes(vector<long long> &arr, int n) {
  // TC O(N log N)
  // SC O(N)
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  for (auto it : arr) {
    pq.push(it);
  }

  long long cost = 0;
  while (pq.size() > 1) {
    long long a = pq.top();
    pq.pop();
    long long b = pq.top();
    pq.pop();
    cost += a + b;
    pq.push(a + b);
  }
  return cost;
}

void inorder(TreeNode *root, vector<int> &arr) {
  if (root == nullptr) {
    return;
  }

  inorder(root->left, arr);
  arr.push_back(root->val);
  inorder(root->right, arr);
}

void preorder(TreeNode *root, vector<int> &arr, int &index) {
  if (root == nullptr)
    return;

  root->val = arr[index++];
  preorder(root->left, arr, index);
  preorder(root->right, arr, index);
}

// Q3
TreeNode *convertBSTtoMinHeap(TreeNode *root) {
  // TC O(N)
  // SC O(N)
  vector<int> inorderArr;

  inorder(root, inorderArr);
  int index = 0;
  preorder(root, inorderArr, index);

  return root;
}

void printPreorder(TreeNode *root) {
  if (root == nullptr)
    return;

  cout << root->val << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

int main() {
  cout << "Merge Two Binary Max-Heap" << endl;
  cout << "Merge 2 Binary Max-Heap" << endl;

  vector<int> a = {10, 5, 6, 2}; // Max Heap
  vector<int> b = {12, 7, 9};    // Max Heap
                                 // Q1
  vector<int> ans = mergeHeaps(a, b, a.size(), b.size());

  cout << "Merged Max Heap: ";
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Q2 Minimum Cost of Ropes " << endl;
  // Q2 Minimum Cost of ropes

  // Given an array, arr[] of rope lengths, connect all ropes into a single rope
  // with the minimum total cost. The cost to connect two ropes is the sum of
  // their lengths.

  //   Input: arr[] = [4, 3, 2, 6]
  // Output: 29
  // Explanation: First connect 2 and 3 to get [4, 5, 6] with a cost of 5, then
  // connect 4 and 5 to get [9, 6] with a cost of 9, and finally connect 9 and 6
  // to get one rope with a cost of 15, giving a total minimum cost of 29. Any
  // other order, such as connecting 4 and 6 first, results in a higher total
  // cost of 38.

  // Here what we want to do is we take 2 minimum and add then and put them back
  // in arr repeat this steps till single element
  // Also note that we are adding those sums too in the last

  // We can use Min Heap it gives us smallest element in O(1)

  vector<long long> ropes = {4, 3, 2, 6};

  cout << "Minimum Cost of Ropes: " << costOfRopes(ropes, ropes.size()) << endl;
  cout << "----------------------------------------------" << endl;

  cout << "Q3 Convert BST to Min Heap" << endl;
  // Q3 Convert BST to Min Heap
  // Given a binary search tree which is also a complete binary tree. The
  // problem is to convert the given BST into a Min Heap with the condition that
  // all the values in the left subtree of a node should be less than all the
  // values in the right subtree of the node. This condition is applied to all
  // the nodes, in the resultant converted Min Heap.

  // Two things to Note
  // Follow Min Heap Property
  // Left Nodes value will be smaller then Right Node value

  //  NOW NOTE CBT inorder gives us sorted values
  // Now acc to condition
  // Follow Min Heap Property Root<Left<Right
  // and
  // Left Nodes value will be smaller then Right Node value
  // Left<Right

  // So we can deduce // Root<Left<Right this is preorder
  // so first we will find inorder and then populate in Preorder manner

  //   BST
  //         4
  //       /   \
//      2     6
  //     / \   / \
//    1  3  5  7

  // Inorder

  // 1 2 3 4 5 6 7
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);

  convertBSTtoMinHeap(root);

  cout << "Preorder of Min Heap: ";
  printPreorder(root);
  cout << endl;
  return 0;
}
