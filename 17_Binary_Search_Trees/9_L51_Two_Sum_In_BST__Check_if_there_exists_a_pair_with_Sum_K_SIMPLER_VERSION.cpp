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
  // Stack stores path to next smallest element (simulating inorder traversal)
  stack<TreeNode *> myStack;
  // reverse = true -> before
  // reverse = false -> next
  bool reverse = true;

public:
  BSTIterator(TreeNode *root, bool isReverse) {
    reverse = isReverse;
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
    if (reverse) {
      pushAll(tmpNode->left);
    } else {
      pushAll(tmpNode->right);
    }
    return tmpNode->val;
  }

private:
  // Push all left nodes from given node into stack
  // This ensures smallest element is always on top
  void pushAll(TreeNode *node) {
    while (node != nullptr) {
      myStack.push(node);
      if (reverse == true) {
        node = node->right;
      } else {
        node = node->left;
      }
    }
  }
};

bool twoSumBST(TreeNode *root, int K) {
  if (!root) {
    return false;
  }

  // For Next
  BSTIterator l(root, false);
  // For Before
  BSTIterator r(root, true);

  int i = l.next();
  int j = r.next();

  while (i < j) {
    if (i + j == K) {
      return true;
    } else if (i + j < K) {
      i = l.next();
    } else {
      j = r.next();
    }
  }
  return false;
}

int main() {
  cout << "9 L51 Two Sum In BST | Check if there exists a pair with Sum K "
          "SIMPLER VERSION"
       << endl;
  // BST L < N < R

  // We will be Given A Binary Tree and a K
  // We need to check if two root as such there sum is equal to K
  // and return True or False

  /*
   Example Tree:
           5
        /    \
       3      6
     /  \       \
    2    4        7
*/
  // K = 9;

  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);

  // ANS can be 5,4
  // ANS can be 3,6
  // ANS can be 2,7

  // Naive Appraoch We get the Inorder and then perform 2 Sum as in 4_2_Sum.cpp
  // TC O(2N) for getting in inorder and then Two Sum
  // SC O(N) for storing in Inorder

  // One Appraoch is we will use the Concept used in BST Iterator
  // 8_L50_Binary_Search_Tree_Iterator.cpp
  // We know how to Compute Next that will be Sorted Order of The Tree
  // We will also compute before it will be same just in next we were doing Left
  // Root Right in before we will be doing Right Root Left
  // Then we will have a pointer at Next and one pointer at before
  // and then acc to sum of both we will either do Next or Before as we did in 2
  // Sum left++ or right--

  int K = 9;
  bool present = twoSumBST(root, K);
  cout << present;

  return 0;
}
