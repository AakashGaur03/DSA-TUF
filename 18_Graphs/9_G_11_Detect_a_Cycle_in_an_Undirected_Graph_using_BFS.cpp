#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], vector<int> &vis) {
  vis[src] = 1;
  queue<pair<int, int>> q; // {who got visisted,last visited}
  q.push({src, -1});       // -1 beause inital dont have any last visited
  while (!q.empty()) {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();

    for (auto adjacentNode : adj[node]) {
      if (!vis[adjacentNode]) {
        vis[adjacentNode] = 1;
        q.push({adjacentNode, node});
      } else if (parent != adjacentNode) {
        // already visited Node
        return true;
      }
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
      if (detect(i, adj, vis)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  cout << "9 G 11 Detect a Cycle in an Undirected Graph using BFS" << endl;
  // Refer 9_G_11_Detect_a_Cycle_in_an_Undirected_Graph_using_BFS_1 &
  // 9_G_11_Detect_a_Cycle_in_an_Undirected_Graph_using_BFS_2
  // adjList for the above Image
  //  1 -> {2,3}
  //  2 -> {1,5}
  //  3 -> {1,4,6}
  //  4 -> {3}
  //  5 -> {2,7}
  //  6 -> {3,7}
  //  6 -> {5,6}

  // Approach
  // we will traverse using BFS So when we traverse we dont go back to node
  // where we came from But if there is a case when two different Node reaches
  // to same node Refer 9_G_11_Detect_a_Cycle_in_an_Undirected_Graph_using_BFS_3
  // that means there is a cycle

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