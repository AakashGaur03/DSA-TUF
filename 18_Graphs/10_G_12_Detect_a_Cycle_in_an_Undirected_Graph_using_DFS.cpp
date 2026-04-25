#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis) {
  vis[node] = 1;

  for (auto adjacentNode : adj[node]) {
    if (!vis[adjacentNode]) {
      if (dfs(adjacentNode, node, adj, vis)) {
        return true;
      }
    } else if (parent != adjacentNode) {
      // already visited Node
      return true;
    }
  }
  return false;
}

bool isCycle(int V, vector<int> adj[]) {
  // TC O(N+ 2E)
  // SC O(N)
  vector<int> vis(V, 0);
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      // Because there can be Connected Components too
      // Refer 9_G_11_Detect_a_Cycle_in_an_Undirected_Graph_using_BFS_4
      if (dfs(i, -1, adj, vis)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  cout << "10 G 12 Detect a Cycle in an Undirected Graph using DFS" << endl;
  // Same question 9_G_11_Detect_a_Cycle_in_an_Undirected_Graph_using_BFS
  // We will be using a DFS
  // Approach
  // we will traverse using DFS So when we traverse we dont go back to node
  // where we came from But if there is a case when we are visiting a node that
  // we have alredy visited other than the parent one that means there is a
  // cycle

  int V = 5;
  vector<int> adj[V];

  // Creating graph
  // 0 -- 1
  // |    |
  // 3 -- 2   (cycle exists)
  // 4 (isolated)

  adj[0].push_back(1);
  adj[1].push_back(0);

  adj[1].push_back(2);
  adj[2].push_back(1);

  adj[2].push_back(3);
  adj[3].push_back(2);

  adj[3].push_back(0);
  adj[0].push_back(3);

  // Node 4 is isolated

  if (isCycle(V, adj)) {
    cout << "Cycle detected\n";
  } else {
    cout << "No cycle\n";
  }

  return 0;
}