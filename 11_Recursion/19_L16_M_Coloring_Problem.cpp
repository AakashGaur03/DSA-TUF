#include <bits/stdc++.h>
using namespace std;
// TC O(N^M)
// SC O(N) for colring and O(N) auxiliary space

bool isSafe(int node, vector<int> &color, vector<vector<int>> &graph, int N,
            int col) {
  for (int k = 0; k < N; k++) {
    // If there is an edge and adjacent node has same color → not safe
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}

bool solve(int node, vector<int> &color, int m, int N,
           vector<vector<int>> &graph) {
  if (node == N)
    return true;

  for (int col = 1; col <= m; col++) {
    if (isSafe(node, color, graph, N, col)) {
      color[node] = col;
      if (solve(node + 1, color, m, N, graph))
        return true;

      color[node] = 0; // backtrack
    }
  }
  return false;
}
int main() {
  cout << "19 L16 M Coloring Problem" << endl;

  int N = 4; // number of nodes
  int m = 3; // number of colors

  // Example graph (should be adjacency matrix)
  vector<vector<int>> graph = {
      {0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};

  vector<int> color(N, 0);

  if (solve(0, color, m, N, graph)) {
    cout << "Graph colored successfully:\n";
    for (int i = 0; i < N; i++) {
      cout << "Node " << i << " -> Color " << color[i] << endl;
    }
  } else {
    cout << "No valid coloring possible with " << m << " colors.\n";
  }

  return 0;
}