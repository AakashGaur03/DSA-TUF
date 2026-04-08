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

TreeNode *next(stack<TreeNode *> &st) {
  TreeNode *node = st.top();
  st.pop();
  TreeNode *temp = node->right;

  while (temp) {
    st.push(temp);
    temp = temp->left;
  }
  return node;
}
TreeNode *before(stack<TreeNode *> &st) {
  TreeNode *node = st.top();
  st.pop();
  TreeNode *temp = node->left;
  while (temp) {
    st.push(temp);
    temp = temp->right;
  }
  return node;
}

bool twoSumBST(TreeNode *root, int K) {
  // TC O(N)
  // SC O(2H)

  if (!root) {
    return false;
  }

  stack<TreeNode *> leftSt, rightSt;

  TreeNode *temp = root;
  while (temp) {
    leftSt.push(temp);
    temp = temp->left;
  }

  temp = root;
  while (temp) {
    rightSt.push(temp);
    temp = temp->right;
  }

  TreeNode *left = next(leftSt);
  TreeNode *right = before(rightSt);

  while (left && right && left != right) {

    int sum = left->val + right->val;
    if (sum == K) {
      return true;
    } else if (sum < K) {
      left = next(leftSt);
    } else {
      right = before(rightSt);
    }
  }

  return false;
}

int main() {
  cout << "9 L51 Two Sum In BST | Check if there exists a pair with Sum K"
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
