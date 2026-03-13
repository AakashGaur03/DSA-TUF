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

int widthOfBinaryTree(TreeNode *root) {
  // TC O(N)
  // SC O(N)
  if (!root) {
    return 0;
  }
  int ans = 0;
  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});

  while (!q.empty()) {
    int size = q.size();
    int mini = q.front().second; // to make id starting from zero
    int first, last;
    for (int i = 0; i < size; i++) {
      int cur_id = q.front().second - mini;
      TreeNode *node = q.front().first;
      q.pop();
      if (i == 0) {
        first = cur_id;
      }
      if (i == size - 1) {
        last = cur_id;
      }
      if (node->left) {
        q.push({node->left, (2 * cur_id + 1)});
      }
      if (node->right) {
        q.push({node->right, (2 * cur_id + 2)});
      }
    }
    ans = max(ans, last - first + 1);
  }

  return ans;
}

int main() {
  cout << "14 L28 Maximum Width of Binary Tree" << endl;
  // Maximum Width is No of nodes in a level between any two nodes
  // Refer 14_L28_Maximum_Width_of_Binary_Tree_1
  // We will be using Level Order Traversal WHY because we have to take
  // First node of the Level and the Last Node of the Level
  // We will try to index the tree and then we can simple subtract the Indexes
  // and get the answer
  // Refer 14_L28_Maximum_Width_of_Binary_Tree_2 &
  // 14_L28_Maximum_Width_of_Binary_Tree_3

  // If we are doing 0 based Indexing then we have left as (2*i +1) and right as
  // (2*i+2)
  // If we are doing 1 based Indexing then we have left as (2*i) and right
  // as (2*i)
  // Refer 14_L28_Maximum_Width_of_Binary_Tree_4

  // Here is an problem but if it is a skew Tree with 10^5 height
  // Overflow with occur 14_L28_Maximum_Width_of_Binary_Tree_5

  // Refer 14_L28_Maximum_Width_of_Binary_Tree_6
  // Idea of - mini
  // At every level we normalize indices so that the first node starts from 0.

  // Code:

  // int mini = q.front().second;
  // int cur_id = q.front().second - mini;

  // So instead of using large indices, we shift them.

  // Example

  // Suppose the queue stores:

  // (nodeA, 50)
  // (nodeB, 51)
  // (nodeC, 52)
  // (nodeD, 53)

  // Here:

  // mini = 50

  // Now we normalize:

  // cur_id = index - mini

  // Result:

  // (nodeA,0)
  // (nodeB,1)
  // (nodeC,2)
  // (nodeD,3)

  // So we avoid large numbers.
  /*
        Example Tree:
                1
             /    \
            2       3
           / \     / \
          4   5   8   9
             / \
            8   9


  */

  // Build tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(8);
  root->right->right = new TreeNode(9);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->left->right->right = new TreeNode(7);

  int res = widthOfBinaryTree(root);
  cout << res << endl;
  return 0;
}
