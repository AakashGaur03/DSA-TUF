#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
  int val;         // The value stored in the node
  TreeNode *left;  // Pointer to the left child
  TreeNode *right; // Pointer to the right child

  // Constructor: initializes a node with a given value,
  // and sets left and right pointers to NULL
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform ZigZag (Spiral) Level Order Traversal
vector<vector<int>> zigZagLevelOrder(TreeNode *root) {
  // Time Complexity: O(N)  -> each node is visited once
  // Space Complexity: O(N) -> queue + result storage

  vector<vector<int>> result; // Final result container

  if (root == nullptr) { // Edge case: empty tree
    return result;
  }

  queue<TreeNode *> nodesQueue; // Queue for BFS traversal
  nodesQueue.push(root);        // Start with the root node
  bool leftToRight = true;      // Direction flag (start with left → right)

  // BFS traversal of tree
  while (!nodesQueue.empty()) {
    int size = nodesQueue.size(); // Number of nodes at the current level
    vector<int> row(size);        // Container for current level values

    // Process all nodes at the current level
    for (int i = 0; i < size; i++) {
      TreeNode *node = nodesQueue.front(); // Get the front node in the queue
      nodesQueue.pop();                    // Remove it from the queue

      // Determine index in row based on traversal direction
      // If leftToRight → normal order
      // If rightToLeft → reverse order
      int index = leftToRight ? i : size - 1 - i;

      row[index] = node->val; // Place value in correct position

      // Add child nodes to queue for next level
      if (node->left) {
        nodesQueue.push(node->left);
      }
      if (node->right) {
        nodesQueue.push(node->right);
      }
    }

    // After finishing this level, flip traversal direction
    leftToRight = !leftToRight;

    // Save the current row into final result
    result.push_back(row);
  }

  return result;
}

int main() {
  cout << "12 Zig Zag or Spiral Traversal" << endl;

  // Constructing a sample binary tree:
  //        1
  //      /   \
  //     2     3
  //    / \   / \
  //   4   5 6   7

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  vector<vector<int>> ans = zigZagLevelOrder(root);

  for (auto &level : ans) {
    for (int val : level) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}

// ZigZag (Spiral) Traversal Direction Pattern:
//
// Level 1 →   (left to right)
// Level 2 ←   (right to left)
// Level 3 →   (left to right)
// Level 4 ←   (right to left)
// Level 5 →   (left to right)
// Level 6 ←   (right to left)
// ... and so on alternating
//
// Example tree:
//
//            1
//         /     \
//        2       3
//       / \     / \
//      4   5   6   7
//
// ZigZag Output:
//
// Level 1 →   [1]
// Level 2 ←   [3, 2]
// Level 3 →   [4, 5, 6, 7]
//
// Final result = [[1], [3, 2], [4, 5, 6, 7]]

// DRY RUN EXPLANATION
//
// Initial:
// result = {}
// queue  = [1]
// leftToRight = true
//
// Level 1:
// size=1, row=[1], queue after = [2,3]
// result = [[1]]
//
// Level 2:
// size=2, order reversed, row=[3,2], queue after = [4,5,6,7]
// result = [[1],[3,2]]
//
// Level 3:
// size=4, normal order, row=[4,5,6,7], queue after = []
// result = [[1],[3,2],[4,5,6,7]]
//
// Queue empty → stop