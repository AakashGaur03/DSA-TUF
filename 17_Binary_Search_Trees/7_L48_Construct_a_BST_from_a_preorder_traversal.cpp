#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val; // The data stored in the node (here it's an integer value)
  TreeNode *left, *right; // Pointers to the left and right child nodes

  // Constructor: initializes a node with value 'x'
  // left and right child pointers are set to NULL (meaning no children
  // initially)
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(vector<int> &preOrder, int preStart, int preEnd,
                    vector<int> &inOrder, int inStart, int inEnd,
                    map<int, int> &inMap) {

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

TreeNode *insertNode(TreeNode *root, int val) {
  if (!root)
    return new TreeNode(val);

  if (val < root->val) {
    root->left = insertNode(root->left, val);
  } else {
    root->right = insertNode(root->right, val);
  }

  return root;
}

TreeNode *bruteApproach(vector<int> &preOrder) {
  TreeNode *root = nullptr;

  for (int val : preOrder) {
    root = insertNode(root, val);
  }

  return root;
}

TreeNode *betterApproach(vector<int> preOrder) {
  /*
  IDEA:
  A BST's inorder traversal is always sorted.

  So:
  1. Given preorder
  2. Create inorder by sorting preorder
  3. Now we have:
      - Preorder
      - Inorder
  4. Use standard "Construct Binary Tree from Preorder + Inorder"
*/

  vector<int> inOrder = preOrder;

  // Step 1: Sort to get inorder traversal of BST
  sort(inOrder.begin(), inOrder.end());

  /*
    Step 2: Build tree using preorder + inorder

    Why this works:
    - Preorder gives root first
    - Inorder splits tree into left + right parts
    - This uniquely reconstructs the BST
  */

  return ConstructBinaryTreePreorderInorderTraversal(preOrder, inOrder);
}

TreeNode *builtOptimalTree(vector<int> &preOrder, int &i, int upperBound) {

  /*
    BASE CONDITION:
    - If all elements are used OR
    - Current value exceeds allowed bound → cannot be placed here
  */
  if (i == preOrder.size() || preOrder[i] > upperBound) {
    return nullptr;
  }

  /*
    Step 1: Create root from current preorder element
    Preorder ensures root comes first
  */
  TreeNode *root = new TreeNode(preOrder[i++]);

  /*
    Step 2: Build LEFT subtree

    Constraint:
    - Left subtree values must be < root->val

    So we update upperBound = root->val
  */
  root->left = builtOptimalTree(preOrder, i, root->val);

  /*
    Step 3: Build RIGHT subtree

    Constraint:
    - Values must be < upperBound (inherited from parent)

    This ensures correct BST placement
  */
  root->right = builtOptimalTree(preOrder, i, upperBound);

  return root;
}

TreeNode *optimalApproach(vector<int> &preOrder) {
  // TC O(N)
  // TC O(H) Recursion Stack

  /*
    IDEA:
    We simulate BST construction using preorder traversal.

    Key Observations:
    - Preorder → Root → Left → Right
    - Each node has a valid range (min, max)
    - Instead of min/max, we track only upperBound

    HOW IT WORKS:
    - Keep a global index `i`
    - At each step:
        - If value fits in bound → create node
        - Otherwise → stop recursion

    This ensures:
    - Each node is processed exactly once
  */
  int i = 0;
  return builtOptimalTree(preOrder, i, INT_MAX);
}

int main() {
  cout << "7 L48 Construct a BST from a preorder traversal" << endl;

  vector<int> preOrder = {8, 5, 1, 7, 10, 12};
  TreeNode *root1 = bruteApproach(preOrder);
  // For each node determine Left or Right
  // TC O(N*N)
  // SC O(1)

  TreeNode *root2 = betterApproach(preOrder);
  // Better Apporach
  // for Preorder we can sort it after sorting it will be the corresponding
  // inorder So now we have Inorder and a Preorder so we can create a unique BT
  // that will be BST as done before also
  // TC O(N logN) + O(N)
  // SC O(N) for Inorder

  TreeNode *root3 = optimalApproach(preOrder);
  // Optimal Appraoch
  // From 5_L46_Check_if_a_tree_is_a_BST_or_BT we know that each node has a
  // range
  // We will be passing Upper Bound in each node
  return 0;
}
