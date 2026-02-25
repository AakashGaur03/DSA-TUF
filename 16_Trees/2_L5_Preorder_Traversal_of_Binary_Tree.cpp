#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform preorder Traversal
// of the tree and store values in 'arr'
void preorder(Node *root, vector<int> &arr) {
  if (root == nullptr) {
    return;
  }
  arr.push_back(root->data);
  preorder(root->left, arr);
  preorder(root->right, arr);
}

// Fuction to initiate preorder Traversal
// and return resulting vector

vector<int> preOrder(Node *root) {
  // TC O(N)
  // SC O(N)
  vector<int> arr;

  preorder(root, arr);

  return arr;
}

int main() {
  cout << "2 L5 Preorder Traversal of Binary Tree";

  // Pre Order Traversal (Root Left Right)
  // TC O(N)
  // SC O(Height of the tree) ar worst O(N)
  //   void preOrder(node) {
  //     if (node == null) {
  //       return;
  //     }
  //     print(node->data);
  //     preorder(node->left);
  //     preorder(node->right);
  //   }

  //   EX
  //         1
  //      /     \
  //     2       3
  //    / \     / \
  //   4   5   6   7
  //      /       / \
  //     8       9   10
  //   1 2 4 5 8 3 6 7 9 10

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  //   EX
  //         1
  //      /     \
  //     2       3
  //    / \ 
  //   4   5

  vector<int> result = preOrder(root);
  cout << "Preorder Traversal: ";
  for (int val : result) {
    cout << val << " ";
  }

  return 0;
}