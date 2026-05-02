#include <bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &st, vector<vector<int>> &adj, vector<int> &vis) {
  vis[node] = 1;
  for (auto adjNode : adj[node]) {
    if (!vis[adjNode]) {
      dfs(adjNode, st, adj, vis);
    }
  }
  st.push(node);
}

vector<int> topoSort(int V, vector<vector<int>> &adj) {
  // TC O( V + E )
  // SC O( 2N )
  vector<int> vis(V, 0);
  stack<int> st;
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      dfs(i, st, adj, vis);
    }
  }

  vector<int> ans;
  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }
  return ans;
}

int main() {
  cout << "18 G 21 Topological Sort Algorithm DFS" << endl;
  // Topological Sort only works on DAG means Directed Acyclic Graph
  // Directed + Graph that dont have any cycles

  // Topological Sort means any Linear ordering of vertices such that if there
  // is an edge between u & v, u appears before v in ordering

  // 0->{}
  // 5->0
  // 4->0
  // 5->2
  // 2->3
  // 3->1
  // 4->1

  // So Adj will be
  // 0 -> {}
  // 1 -> {}
  // 2 -> {3}
  // 3 -> {1}
  // 4 -> {0,1}
  // 5 -> {0,2}

  // so
  // 5 4 2 3 1 0
  // 4 5 2 3 1 0

  // These both are valid Linear Ordering as u->v
  // u appears before v
  // There can be multiple valid orderings

  // So Lets now understand why it works only in DAG (Directed Acyclic Graph)
  // So if a graph is Directed then u -> v and v -> u so it fails u appears
  // before v condition
  // Same as for cycle too it fails u appears before v condition

  // So to get topo Sort it is just storing the node while backtracting in the
  // DFS

  int V = 6;
  vector<vector<int>> adj(V);

  // Building the graph
  adj[2].push_back(3);
  adj[3].push_back(1);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[5].push_back(0);
  adj[5].push_back(2);

  vector<int> result = topoSort(V, adj);

  cout << "Topological Order: ";
  for (auto x : result) {
    cout << x << " ";
  }
  return 0;
}