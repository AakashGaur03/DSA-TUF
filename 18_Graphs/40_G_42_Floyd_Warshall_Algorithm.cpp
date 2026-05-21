#include <bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>> &matrix) {
  // TC O(N^3)
  // SC O(N^2)
  int n = matrix.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == -1) {
        matrix[i][j] = 1e8;
      }
      if (i == j) {
        // Self Distance is 0
        matrix[i][j] = 0;
      }
    }
  }

  for (int via = 0; via < n; via++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][via] != 1e8 && matrix[via][j] != 1e8) {
          matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
        }
      }
    }
  }

  // If need to check for Negative Cycle
  for (int i = 0; i < n; i++) {
    if (matrix[i][i] < 0) {
      // we can do whatever wanted
    }
  }

  // To Return Properly
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 1e8) {
        matrix[i][j] = -1;
      }
    }
  }
}

int main() {
  cout << "40 G 42 Floyd Warshall Algorithm" << endl;
  // This Algo also helps to find out the shortest path
  // It is different from Dijkstra and Bellman Ford as they are
  // Single Source Shortest Path Algo

  // In here there are multiple Source Nodes also know as
  // Multi Source Shortest Path Algo and it also helps detect negative cycles as
  // well

  // It states
  // Go Via Every Node/Vertex (means take all possible path from each node to
  // every other node and store minimum)
  // In here as we need to kinda pre compute the edges to we will use Adj matrix

  //   Why matrix is preferred:

  // We need direct access to every pair (i,j)
  // Floyd Warshall uses 3 nested loops
  // Updating paths becomes very easy with matrix indexing
  // Time complexity is already O(V
  // 3
  // ), so using matrix is natural

  // Adjacency List is better for:

  // sparse graphs
  // single source algorithms like Dijkstra's algorithm or Bellman–Ford
  // algorithm

  // Adjacency Matrix is better for:

  // all-pairs shortest path
  // dense graphs
  // Floyd Warshall

  // Initialze Matrix with infinity
  // In Matrix all node will have cost to reach themselves as 0
  // Refer 40_G_42_Floyd_Warshall_Algorithm_1
  // Mark all Nodes acc to Edges in Matrix
  // Refer 40_G_42_Floyd_Warshall_Algorithm_2

  // After this we have to traverse in Matrix via each nodes calculation minimum
  // of
  // dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j])

  // After allowing all N nodes as intermediate(via) nodes
  // we get the shortest distance between every pair of nodes

  // How to detect Negative Cycle
  // If any cost of the Node to itself is less than 0 then there is a Negative
  // Cycle

  //   Given a matrix dist[][] of size n x n, where dist[i][j] represents the
  //   weight of the edge from node i to node j.

  // If there is no direct edge, dist[i][j] is set to INF (a large value i.e.,
  // 108). The diagonal entries dist[i][i] are 0, since the distance from a node
  // to itself is zero. The graph may contain negative edge weights, but it does
  // not contain any negative weight cycles.
  // Do it in Place

  // HERE Dijkstra can also work if not dealing with Negative cycle
  // If we know all there are no negative Cycles we can apply Dijkstra on each
  // node and can get result and it will take TC O(N*E log V) that is better
  // than N^3 but it wont work if Negative Cycle

  vector<vector<int>> matrix = {
      {0, 2, -1, -1}, {1, 0, 3, -1}, {-1, -1, 0, 4}, {3, 5, -1, 0}};

  shortest_distance(matrix);

  cout << "Shortest Distance Matrix:\n";

  for (auto row : matrix) {
    for (auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}