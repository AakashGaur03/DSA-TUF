#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to get Preorder, Inorder, Postorder in one traversal
void allInOne(TreeNode *root) {
  if (root == NULL)
    return;

  stack<pair<TreeNode *, int>> st;
  st.push({root, 1});

  vector<int> pre, in, post;

  while (!st.empty()) {
    auto it = st.top();
    st.pop();

    // Preorder case
    if (it.second == 1) {
      pre.push_back(it.first->val);
      // increment 1 to 2
      it.second++;
      st.push(it); // push back with incremented state

      if (it.first->left != NULL) {
        st.push({it.first->left, 1});
      }
    }
    // Inorder case
    else if (it.second == 2) {
      in.push_back(it.first->val);
      // increment 2 to 3
      it.second++;
      st.push(it);

      if (it.first->right != NULL) {
        st.push({it.first->right, 1});
      }
    }
    // Postorder case
    else {
      post.push_back(it.first->val);
    }
  }

  // Print results
  cout << "Preorder: ";
  for (int x : pre)
    cout << x << " ";
  cout << "\n";

  cout << "Inorder: ";
  for (int x : in)
    cout << x << " ";
  cout << "\n";

  cout << "Postorder: ";
  for (int x : post)
    cout << x << " ";
  cout << "\n";
}

int main() {
  cout << "5 L13 Preorder Inorder Postorder Traversals in One Traversal"
       << endl;

  /*
     Example Tree:
           1
          / \
         2   3
        / \
       4   5
  */

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  allInOne(root);

  // Single stack to find out all three traversals
  // we will store node,number in an stack (LIFO)
  // RULES

  // if number == 1
  // that will go to preorder
  // we push that number by doing a ++
  // and if there exist a left we enter the left

  // if number == 2
  // that will go to inorder
  // we push that number by doing a ++
  // and if there exist a right we enter the right

  // if number == 3
  // that will go to postorder
  // pop the number and node

  // Refer to 5_L13_Preorder_Inorder_Postorder_Traversals_in_One_Traversal_1,
  // 5_L13_Preorder_Inorder_Postorder_Traversals_in_One_Traversal_2 &
  // 5_L13_Preorder_Inorder_Postorder_Traversals_in_One_Traversal_3

  // TC O(3N) // we iterated over thrice for each node with number 1 2 3
  // SC O(4N) // we are using three differnt lists to store answer and
  // a stack for computation
  return 0;
}