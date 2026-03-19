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

TreeNode *buildTree(vector<int> &preOrder, int preStart, int preEnd,
                    vector<int> &inOrder, int inStart, int inEnd,
                    map<int, int> inMap) {

  // Base case: if range becomes invalid, return NULL
  if (preStart > preEnd || inStart > inEnd) {
    return nullptr;
  }

  // Step 1: First element of preorder is always the root
  TreeNode *root = new TreeNode(preOrder[preStart]);

  // Step 2: Find root index in inorder using map
  int inRoot = inMap[root->val];

  // Step 3: Count how many nodes are in left subtree
  int numsLeft = inRoot - inStart;

  /*
    Step 4: Recursively build left subtree
    - Next element in preorder is start of left subtree
    - Inorder left part defines left subtree
  */
  root->left = buildTree(preOrder, preStart + 1, preStart + numsLeft, inOrder,
                         inStart, inRoot - 1, inMap);

  /*
    Step 5: Recursively build right subtree
    - Remaining elements after left subtree in preorder
    - Inorder right part defines right subtree
  */
  root->right = buildTree(preOrder, preStart + numsLeft + 1, preEnd, inOrder,
                          inRoot + 1, inEnd, inMap);

  return root;
}

/*
  Main function to initialize map and call recursive builder
*/
TreeNode *ConstructBinaryTreePreorderInorderTraversal(vector<int> &preOrder,
                                                      vector<int> &inOrder) {

  // Map to store inorder value → index
  // This avoids O(N) search every time
  map<int, int> inMap;

  for (int i = 0; i < inOrder.size(); i++) {
    inMap[inOrder[i]] = i;
  }

  // Call recursive function
  TreeNode *root = buildTree(preOrder, 0, preOrder.size() - 1, inOrder, 0,
                             inOrder.size() - 1, inMap);

  return root;
}

// Hash All th InOrder Elements take Preorder First Node that is root
// Search the Node in the Inorder then get how many elements before it lets
// assume x then take those x in inorder and mark them for recrusive inorder
// again and take x elements from preorder and mark them for preorder again
// recursively

// Inorder Traversal (Left → Root → Right)
void printInorder(TreeNode *root) {
  if (root == NULL)
    return;

  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

int main() {
  cout << "19 L34 Construct a Binary Tree from Preorder and Inorder Traversal"
       << endl;
  // We have to create Binary Tree Using given Preorder and Inorder Traversal
  // Note from Prev video acc to concepts this will form a Unique Binary Tree
  // Inorder : [40 20 50 10 60 30]
  // Preorder : [10 20 40 50 30 60]
  // Inorder : LEFT ROOT RIGHT
  // Preorder : ROOT LEFT RIGHT
  // From the Preorder we know First Node is Root
  // So we have got Root
  // that is 10 then if we are able to find the root in the Inorder
  // We can say that whatever is at Left of it is Left of BT and right is right
  // of BT Refer
  // 19_L34_Construct_a_Binary_Tree_from_Preorder_and_Inorder_Traversal_1
  // Then we can recursively Apply this Step to Left and rights and we can get a
  // Unique Binary Tree
  // Refer 19_L34_Construct_a_Binary_Tree_from_Preorder_and_Inorder_Traversal_2,
  // 19_L34_Construct_a_Binary_Tree_from_Preorder_and_Inorder_Traversal_3,
  // 19_L34_Construct_a_Binary_Tree_from_Preorder_and_Inorder_Traversal_4
  // 19_L34_Construct_a_Binary_Tree_from_Preorder_and_Inorder_Traversal_4

  vector<int> preOrder = {9, 3, 15, 20, 7};
  vector<int> inOrder = {3, 9, 20, 15, 7};
  TreeNode *root =
      ConstructBinaryTreePreorderInorderTraversal(preOrder, inOrder);

  // Print inorder to verify
  cout << "Inorder of constructed tree: ";
  printInorder(root);
  cout << endl;

  return 0;
}
