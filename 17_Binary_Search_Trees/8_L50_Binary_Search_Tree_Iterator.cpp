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

class BSTIterator {

private:
  stack<TreeNode *> myStack;
  // Stack stores path to next smallest element (simulating inorder traversal)

public:
  BSTIterator(TreeNode *root) {
    // Push all left descendants so that the smallest element is on top
    pushAll(root);
  }

  bool hasNext() {
    // Returns true if there is a next smallest number
    return !myStack.empty();
  }
  int next() {
    // Top of stack = current smallest unvisited node
    TreeNode *tmpNode = myStack.top();
    myStack.pop();
    // If this node has a right subtree,
    // push all its left descendants
    pushAll(tmpNode->right);
    return tmpNode->val;
  }

private:
  // Push all left nodes from given node into stack
  // This ensures smallest element is always on top
  void pushAll(TreeNode *node) {
    for (; node != nullptr; myStack.push(node), node = node->left)
      ;

    // Simpler Version
    // while (node != nullptr) {
    //   myStack.push(node);
    //   node = node->left;
    // }
  }
};

int main() {
  cout << "8 L50 Binary Search Tree Iterator" << endl;
  // BST L < N < R

  /*
   Example Tree:
           7
        /    \
       3      15
             /  \
            9    20
*/
  // Inorder will be 3 7 9 15 20

  // Design BST Iterator
  // We will have 3 components BSTiterator, next, hasNext
  // BSTiterator(x) this x is the root of the BST
  // initally it will be pointing to null so when first Next is called
  // next will be 3 (acc to inorder)
  // after that next will point to 7 (acc to inorder 3 7 9 15 20)
  // after that next will point to 9 (acc to inorder 3 7 9 15 20)
  // and so on
  // hasNext gives us true or falso if there exist a next or not acc to
  // inorder

  // BSTiterator(7)
  // next     -> 3
  // next     -> 7
  // hasNext  -> true
  // next     -> 9
  // hasNext  -> true
  // next     -> 15
  // hasNext  -> true
  // next     -> 20
  // hasNext  -> false

  // Simple appraoch is Store the Inorder in vector and then iterate over it
  // TC O(1) for each operation and SC O(N) because we are storing BST

  // But we are asked to perform this in SC O(H)
  // For that we will be using the same approach of Inorder Traversal But with
  // a updation that we will only store the elements till the Height of the
  // BST
  // Space Complexity:
  // O(H), where H = height of BST

  // Time Complexity:
  // next() -> Amortized O(1)
  // hasNext() -> O(1)
  // Each node is pushed and popped exactly once overall
  return 0;
}
