#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &vis, vector<int> &pathVis,
         vector<vector<int>> &adj, vector<int> &check) {
  vis[node] = 1;
  pathVis[node] = 1;
  check[node] = 0;

  for (auto adjNode : adj[node]) {
    if (!vis[adjNode]) {
      if (dfs(adjNode, vis, pathVis, adj, check)) {
        check[node] = 0;
        return true;
      }
    } else if (pathVis[adjNode]) {
      check[node] = 0;
      return true;
    }
  }
  // If a DFS is successfully completed means it is a safe node
  // because if there is a cycle it will break out in above return
  check[node] = 1;
  pathVis[node] = 0;
  return false;
}

vector<int> evaluateSafeNodes(int V, vector<vector<int>> &adj) {
  // TC O(V+E)
  // SC O(3V)
  vector<int> vis(V, 0);
  vector<int> pathVis(V, 0);
  vector<int> check(V, 0);
  vector<int> safeNodes;
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      dfs(i, vis, pathVis, adj, check); // WE need all the DFS So we dont break
    }
  }

  for (int i = 0; i < V; i++) {
    if (check[i] == 1) {
      safeNodes.push_back(i);
    }
  }

  return safeNodes;
}

int main() {
  cout << "17 G 20 Find Eventual Safe States DFS" << endl;

  //   There is a directed graph of n nodes with each node labeled from 0 to
  //   n - 1. The graph is represented by a 0-indexed 2D integer array graph
  //   where graph[i] is an integer array of nodes adjacent to node i, meaning
  //   there is an edge from node i to each node in graph[i].

  // A node is a terminal node if there are no outgoing edges. A node is a safe
  // node if every possible path starting from that node leads to a terminal
  // node (or another safe node).

  // Return an array containing all the safe nodes of the graph. The answer
  // should be sorted in ascending order.

  // Refer 17_G_20_Find_Eventual_Safe_States_DFS_1
  // We will use Cycle Detection Technique
  // So in the mentioned Image answer will be [2,4,5,6]

  // Anyone who is a part of cycle or connected to cycle(incoming edge to
  //  cycle), cant be a safe Node

  // Anyone who is a part of cycle
  // Anyone connected to cycle(incoming edge to cycle), cant be a safe Node

  // Extension Problem of 16_G_19_Detect_cycle_in_a_directed_graph_using_DFS
  int V = 7;

  // Graph:
  // 0 → 1,2
  // 1 → 2,3
  // 2 → 5
  // 3 → 0
  // 4 → 5
  // 5 → (terminal)
  // 6 → (terminal)

  vector<vector<int>> adj = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

  vector<int> safeNodes = evaluateSafeNodes(V, adj);

  cout << "Safe Nodes: ";
  for (auto node : safeNodes) {
    cout << node << " ";
  }
  cout << endl;
  return 0;
}