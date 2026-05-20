#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
  // TC O(V*E)
  // SC (V)
  vector<int> dist(V, 1e8);
  dist[S] = 0;
  for (int i = 0; i < V - 1; i++) {
    for (auto it : edges) {
      int u = it[0];
      int v = it[1];
      int wt = it[2];

      if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
        dist[v] = dist[u] + wt;
      }
    }
  }

  // Nth Relaxation to check Negative Cycle
  for (auto it : edges) {
    int u = it[0];
    int v = it[1];
    int wt = it[2];

    if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
      return {-1};
    }
  }

  return dist;
}

int main() {
  cout << "39 G 41 Bellman Ford Algorithm" << endl;
  // It is also used for Finding out Shortest Path
  // As we studied Dijkstra failed when it had negative edges so Bellman Ford
  // Algorithm that helps us to detect Negative Cycles
  // NOTE Bellman Ford Algorithm only works for DIRECTED GRAPH
  // if we need it to work on undirected we need to convert it into Directed one
  // by updated Undirected To Directed

  // SO Step 1 will be Relaxing all the Edges N-1 times sequentially
  // Relax means if(dist[u] + wt < dist[v]) {
  // dist[v] = dist[u] + wt ;
  // }

  // Why N - 1 iterations?

  // In a graph with N nodes,
  // the shortest path can contain at most N - 1 edges.
  // So relaxing all edges N - 1 times guarantees
  // the shortest distances.

  // Detecting Negative Cycle:

  // Perform one extra iteration (Nth iteration).
  // If any distance still gets reduced,
  // then a Negative Weight Cycle exists.

  // QUESTION
  //   Given an weighted graph with V vertices numbered from 0 to V-1 and E
  //   edges, represented by a 2d array edges[][], where edges[i] = [u, v, w]
  //   represents a direct edge from node u to v having w edge weight. You are
  //   also given a source vertex src.

  // Your task is to compute the shortest distances from the source to all other
  // vertices. If a vertex is unreachable from the source, its distance should
  // be marked as 108. Additionally, if the graph contains a negative weight
  // cycle, return [-1] to indicate that shortest paths cannot be reliably
  // computed.

  int V = 6;

  vector<vector<int>> edges = {{3, 2, 6},  {5, 3, 1},  {0, 1, 5}, {1, 5, -3},
                               {1, 2, -2}, {3, 4, -2}, {2, 4, 3}};

  int src = 0;

  vector<int> ans = bellman_ford(V, edges, src);

  if (ans.size() == 1 && ans[0] == -1) {

    cout << "Negative Weight Cycle Detected" << endl;
  } else {

    cout << "Shortest Distance Array:" << endl;

    for (int i = 0; i < V; i++) {
      cout << ans[i] << " ";
    }
  }

  return 0;
}
