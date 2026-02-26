#include <bits/stdc++.h>
using namespace std;

// Definition of Tree Node
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

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
  cout << "3 L10 iterative Inorder Traversal in Binary Tree" << endl;

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

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