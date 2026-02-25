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
void postorder(Node *root, vector<int> &arr) {
  if (root == nullptr) {
    return;
  }
  postorder(root->left, arr);
  postorder(root->right, arr);
  arr.push_back(root->data);
}

// Fuction to initiate preorder Traversal
// and return resulting vector
vector<int> postOrder(Node *root) {
  vector<int> arr;

  postorder(root, arr);

  return arr;
}

int main() {
  cout << "2 L7 Postorder Traversal of Binary Tree";

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  // Post Order Traversal (Left Right Root)
  // TC O(N)
  // SC O(Height of the tree) ar worst O(N)

  //   void postOrder(node) {
  //     if (node == null) {
  //       return;
  //     }
  //     postOrder(node->left);
  //     postOrder(node->right);
  //     print(node->data);
  //   }

  vector<int> result = postOrder(root);
  cout << endl;
  cout << "PostOrder Traversal: ";
  for (int val3 : result) {
    cout << val3 << " ";
  }
  //   EX
  //         1
  //      /     \
  //     2       3
  //    / \     / \
  //   4   5   6   7
  //      /       / \
  //     8       9   10
  // 4 8 5 2 6 9 10 7 3 1

  return 0;
}