using namespace std;
#include <bits/stdc++.h>

struct TreeNode {
  int val; // The data stored in the node (here it's an integer value)
  TreeNode *left, *right; // Pointers to the left and right child nodes

  // Constructor: initializes a node with value 'x'
  // left and right child pointers are set to NULL (meaning no children
  // initially)
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  TreeNode *first;
  TreeNode *prev;
  TreeNode *middle;
  TreeNode *second;

  void inorder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    // -----------------------------------------
    // Commented Explaination Below
    inorder(root->left);
    if (prev && root->val < prev->val) {
      // If First Violation Store Both Nodes
      if (first == nullptr) {
        first = prev;
        middle = root;
      } else {
        // If second Violation Store only violated Node
        second = root;
      }
    }
    // -----------------------------------------

    prev = root;
    inorder(root->right);
  }

public:
  void recoverBST(TreeNode *root) {
    // TC O(2N)
    // SC: O(H)  // ( if done using Morris then O(1) )
    first = middle = second = nullptr;
    prev = nullptr;
    inorder(root);

    if (first && second) {
      swap(first->val, second->val);
    } else if (first && middle) {
      swap(first->val, middle->val);
    }
  }
};

int main() {
  cout << "10 L52 Recover BST | Correct BST with two nodes swapped" << endl;
  // BST L < N < R
  // We will be Given a Node and in this BST there will be two nodes that are
  // swapped
  // So we need to swap them back and Correct the BST

  /*
   Example Tree:
           5
        /    \
       6      3
     /  \       \
    2    4        7
*/
  // K = 9;

  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(6);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);

  // BRUTE
  // we can do any Traversal and then sort it
  // Means we will have a Inorder of the BST
  // Then we can compare nodes with inorder and place correct values at BST
  // TC will be O(2N + N log N)
  // SC O(N)

  // OPTIMAL
  // We can get the Inorder of the BST that has two value Swapped
  // There can be two case that swapped values are not at adjacent Nodes
  // Like 3 25 7 8 10 15 20 5
  // Here 25 and 5
  // and second case swapped values are at adjacent Nodes
  // Like 3 5 8 7 10 15 20 25
  // Here 8 and 7

  // So for Non Adjacent when we iterate over it we can see that i should be <
  // i++ and if thats not the case we can get our First and Second Element
  // that are violating the rule and then swap them

  // For Adjacent Node
  // There will be only 1 Violation so we will also Store or remember that
  // First Element is violating with whom and if we dont find Second element
  // we swap that element with whom it is violating the rule

  Solution obj;
  obj.recoverBST(root);

  /*

  inorder(root->left);

  // Detect violation of BST property (inorder should be sorted)
  // If previous node value is greater than current, it's a violation
  if (prev && root->val < prev->val) {

  // First violation:
  // store previous node as 'first' (larger one)
  // store current node as 'middle' (smaller one)
  if (first == nullptr) {
    first = prev;
    middle = root;
  }
  // Second violation:
  // update 'second' to current node
  else {
    second = root;
  }
  }
  */

  return 0;
}
