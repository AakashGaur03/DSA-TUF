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
TreeNode *buildTree(vector<int> &postOrder, int postStart, int postEnd,
                    vector<int> &inOrder, int inStart, int inEnd,
                    map<int, int> &inMap) {

  // Base case: if range becomes invalid, return NULL
  if (postStart > postEnd || inStart > inEnd) {
    return nullptr;
  }

  // Step 1: Last element of postorder is always the root
  TreeNode *root = new TreeNode(postOrder[postEnd]);

  // Step 2: Find root index in inorder using map
  int inRoot = inMap[root->val];

  // Step 3: Count how many nodes are in left subtree
  int numsLeft = inRoot - inStart;

  /*
  Step 4: Recursively build left subtree
  - Next element in preorder is start of left subtree
  - Inorder left part defines left subtree
*/

  root->left = buildTree(postOrder, postStart, postStart + numsLeft - 1,
                         inOrder, inStart, inRoot - 1, inMap);

  /*
    Step 5: Recursively build right subtree
    - Remaining elements after left subtree in preorder
    - Inorder right part defines right subtree
  */
  root->right = buildTree(postOrder, postStart + numsLeft, postEnd - 1, inOrder,
                          inRoot + 1, inEnd, inMap);

  return root;
}

/*
Main function to initialize map and call recursive builder
*/
TreeNode *ConstructBinaryTreePostorderInorderTraversal(vector<int> &postOrder,
                                                       vector<int> &inOrder) {
  // Map to store inorder value → index
  // This avoids O(N) search every time
  map<int, int> inMap;

  for (int i = 0; i < inOrder.size(); i++) {
    inMap[inOrder[i]] = i;
  }

  TreeNode *root = buildTree(postOrder, 0, postOrder.size() - 1, inOrder, 0,
                             inOrder.size() - 1, inMap);

  return root;
}

// Hash All th InOrder Elements take Postorder Last Node that is root
// Search the Node in the Inorder then get how many elements before it lets
// assume x then take those x in inorder and mark them for recrusive inorder
// again and take x elements from postorder and mark them for postorder
// again recursively

// Inorder Traversal (Left → Root → Right)
void printInorder(TreeNode *root) {
  if (root == NULL)
    return;

  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

int main() {
  cout << "20 L35 Construct a Binary Tree from Postorder and Inorder Traversal"
       << endl;
  // We have to create Binary Tree Using given Postorder and Inorder Traversal
  // Note from Prev video acc to concepts this will form a Unique Binary Tree
  // Inorder : [40 20 50 10 60 30]
  // Postorder : [40 50 20 60 30 10]
  // Inorder : LEFT ROOT RIGHT
  // Postorder : LEFT RIGHT ROOT
  // From the Postorder we know Last Node is Root
  // So we have got Root
  // that is 10 then if we are able to find the root in the Inorder
  // We can say that whatever is at Left of it is Left of BT and right is right
  // of BT Refer
  // 20_L35_Construct_a_Binary_Tree_from_Postorder_and_Inorder_Traversal_1
  // Then we can recursively Apply this Step to Left and rights and we can get a
  // Unique Binary Tree
  // Refer
  // 20_L35_Construct_a_Binary_Tree_from_Postorder_and_Inorder_Traversal_2,
  // 20_L35_Construct_a_Binary_Tree_from_Postorder_and_Inorder_Traversal_3,
  // 20_L35_Construct_a_Binary_Tree_from_Postorder_and_Inorder_Traversal_4

  vector<int> inOrder = {9, 3, 15, 20, 7};
  vector<int> postOrder = {9, 15, 7, 20, 3};
  TreeNode *root =
      ConstructBinaryTreePostorderInorderTraversal(postOrder, inOrder);

  // Print inorder to verify
  cout << "Inorder of constructed tree: ";
  printInorder(root);
  cout << endl;

  return 0;
}
