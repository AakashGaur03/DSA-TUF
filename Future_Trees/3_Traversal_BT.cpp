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

void postorder(Node *root, vector<int> &arr) {
  if (root == nullptr) {
    return;
  }
  postorder(root->left, arr);
  postorder(root->right, arr);
  arr.push_back(root->data);
}

vector<int> postOrder(Node *root) {
  vector<int> arr;

  postorder(root, arr);

  return arr;
}

void inorder(Node *root, vector<int> &arr) {
  if (root == nullptr) {
    return;
  }
  inorder(root->left, arr);
  arr.push_back(root->data);
  inorder(root->right, arr);
}

vector<int> inOrder(Node *root) {
  vector<int> arr;

  inorder(root, arr);

  return arr;
}

int main() {
  cout << "3 Traversal BT";

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

  vector<int> result2 = inOrder(root);
  cout << endl;
  cout << "inOrder Traversal: ";
  for (int val2 : result2) {
    cout << val2 << " ";
  }

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

  vector<int> result3 = postOrder(root);
  cout << endl;
  cout << "PostOrder Traversal: ";
  for (int val3 : result3) {
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

  // Level Order traversal

  //   EX
  //         1
  //      /     \
  //     2       3
  //    / \     / \
  //   4   5   6   7

  // 1 2 3 4 5 6 7

  // TC O(N)
  // SC O(N)
  //   vector<vector<int>> levelOrder(TreeNode * root) {
  //     vector<vector<int>> ans;
  //     if (root == null)
  //       return ans;
  //     queue<TreeNode *> q;
  //     q.push(root);
  //     while (!q.empty()) {
  //     int size = q.size()
  //       vector<int> level;
  //       for (int i = 0; i < size; i++) {
  //         TreeNode *node = q.front();
  //         q.pop();
  //         if (node->left != NULL) {
  //           q.push(node->left);
  //         }
  //         if (node->right != NULL) {
  //           q.push(node->right);
  //         }
  //         level.push_back(node->val);
  //       }
  //       ans.push_back(level);
  //     }
  //     return ans;
  //   }
  return 0;
}