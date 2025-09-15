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

// Correct Iterative Inorder Traversal: Left -> Root -> Right
vector<int> iterativeInOrder(Node *root) {
  // TC O(N) travelling each node
  // SC O(N) It is height of Tree at worst case N
  vector<int> inorder;
  stack<Node *> st;
  Node *node = root;

  while (true) {
    if (node != nullptr) {
      st.push(node);
      node = node->left;
    } else {
      if (st.empty())
        break;
      node = st.top();
      st.pop();
      inorder.push_back(node->data);
      node = node->right;
    }
  }

  return inorder;
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

  // [Initial]       Stack: [1]
  // Pop 1 → Output: [1], Stack becomes [3, 2] (right first, then left)

  // Pop 2 → Output: [1, 2], Stack becomes [3, 5, 4]

  // Pop 4 → Output: [1, 2, 4], Stack becomes [3, 5]

  // Pop 5 → Output: [1, 2, 4, 5], Stack becomes [3]

  // Pop 3 → Output: [1, 2, 4, 5, 3], Stack becomes []

  cout << "Iterative Inorder Traversal Example:\n";
  vector<int> inResult = iterativeInOrder(root);
  cout << "Inorder Traversal: ";
  for (int val : inResult)
    cout << val << " ";
  /*
  Example Tree:
         1
        / \
       2   3
      / \
     4   5

  Step by Step Stack Behavior for Inorder Traversal:

  [Initial]       Stack: [], Current Node: 1

  1. Push 1 → Stack: [1], Move to left → Current Node: 2
  2. Push 2 → Stack: [1, 2], Move to left → Current Node: 4
  3. Push 4 → Stack: [1, 2, 4], Move to left → Current Node: nullptr

  4. Pop 4 → Output: [4], Stack: [1, 2], Move to right → Current Node: nullptr
  5. Pop 2 → Output: [4, 2], Stack: [1], Move to right → Current Node: 5
  6. Push 5 → Stack: [1, 5], Move to left → Current Node: nullptr

  7. Pop 5 → Output: [4, 2, 5], Stack: [1], Move to right → Current Node:
  nullptr
  8. Pop 1 → Output: [4, 2, 5, 1], Stack: [], Move to right → Current Node: 3
  9. Push 3 → Stack: [3], Move to left → Current Node: nullptr

  10. Pop 3 → Output: [4, 2, 5, 1, 3], Stack: [], Current Node: nullptr

  Traversal Complete.
  */
  return 0;
}