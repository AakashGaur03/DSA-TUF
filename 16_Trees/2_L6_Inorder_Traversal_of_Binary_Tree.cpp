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
void inorder(Node *root, vector<int> &arr) {
  if (root == nullptr) {
    return;
  }
  inorder(root->left, arr);
  arr.push_back(root->data);
  inorder(root->right, arr);
}

// Fuction to initiate preorder Traversal
// and return resulting vector
vector<int> inOrder(Node *root) {
  vector<int> arr;

  inorder(root, arr);

  return arr;
}

int main() {
  cout << "2 L6 Inorder Traversal of Binary Tree";

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  // In Order Traversal (Left Root Right)
  // TC O(N)
  // SC O(Height of the tree) ar worst O(N)

  //   void inOrder(node) {
  //     if (node == null) {
  //       return;
  //     }
  //     inOrder(node->left);
  //     print(node->data);
  //     inOrder(node->right);
  //   }

  //   EX
  //         1
  //      /     \
  //     2       3
  //    / \     / \
  //   4   5   6   7
  //      /       / \
  //     8       9   10
  // 4 2 8 5 1 6 3 9 7 10

  vector<int> result = inOrder(root);
  cout << endl;
  cout << "inOrder Traversal: ";
  for (int val2 : result) {
    cout << val2 << " ";
  }
  return 0;
}