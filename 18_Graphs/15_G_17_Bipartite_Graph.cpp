#include <bits/stdc++.h>
using namespace std;

bool isCheck(int start, vector<vector<int>> &adj, vector<int> &color) {
  queue<int> q;
  q.push(start);

  color[start] = 0; // colour intial node t 0
  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (auto adjNode : adj[node]) {
      // if adjNode is not yet coloured
      // color it with opposite
      if (color[adjNode] == -1) {
        color[adjNode] = !color[node]; // 0 becomes 1 and 1 becomes 0
        q.push(adjNode);
      } else if (color[adjNode] == color[node]) {
        // Is AdjNode color same to Node
        return false;
      }
    }
  }

  return true;
}
bool isBipartite(int V, vector<vector<int>> &adj) {
  vector<int> color(V, -1);

  for (int i = 0; i < V; i++) {
    if (color[i] == -1) {
      if (isCheck(i, adj, color) == false) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cout << "15 G 17 Bipartite Graph" << endl;
  // Bipartite Graph means we can colour the graph with 2 colours such that no
  // adjacent nodes have same colour

  // Linear Graphs that dont have any cycle are always Bipartite Graph
  // Any Graph with Even Cycle Length can also be Bipartite

  // Simple Brute Force
  // We will go node by node in visited we will mark the colours as 0 and 1 and
  // if we get two nodes that have same colour we will return false else true

  int V = 4;
  vector<vector<int>> adj(V);

  // Example: Not Bipartite (odd cycle)
  adj[0].push_back(1);
  adj[1].push_back(0);

  adj[1].push_back(2);
  adj[2].push_back(1);

  adj[2].push_back(0);
  adj[0].push_back(2);

  if (isBipartite(V, adj)) {
    cout << "Graph is Bipartite\n";
  } else {
    cout << "Graph is NOT Bipartite\n";
  }
}