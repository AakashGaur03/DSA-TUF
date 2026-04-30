#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &vis, vector<int> &pathVis,
         vector<vector<int>> &adj) {
  vis[node] = 1;
  pathVis[node] = 1;

  for (auto adjNode : adj[node]) {
    if (!vis[adjNode]) {
      if (dfs(adjNode, vis, pathVis, adj)) {
        return true;
      }
    } else if (pathVis[adjNode]) {
      // Means Visited and also ParhVisited
      return true;
    }
  }
  pathVis[node] = 0;
  return false;
}

bool detectCycleDirectedGraph(int V, vector<vector<int>> &adj) {
  // TC O(V+E)
  // SC O(2N)

  vector<int> vis(V, 0);
  vector<int> pathVis(V, 0);

  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      if (dfs(i, vis, pathVis, adj)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  cout << "16 G 19 Detect cycle in a directed graph using DFS" << endl;
  // Here 10_G_12_Detect_a_Cycle_in_an_Undirected_Graph_using_DFS this will not
  // work as there we were
  // where we came from But if there is a case when we are visiting a node
  // that we have alredy visited other than the parent one that means there is a
  // cycle but here 16_G_19_Detect_cycle_in_a_directed_graph_using_DFS_1
  // 16_G_19_Detect_cycle_in_a_directed_graph_using_DFS_2 these will fail

  // In here we will Note that a node should be visited again on same path then
  // only it can be called as Cycle

  // So here we will take two Arrays visited and pathVisited
  // Now visited will remain as we were performing pathVisisted will be marked
  // as 1 when visited and when backtracking we will again update it to 0

  // So Visited will help us to not itertate over Nodes again and again and
  // pathVisited will help us to take Directed Cycle in considertation

  int V = 6;
  vector<vector<int>> adj(V);

  // Graph:
  // 0 → 1
  // 1 → 2
  // 2 → 3
  // 3 → 1  (cycle here)
  // 4 → 5  (separate component, no cycle)

  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(3);
  adj[3].push_back(1);
  adj[4].push_back(5);

  if (detectCycleDirectedGraph(V, adj)) {
    cout << "Cycle detected\n";
  } else {
    cout << "No cycle\n";
  }

  return 0;
}