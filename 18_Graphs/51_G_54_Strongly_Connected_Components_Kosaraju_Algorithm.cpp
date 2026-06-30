#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) {
  vis[node] = 1;
  for (auto it : adj[node]) {
    if (!vis[it]) {
      dfs(it, vis, adj, st);
    }
  }

  st.push(node);
}
void dfs3(int node, vector<int> &vis, vector<vector<int>> &adjT) {
  vis[node] = 1;
  for (auto it : adjT[node]) {
    if (!vis[it]) {
      dfs3(it, vis, adjT);
    }
  }
}

int kosaraju(int V, vector<vector<int>> &adj) {
  vector<int> vis(V, 0);
  stack<int> st;

  // Step 1
  // TC O(V+E)
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      dfs(i, vis, adj, st);
    }
  }

  // Step 2
  // TC O(V+E)
  vector<vector<int>> adjTransposed(V);
  for (int i = 0; i < V; i++) {
    vis[i] = 0; // Unmarking here so we can use in Step3
    for (auto it : adj[i]) {
      // So it means for i there is an edge to i -> it
      // we need to reverse it
      adjTransposed[it].push_back(i);
    }
  }

  // Step 3
  // TC O(V+E)
  int scc = 0;
  while (!st.empty()) {
    int node = st.top();
    st.pop();
    if (!vis[node]) {
      scc++;
      dfs3(node, vis, adjTransposed);
    }
  }

  return scc;
}

int main() {

  cout << "51 G 54 Strongly Connected Components Kosaraju Algorithm" << endl;
  // Strongly Connected Components are only valid for Directed Graphs
  // A Strongly Connected Component (SCC) is a maximal subgraph within a
  // directed graph where every vertex can reach every other vertex
  // Refer 51_G_54_Strongly_Connected_Components_Kosaraju_Algorithm_1

  // Step1: Sort all the edges acc to the finishing time (Perform a DFS and
  // store in a vector or stack)

  // Step2: Reverse the Graph (Original Graph Directed Directions needs to be
  // reversed)

  // Step3: Do a DFS on reversed Graph

  int V = 5;
  vector<vector<int>> adj(V);

  adj[0].push_back(2);
  adj[2].push_back(1);
  adj[1].push_back(0);

  adj[0].push_back(3);
  adj[3].push_back(4);

  cout << "Number of SCCs: " << kosaraju(V, adj) << endl;
  return 0;
}