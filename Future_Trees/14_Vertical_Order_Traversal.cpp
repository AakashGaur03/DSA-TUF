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
vector<vector<int>> verticalTraversal(TreeNode *root) {
  map<int, map<int, multiset<int>>> nodes;
  queue<pair<TreeNode *, pair<int, int>>> todo;
  // todo is for traversing

  // nodes is for storing the correct order
  todo.push({root, {0, 0}});
  while (!todo.empty()) {
    auto p = todo.front();
    todo.pop();
    TreeNode *node = p.first;
    int x = p.second.first;
    int y = p.second.second;
    nodes[x][y].insert(node->val);
    if (node->left) {
      todo.push({node->left, {x - 1, y + 1}});
    }
    if (node->right) {
      todo.push({node->right, {x + 1, y + 1}});
    }
  }

  vector<vector<int>> ans;
  for (auto p : nodes) {
    vector<int> col;
    for (auto q : p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}

int main() {

  cout << "14 Vertical Order Traversal" << endl;
  // basic Idea is to get them in a way to arrange them on the basis on axes
  // refer to the image So whenever we move to left we do -1 and +1 -1 for going
  // in left and+1 for going down
  // And similarly for right we do +1,+1 for right and down

  // Create the tree:
  //         3
  //        / \
  //       9  20
  //          / \
  //         15  7

  //   Column -1: [Row 1: 9 ]
  // Column 0: [Row 0: 3 ] [Row 2: 15 ]
  // Column 1: [Row 1: 20 ]
  // Column 2: [Row 2: 7 ]

  // A multiset is like a set, but it allows duplicate elements.
  // Key feature: it automatically keeps its elements in sorted order.
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  vector<vector<int>> result = verticalTraversal(root);

  for (auto &col : result) {
    for (int val : col) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
Tree:

        3
       / \
      9  20
         / \
        15  7

Coordinate system (x = column, y = row):
- Root: (0,0)
- Left child: (x-1, y+1)
- Right child: (x+1, y+1)
- Multiset automatically sorts values if multiple nodes share same (x,y)
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalTraversal(TreeNode *root) {
  map<int, map<int, multiset<int>>> nodes;
  queue<pair<TreeNode *, pair<int, int>>> todo;

  // Step 0: Push root (3) at (0,0)
  todo.push({root, {0, 0}});

  while (!todo.empty()) {
    auto p = todo.front();
    todo.pop();
    TreeNode *node = p.first;
    int x = p.second.first;
    int y = p.second.second;

    // Step 1: Insert node->val into nodes[x][y]
    nodes[x][y].insert(node->val);

    // Step 2: Add left child to queue
    if (node->left)
      todo.push({node->left, {x - 1, y + 1}});

    // Step 3: Add right child to queue
    if (node->right)
      todo.push({node->right, {x + 1, y + 1}});
  }

  // Step 4: Construct answer from map
  vector<vector<int>> ans;
  for (auto p : nodes) {
    vector<int> col;
    for (auto q : p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}

int main() {
  // Create the tree
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  // Call vertical traversal
  vector<vector<int>> result = verticalTraversal(root);

  // Dry run visualization
  // Queue and map updates step by step:

  /*
  Initial queue: [(3, (0,0))]

  Step 1:
  Pop (3,0,0)
  Insert 3 into nodes[0][0] => nodes = {0: {0: {3}}}
  Push left (9, -1,1) and right (20, 1,1)
  Queue: [(9,-1,1), (20,1,1)]

  Step 2:
  Pop (9,-1,1)
  Insert 9 into nodes[-1][1] => nodes = {-1:{1:{9}}, 0:{0:{3}}}
  9 has no children
  Queue: [(20,1,1)]

  Step 3:
  Pop (20,1,1)
  Insert 20 into nodes[1][1] => nodes = {-1:{1:{9}}, 0:{0:{3}}, 1:{1:{20}}}
  Push left (15,0,2) and right (7,2,2)
  Queue: [(15,0,2), (7,2,2)]

  Step 4:
  Pop (15,0,2)
  Insert 15 into nodes[0][2] => nodes = {-1:{1:{9}}, 0:{0:{3}, 2:{15}},
  1:{1:{20}}, 2:{2:{7}}} 15 has no children Queue: [(7,2,2)]

  Step 5:
  Pop (7,2,2)
  Insert 7 into nodes[2][2] => nodes = {-1:{1:{9}}, 0:{0:{3}, 2:{15}},
  1:{1:{20}}, 2:{2:{7}}} 7 has no children Queue empty → BFS done

  Construct answer from nodes:
  Column -1: [9]
  Column 0: [3, 15]
  Column 1: [20]
  Column 2: [7]

  Final vertical order traversal:
  9
  3 15
  20
  7
  */