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

// Build a map that stores: child -> parent
void markParents(TreeNode *root,
                 unordered_map<TreeNode *, TreeNode *> &parent_track,
                 TreeNode *target) {
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *current = q.front();
    q.pop();
    if (current->left) {
      parent_track[current->left] = current; // store parent
      q.push(current->left);
    }
    if (current->right) {
      parent_track[current->right] = current; // store parent
      q.push(current->right);
    }
  }
}

vector<int> nodesAtDistanceK(TreeNode *root, TreeNode *target, int K) {
  // TC O(N)
  // SC O(N + logN(for hashMap))
  unordered_map<TreeNode *, TreeNode *> parent_track;
  markParents(root, parent_track, target);

  unordered_map<TreeNode *, bool> visited;
  queue<TreeNode *> q;
  q.push(target); // start BFS from target
  visited[target] = true;
  int curr_level = 0;

  while (!q.empty()) {
    int size = q.size();
    // stop when we reach level K
    if (curr_level++ == K) {
      break;
    }
    for (int i = 0; i < size; i++) {
      TreeNode *current = q.front();
      q.pop();
      // move to left child
      if (current->left && !visited[current->left]) {
        q.push(current->left);
        visited[current->left] = true;
      }
      // move to right child
      if (current->right && !visited[current->right]) {
        q.push(current->right);
        visited[current->right] = true;
      }
      // move to parent
      if (parent_track[current] && !visited[parent_track[current]]) {
        q.push(parent_track[current]);
        visited[parent_track[current]] = true;
      }
    }
  }
  // remaining nodes in queue are at distance K
  vector<int> result;
  while (!q.empty()) {
    TreeNode *current = q.front();
    q.pop();
    result.push_back(current->val);
  }
  return result;
}

int main() {
  cout << "16 L30 Print all the Nodes at a distance of K in Binary Tree"
       << endl;
  // We will be given K and a target
  // K is the distance here
  // So we have to print all the nodes that are at K distance from the target
  // Refer 16_L30_Print_all_the_Nodes_at_a_distance_of_K_in_Binary_Tree_1 for
  // below tree

  /*
        Example Tree:
                3
             /    \
            5      1
           / \     / \
          6   2   0   8
             / \
            7   4
  */
  // One concern we can see in this problem is we dont know how to traverse back
  // as we know 3's left is 5 but there is attachment or link from 5 to 3

  // We will mark Parent Pointers we will do BFS Traversal
  // So while Doing BFS we will make the child with Parent Pointers with a
  // hashmap Refer
  // 16_L30_Print_all_the_Nodes_at_a_distance_of_K_in_Binary_Tree_2 After this
  // we can move upwards too

  // We will reach to the Target node and then readily will search for nodes
  // with distance k in both Direction Upward and Downward
  // First we will search for distance 1 then 2 until we reach K
  // NOTE we also need to track the visited Node so you know from which
  // Direction you came from and dont have to move in that direction

  // Build tree as shown Above
  TreeNode *root = new TreeNode(3);

  root->left = new TreeNode(5);
  root->right = new TreeNode(1);

  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);

  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);

  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  TreeNode *target = root->left;
  int K = 2;
  vector<int> ans = nodesAtDistanceK(root, target, K);
  for (int x : ans)
    cout << x << " ";
  return 0;
}
