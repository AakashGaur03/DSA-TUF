#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "" << endl;
  return 0;
}

// We need to keep Unique class name
// Singly LL
class Node {
public:
  int data;
  Node *next;

public:
  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }

  // we can also add if we dont want to assign null
  // in code again and again
public:
  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

// We need to keep Unique class name
// Doubly LL
class Node {
public:
  int data;
  Node *next;
  Node *back;

public:
  Node(int data1, Node *next1, Node *back1) {
    data = data1;
    next = next1;
    back = back1;
  }

  // we can also add if we dont want to assign null
  // in code again and again
public:
  Node(int data1) {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

struct TreeNode {
  int val; // The data stored in the node (here it's an integer value)
  TreeNode *left, *right; // Pointers to the left and right child nodes

  // Constructor: initializes a node with value 'x'
  // left and right child pointers are set to NULL (meaning no children
  // initially)
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
GRAPH
// --------------------------------------------------------
  // GENERIC CODE
  //  If we are given AdJ matrix then we can convert it to Adj List
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (adjMat[i][j] == 1 && i != j) {
        adjLs[i].push_back(j);
      }
    }
  }
  // It still behaves like an undirected graph because:
  // Because we are scanning the full matrix:
  // Matrix has both adjMat[i][j] and adjMat[j][i]
  // So both directions eventually get added
  // OR
  // we can reduce work by half:
  // for (int i = 0; i < V; i++) {
  //   for (int j = i + 1; j < V; j++) {
  //     if (adjMat[i][j] == 1) {
  //       adjLs[i].push_back(j);
  //       adjLs[j].push_back(i);
  //     }
  //   }
  // }

  // --------------------------------------------------------
*/