#include <bits/stdc++.h>
using namespace std;

//  N is Number of nodes
//  M is Number of Edges
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges, int src) {
  // TC O(V+2E)
  // SC O(V+2E)

  vector<vector<int>> adj(N);
  for (int i = 0; i < M; i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> dist(N, INT_MAX);
  dist[src] = 0;
  queue<int> q;
  q.push(src);

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (auto adjNode : adj[node]) {
      if (dist[node] != INT_MAX && dist[node] + 1 < dist[adjNode]) {
        dist[adjNode] = dist[node] + 1;
        q.push(adjNode);
      }
    }
  }
  vector<int> ans(N, -1);
  for (int i = 0; i < N; i++) {
    if (dist[i] != INT_MAX) {
      ans[i] = dist[i];
    }
  }

  return ans;
}

int main() {
  cout << "25 G 28 Shortest Path in Undirected Graph with Unit Weights" << endl;
  // You are given an Undirected Graph having unit weight of the edges, find the
  // shortest path from src to all the vertex and if it is unreachable to reach
  // any vertex, then return -1 for that vertex.

  // Refer 25_G_28_Shortest_Path_in_Undirected_Graph_with_Unit_Weights_1

  // adjList
  // 0 -> {1,3}
  // 1 -> {0,2,3}
  // 2 -> {1,6}
  // 3 -> {0,4}
  // 4 -> {3,5}
  // 5 -> {4,6}
  // 6 -> {2,5,7,8}
  // 7 -> {6,8}
  // 8 -> {6,7}

  int N = 9;
  int M = 10;

  vector<vector<int>> edges = {
      {0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 6},
      {3, 4}, {4, 5}, {5, 6}, {6, 7}, {6, 8},
  };

  int src = 0;

  vector<int> ans = shortestPath(N, M, edges, src);

  cout << "Shortest Distance from Source " << src << ":\n";

  for (int i = 0; i < N; i++) {
    cout << "Node " << i << " -> " << ans[i] << endl;
  }

  return 0;
}