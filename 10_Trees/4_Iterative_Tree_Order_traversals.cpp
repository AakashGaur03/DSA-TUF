#include <bits/stdc++.h>
using namespace std;

// Definition of Tree Node
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Iterative Preorder Traversal: Root -> Left -> Right
vector<int> iterativePreOrder(Node *root) {
  vector<int> preorder;

  // Edge case: if tree is empty
  if (root == nullptr)
    return preorder;

  stack<Node *> st;
  st.push(root);

  // Iterate on stack till its empty
  while (!st.empty()) {
    root = st.top();
    st.pop();

    // Visit the current node
    preorder.push_back(root->data);

    // Push right child first, so that left is processed first
    if (root->right)
      st.push(root->right);
    if (root->left)
      st.push(root->left);
  }

  return preorder;
}

int main() {
  cout << "Iterative Preorder Traversal Example:\n";
  // TC O(N) travelling each node
  // SC O(N) It is height of Tree at worst case N
  // Example Tree:
  //       1
  //      / \
    //     2   3
  //    / \
    //   4   5

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  vector<int> result = iterativePreOrder(root);

  cout << "Preorder Traversal: ";
  for (int val : result)
    cout << val << " ";

  return 0;
}

// [Initial]       Stack: [1]
// Pop 1 → Output: [1], Stack becomes [3, 2] (right first, then left)

// Pop 2 → Output: [1, 2], Stack becomes [3, 5, 4]

// Pop 4 → Output: [1, 2, 4], Stack becomes [3, 5]

// Pop 5 → Output: [1, 2, 4, 5], Stack becomes [3]

// Pop 3 → Output: [1, 2, 4, 5, 3], Stack becomes []
