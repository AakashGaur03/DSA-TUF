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

vector<int> topView(TreeNode *root) {
  // TC O(N)
  // SC O(N)
  vector<int> ans;
  if (root == nullptr)
    return ans;
  // Map: line -> node value
  // 'line' represents horizontal distance from root
  map<int, int> mpp;

  // Queue for BFS: stores (node pointer, line)
  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});
  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    TreeNode *node = it.first;
    int line = it.second;

    // Step 1: Store first node of each line in map
    if (mpp.find(line) == mpp.end())
      mpp[line] = node->val;

    // Step 2: Add children to queue with line-1 and line+1
    if (node->left != nullptr) {
      q.push({node->left, line - 1});
    }
    if (node->right != nullptr) {
      q.push({node->right, line + 1});
    }
  }
  // Map stores in Sorted Order so we get from left to right
  for (auto it : mpp) {
    ans.push_back(it.second);
  }
  return ans;
}

int main() {
  cout << "15 Top View of Tree" << endl;
  // Refer to 15_Top_View_BT Image
  // Level Order Traversal
  // We follow kind of same approach as previous
  // when mones left -1 when right +1
  // Here for each we only take one value that is from 1st node

  /*
 Example Tree:

         1
        / \
       2   3
        \
         4
          \
           5
            \
             6

 Top view = [2, 1, 3, 6]
 */

  // Construct tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->left->right->right = new TreeNode(5);
  root->left->right->right->right = new TreeNode(6);

  // Call function
  vector<int> result = topView(root);

  // Dry Run (Queue + Map updates):
  /*
  Start: queue = [(1,0)]

  Pop (1,0) → mpp[0] = 1
  Push (2,-1), (3,1)

  Pop (2,-1) → mpp[-1] = 2
  Push (4,0)

  Pop (3,1) → mpp[1] = 3

  Pop (4,0) → mpp already has line 0, ignore
  Push (5,1)

  Pop (5,1) → mpp already has line 1, ignore
  Push (6,2)

  Pop (6,2) → mpp[2] = 6

  Final map:
  -1 → 2
   0 → 1
   1 → 3
   2 → 6

  Result = [2, 1, 3, 6]
  */

  cout << "Top View: ";
  for (int val : result)
    cout << val << " ";
  cout << endl;
  return 0;
}
