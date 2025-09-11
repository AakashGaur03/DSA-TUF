#include <bits/stdc++.h>
using namespace std;
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