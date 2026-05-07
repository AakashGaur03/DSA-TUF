#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis,
              stack<int> &st) {
  vis[node] = 1;

  for (auto adjNode : adj[node]) {
    int v = adjNode.first;
    if (!vis[v]) {
      topoSort(v, adj, vis, st);
    }
  }

  st.push(node);
}

//  N is Number of nodes
//  M is Number of Edges
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
  // TC O(2N + 2M)
  vector<vector<pair<int, int>>> adj(N);

  for (int i = 0; i < M; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int wt = edges[i][2];

    adj[u].push_back({v, wt});
  }

  // Find Topo Sort
  // O(N + M)

  vector<int> vis(N, 0);
  stack<int> st;

  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      topoSort(i, adj, vis, st);
    }
  }

  // Relax the Edges (Distance Thing)
  vector<int> dist(N, INT_MAX); // Mark with Infinity
  dist[0] = 0;                  // Source Node Distance is 0
                                // TC O(N + M)
  while (!st.empty()) {
    int node = st.top();
    st.pop();

    for (auto adjNode : adj[node]) {
      int v = adjNode.first;
      int wt = adjNode.second;

      if (dist[node] != INT_MAX && dist[node] + wt < dist[v]) {
        dist[v] = dist[node] + wt;
      }
    }
  }

  return dist;
}

int main() {
  cout << "24 G 27 Shortest Path in Directed Acyclic Graph Topological Sort"
       << endl;
  // Find the shortest path from src(0) to all the vertex.
  // So in this question we will introduce to edge weigths
  // So we need shortest path acc to weigths

  // So we have to find shortest distance from 0 to each node
  // So 0 -> 0 will be 0,
  // then we will find 0 -> 1 say x,
  // then 0 -> 2 say y,
  // and till 0 -> n-1 say z.

  // adjList
  // 0 -> {1,2}
  // 1 -> {3,1}
  // 2 -> {1,3}
  // 3 ->
  // 4 -> {0,3}{2,1}
  // 5 -> {4,1}
  // 6 -> {4,2}{5,3}

  // Refer 24_G_27_Shortest_Path_in_Directed_Acyclic_Graph_Topological_Sort_1

  //  6 -> {4,2}{5,3}
  // This means from 6 to 4 there is a node that has weight 2 and 6 to 5 which
  // have weight 5

  // Step 1 Will be Simply get the Topo Sort

  // Step 2 Take the nodes out of Stack and relax the edges
  // relax the edges : Take Distance Array marked with Infinty
  // Make Source Node distance to be 0
  // then mark all its connected and update the distance array repeeat it for
  // all and we will have our Distance Array

  // STACK OVERFLOW
  //   Finding the shortest path to a vertex is easy if you already know the
  //   shortest paths to all the vertices that can precede it. Finding the
  //   longest path to a vertex in DAG is easy if you already know the longest
  //   path to all the vertices that can precede it.

  // Processing the vertices in topological order ensures that by the time you
  // get to a vertex, you've already processed all the vertices that can precede
  // it.

  // Dijkstra's algorithm is necessary for graphs that can contain cycles,
  // because they can't be topologically sorted.

  int N = 6;
  int M = 7;

  vector<vector<int>> edges = {

      {0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2},
      {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};

  vector<int> ans = shortestPath(N, M, edges);

  cout << "Shortest Distance from Source Node 0:\n";

  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }

  cout << endl;
  return 0;
}