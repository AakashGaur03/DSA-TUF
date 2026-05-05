#include <bits/stdc++.h>
using namespace std;

vector<int> evaluateSafeNodes(int V, vector<vector<int>> &adj) {
  vector<vector<int>> adjRev(V);
  vector<int> indegree(V, 0);

  for (int i = 0; i < V; i++) {
    for (auto it : adj[i]) {
      // Originally it was i -> it
      // We did it -> i
      adjRev[it].push_back(i);
      indegree[i]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> safeNodes;

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    safeNodes.push_back(node);

    for (auto it : adjRev[node]) {
      indegree[it]--;

      if (indegree[it] == 0) {
        q.push(it);
      }
    }
  }

  sort(safeNodes.begin(), safeNodes.end());
  return safeNodes;
}

int main() {
  cout << "22_G_25_Find_Eventual_Safe_States_BFS_Topological_Sort" << endl;

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
  // We will use Topo Sort
  // So in the mentioned Image answer will be [2,4,5,6]

  // Anyone who is a part of cycle or connected to cycle(incoming edge to
  //  cycle), cant be a safe Node

  // Anyone who is a part of cycle
  // Anyone connected to cycle(incoming edge to cycle), cant be a safe Node

  // So How are we planning to Solve it in using Topo Sort
  // POINT TO NOTE that all Terminal Node can be our Safe Node
  // So we will backtrack we will see that terminal node is 0 that can be our
  // answer and then remove that one from the indegre of others

  // STEP 1 Reverse all the Edges of Graph
  // Get all the nodes with Indegree 0
  // Do a removal of edges on adjacent Nodes
  int V = 7;
  vector<vector<int>> adj = {
      {1, 2}, // 0
      {2, 3}, // 1
      {5},    // 2
      {0},    // 3
      {5},    // 4
      {},     // 5
      {}      // 6
  };

  vector<int> safeNodes = evaluateSafeNodes(V, adj);

  cout << "Safe Nodes: ";
  for (auto node : safeNodes) {
    cout << node << " ";
  }
  cout << endl;
  return 0;
}