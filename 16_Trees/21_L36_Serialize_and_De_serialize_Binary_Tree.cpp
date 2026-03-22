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

string serialize(TreeNode *node) {
  string s;

  queue<TreeNode *> q;

  q.push(node);

  while (!q.empty()) {
    TreeNode *currentNode = q.front();
    q.pop();
    if (currentNode == nullptr) {
      s.append("#,");
    } else {
      s.append(to_string(currentNode->val) + ',');
    }
    if (currentNode != nullptr) {
      q.push(currentNode->left);
      q.push(currentNode->right);
    }
  }
  return s;
}

TreeNode *deSerialize(string data) {
  if (data.size() == 0) {
    return nullptr;
  }
  // stringstream allows the string to be iterated over as objects
  stringstream s(data);
  string str;
  // it separates the value with the help of separator in our case ','
  getline(s, str, ',');
  TreeNode *root = new TreeNode(stoi(str)); // coverts String to Number
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    getline(s, str, ',');
    if (str == "#") {
      node->left = nullptr;
    } else {
      TreeNode *leftNode = new TreeNode(stoi(str));
      node->left = leftNode;
      q.push(leftNode);
    }
    getline(s, str, ',');
    if (str == "#") {
      node->right = nullptr;
    } else {
      TreeNode *rightNode = new TreeNode(stoi(str));
      node->right = rightNode;
      q.push(rightNode);
    }
  }
  return root;
}

void printLevelorder(TreeNode *root) {
  if (root == NULL)
    return;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *curr = q.front();
    q.pop();

    cout << curr->val << " ";

    if (curr->left)
      q.push(curr->left);
    if (curr->right)
      q.push(curr->right);
  }
}

int main() {
  cout << "21 L36 Serialize and De serialize Binary Tree" << endl;
  // We have to write two functions Serialize and De Serialize
  // So that we will be given a root of the BT we will send it to
  // Serialize function it will return us the string and when we pass the same
  // string to the De Serialize it will covert it to the original Binary Tree

  // We can use and Traversal Level Order InOrder PreOrder PostOrder
  /*
       Example Tree:
               1
            /    \
           2      3
                 / \
                4   5
 */
  // Will be performing Level Order Traversal
  // String will be 1, 2, 3, #, #, 4, 5, #,#,#,#

  TreeNode *root = new TreeNode(1);

  // Level 2
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  // Level 3
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  cout << "Level Order of constructed tree: ";
  printLevelorder(root);
  cout << endl;

  string s = serialize(root);
  cout << "Serialize Value: " << s << endl;
  TreeNode *node = deSerialize(s);
  // TC O(N)
  // SC O(N)
  cout << "Level Order of constructed tree: ";
  printLevelorder(node);
  cout << endl;
  return 0;
}
